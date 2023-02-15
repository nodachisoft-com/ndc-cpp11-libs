#pragma once

namespace nl
{
  class ScheduleTask
  {
  private:
    /// @brief TimeWatch 内で検索・識別するためのコード
    int taskcode;
    /// @brief タスク処理に必要とする時間（ミリ秒）
    int relTimeMs;

    /// @brief 経過時間を計測
    long progressMs;

  public:
    /// @brief コンストラクタ
    ScheduleTask(const int _taskcode, const int _relTimeMs);

    /// @brief ミリ秒を経過時間として加算する
    /// @param addDeltaTimeMs 追加する経過時間
    void addProgressMs(long addDeltaTimeMs);

    /// @brief タスク処理にかかる処理 ÷ 計測時間を計算して進捗率を返す
    /// @return 進捗を 0.0f ～ 1.0f
    float getTaskProgress();
  };
}
