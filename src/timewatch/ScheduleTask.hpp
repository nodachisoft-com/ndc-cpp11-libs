#pragma once
#include <stdint.h>

namespace nl
{
  class ScheduleTask
  {
  private:
    /// @brief TimeWatch 内で検索・識別するためのコード
    int taskcode;

    /// @brief タスク処理に必要とする時間（ミリ秒）
    int64_t relTimeMs;

    /// @brief 経過時間を計測
    int64_t progressMs;

    /// @brief タスクが完了していれば true が返る
    bool _isCompleted;

  public:
    /// @brief コンストラクタ
    ScheduleTask(const int _taskcode, const int64_t _relTimeMs);

    /// @brief ミリ秒を経過時間として加算する
    /// @param addDeltaTimeMs 追加する経過時間
    /// @return 予定した時間をオーバーした、超過分の ms を返す
    int64_t addProgressMs(int64_t addDeltaTimeMs);

    /// @brief タスク処理にかかる処理 ÷ 計測時間を計算して進捗率を返す
    /// @return 進捗を 0.0f ～ 1.0f
    float getTaskProgress();

    /// @brief タスクコードを返す
    int getTaskcode();

  public: // Accessor Methods
    /// @brief タスク処理に必要とする時間（ミリ秒）を返す
    int64_t getRelTimeMs();

    int64_t getProgressMs();

    /// @brief タスクが完了していれば true が返る
    bool isCompleted();
  };
}
