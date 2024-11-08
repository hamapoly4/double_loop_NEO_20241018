/******************************************************************************
 *  ファイル名：RunDistMeasure.cpp
 *　　　　内容：走行距離計測クラスの定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "RunDistMeasure.h"     // 走行距離計測クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：回転角取得
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
RunDistMeasure::RunDistMeasure(const MotorManage* getcount)
    : mGetCount(getcount)
{
    ;
}

/******************************************************
 *  関数名：measureRunDist
 *    概要：走行距離を計測する
 *  　引数：なし
 *  返却値：現在の走行距離
 *  　備考：なし
 ******************************************************/
float RunDistMeasure::measureRunDist()
{
    mGetCount->readCount(Count);
    FindRunDist();
    return run_dist;
}

/******************************************************
 *  関数名：FindRunDist
 *    概要：走行距離を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void RunDistMeasure::FindRunDist()
{
    run_dist = static_cast<float>(Count.left + Count.right) * RUNDIST_ECDR_CNT / 2.0;
}
