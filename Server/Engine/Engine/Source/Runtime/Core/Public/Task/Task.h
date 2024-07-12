#pragma once
#include "CoreTypes.h"

namespace ENamedThreads
{
	enum Type : int32
	{
		MainThread,
		AnyThead,
	};
}

struct CORE_API FTask
{
	virtual ~FTask() {}
	virtual void ExecuteTask() {}

	virtual void FinishTask() { bTaskDone = true; }
	bool IsTaskDone() const { return bTaskDone; }

private:
	bool bTaskDone = false;
};

class CORE_API FTaskManager
{
	friend class FEngineLoop;
public:
	static FTaskManager* Get(const bool bDestroy = false);

	// 호출 즉시 실행되는 Task
	// 1회 실행 이후 반복 실행되지 않는다.
	template<typename TTask, typename... Types>
	void InvokeTask(Types... InArgs)
	{
		static_assert(is_base_of_v<FTask, TTask>);
		TTask NewTask = TTask(InArgs...);
		NewTask.ExecuteTask();
		NewTask.FinishTask();
	}

	template<typename TTask, typename... Types>
	void AddTask(Types... InArgs)
	{
		static_assert(is_base_of_v<FTask, TTask>);

		shared_ptr<TTask> NewTask = make_shared<TTask>(InArgs...);
		lock_guard<mutex> LockGuard(TaskMutex);
		NewTasks.push_back(NewTask);
	}

protected:
	void ProcessTasks();

protected:
	mutex TaskMutex;
	vector<shared_ptr<FTask>> NewTasks;
	vector<shared_ptr<FTask>> Tasks;
};

template<typename TTask, typename... Types>
void InvokeTask(Types... InArgs)
{
	FTaskManager::Get()->InvokeTask<TTask>(InArgs...);
}

template<typename TTask, typename... Types>
void AsyncTask(ENamedThreads::Type Thread, Types... InArgs)
{
	if (Thread == ENamedThreads::MainThread)
	{
		FTaskManager* TaskManager = FTaskManager::Get();
		TaskManager->AddTask<TTask>(InArgs...);
	}
	else
	{
		// Not impl yet...
		_ASSERT(false);
	}
}

template<BOOST_ASIO_COMPLETION_TOKEN_FOR(void()) NullaryToken>
void AsyncTask(boost::asio::thread_pool& ThreadPool, NullaryToken&& InFunction)
{
	return boost::asio::post(ThreadPool, InFunction);
}

