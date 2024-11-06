/******************************************************************************
 *  ファイル名：StraRun.h
 *　　　　内容：直進走行クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "StraRun.h"    // 直進走行クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：直進走行用PD制御、走行速度
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
StraRun::StraRun(Control* conforrun, eSpeed speed)
    : Run(conforrun, speed)
{
    ;
}

/******************************************************
 *  関数名：run
 *    概要：直進走行をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void StraRun::run()
{
    turn = mConForRun->getTurn();

    mLeftMotorForRun.setPWM(pwm - turn);
    mRightMotorForRun.setPWM(pwm + turn);
}
