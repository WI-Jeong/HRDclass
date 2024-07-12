#include "Task/Task.h"

FTaskManager* FTaskManager::Get(const bool bDestroy)
{
    static unique_ptr<FTaskManager> Instance = make_unique<FTaskManager>();
    if (bDestroy)
    {
        Instance.release();
        return nullptr;
    }

    return Instance.get();
}

void FTaskManager::ProcessTasks()
{
    TaskMutex.lock();
    Tasks.insert(Tasks.end(), NewTasks.begin(), NewTasks.end());
    TaskMutex.unlock();

    for (auto It = Tasks.begin(); It != Tasks.end(); ++It)
    {
        It->get()->ExecuteTask();
    }

    erase_if(Tasks, [](shared_ptr<FTask>& InTask) -> bool
        {
            return InTask->IsTaskDone();
        });
}