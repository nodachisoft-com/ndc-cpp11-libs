#include "ScheduleTask.hpp"

using namespace nl;

/// @brief コンストラクタで初期化を行う
ScheduleTask::ScheduleTask(const int _taskcode, const int _relTimeMs) : taskcode(_taskcode), relTimeMs(_relTimeMs), progressMs(0L)
{
}

void ScheduleTask::addProgressMs(long addDeltaTimeMs)
{
  progressMs += addDeltaTimeMs;
}

float ScheduleTask::getTaskProgress()
{
  return progressMs / (float)relTimeMs;
}
