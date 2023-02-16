#include "TimeWatch.hpp"

using namespace nl;

TimeWatch::TimeWatch() : tasklist({}), appSpeed(1.0f), timeFromStartMs(0L), stopFlag(true)
{
}

void TimeWatch::start()
{
}

void TimeWatch::stop() {}

void TimeWatch::removeCompletedTasks()
{
}

void TimeWatch::removeWholeTasks()
{
}

void TimeWatch::setAppSpeed(const float speed)
{
}

void TimeWatch::addRealTime(const int64_t deltaTimeMs)
{
}
void TimeWatch::pushTask(const ScheduleTask task)
{
}
void TimeWatch::checkTaskCompleted(const int taskcode)
{
}

int TimeWatch::getNowProgressingTaskcode()
{
  return 0;
}
float TimeWatch::getTaskProgress()
{
  return 0.0f;
}
float TimeWatch::getWholeTasksProgress()
{
  return 0.0f;
}
int64_t TimeWatch::getTimeFromStartMs()
{
  return timeFromStartMs;
}

int64_t TimeWatch::getNowMs()
{
  time_t now = time(nullptr);
  time_t mnow = now * 1000;
  return (int64_t)mnow;
}

std::string TimeWatch::getNowMsAsStrIso8601()
{
  auto t3 = time(nullptr);
  auto tmv3 = tm();
  auto error3 = localtime_s(&tmv3, &t3);
  char buf[256] = {0};
  strftime(buf, 256, "%Y/%m/%d %H:%M:%S%z\n", &tmv3);
  return std::string(buf);
}

std::string TimeWatch::getNowMsAsStr_hhmmssSSS()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::tm *now_tm = std::localtime(&now_c);

  std::ostringstream oss;
  oss << std::put_time(now_tm, "%H:%M:%S.") << std::setfill('0') << std::setw(3) << (now.time_since_epoch() % std::chrono::seconds(1)) / std::chrono::milliseconds(1);

  return oss.str();
}
