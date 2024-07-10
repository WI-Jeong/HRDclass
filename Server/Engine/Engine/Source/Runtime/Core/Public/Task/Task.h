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
};

class CORE_API FTaskManager
{
public:
	static FTaskManager* Get(const bool bDestroy = false);

	template<typename TTask, typename... Types>
	void InvokeTask(Types... InArgs)
	{
		static_assert(is_base_of_v<FTask, TTask>);
		TTask NewTask = TTask(InArgs...);
		NewTask.ExecuteTask();
	}

protected:

};

template<typename TTask, typename... Types>
void InvokeTask(Types... InArgs)
{
	FTaskManager::Get()->InvokeTask<TTask>(InArgs...);
}