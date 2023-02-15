/**
 * @brief
 *  アプリケーション内の汎用的な時間計測用の機能を提供する
 *  処理を実行している時間のみを計測する、アプリケーション内での経過時刻をスピード係数で
 *  調整可能な機能を提供する
 */
#pragma once
#include <iostream>
#include <vector>
#include "ScheduleTask.hpp"

namespace nl
{

  class TimeWatch
  {
  private:
    /// @brief スケジュールタスクの一覧
    std::vector<ScheduleTask> tasklist;

    /// @brief アプリケーション時間に反映させるスピード（0.5f なら 0.5倍の速度として計算）
    float appSpeed;

    /// @brief 計測した時間の合計
    long timeFromStartMs;

  public:
    /// @brief コンストラクタ
    TimeWatch();

    /// @brief 計測開始
    void start();

    void stop();

    /// @brief
    ///  完了済みのタスクを削除する。
    ///  全体の進捗計測対象から除外され、過去の完了済みタスクは参照不可となる
    void removeCompletedTasks();
    void removeWholeTasks();

    void setAppSpeed(const float speed);

    void addRealTime(const long deltaTimeMs);

    /// @brief タスクを追加する。スケジュールタスクコードは 0 以上である検査をする
    /// @param task 計測のため末尾に追加するタスク
    void pushTask(const ScheduleTask task);

    void checkTaskCompleted(const int taskcode);

    /// @brief 現在計測中のタスクのタスクコードを返す。計測中のタスクがない場合、 -1 を返す
    /// @return 計測中のタスクコード。ないなら -1 を返す
    int getNowProgressingTaskcode();

    /// @brief 現在処理中タスクの進捗を計算して返す
    /// @return 0.0～1.0f で進捗率を返す
    float getTaskProgress();

    /// @brief 全体タスクから実施完了したぶんの進捗を計算して返す
    /// @return 0.0～1.0f で進捗率を返す
    float getWholeTasksProgress();

    /// @brief 計測を開始（Start）してからの累積時間をミリ秒で返す
    /// @return 累積時間（ms）
    long getTimeFromStartMs();

    /// @brief 現在の時刻を UnitTime 形式で MS 単位で返す
    /// @return 現在時刻(ms)
    static long getNowMs();

    /// @brief 現在の時刻を ISO8601 形式（YYYYMMDDThh:mm:ss.sss+09:00 形式で返す）
    /// @return 時刻を ISO8601 形式の文字列
    static std::string getNowMsAsStrIso8601();

    /// @brief 現在の時刻を hh:mm:ss.SSS 形式の文字列で返す
    /// @return 現在時刻（hh:mm:ss.SSS）の文字列
    static std::string getNowMsAsStr_hhmmssSSS();
  };
};
