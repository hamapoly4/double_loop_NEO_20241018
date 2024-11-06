/******************************************************************************
 *  ファイル名：ScenarioTracer.cpp
 *　　　　内容：シナリオトレーサクラスの定義
 *  　　作成日：2024/10/24
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "ScenarioTracer.h"     // シナリオトレーサクラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：ダブルループNEO攻略用シナリオ
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
ScenarioTracer::ScenarioTracer(Scenario* conqdoublescenario)
    : mConqDoubleScenario(conqdoublescenario), state(START)
{
    ;
}

/******************************************************
 *  関数名：conquer
 *    概要：攻略する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ScenarioTracer::conquer()
{
    switch (state)
    {
        case START:
            transState(CONQUEST);

        case CONQUEST:
            run();
            break;
        default:
            break;
    }
}

/******************************************************
 *  関数名：run
 *    概要：攻略のための走行をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ScenarioTracer::run()
{
    mConqDoubleScenario->conquer();

    if (mConqDoubleScenario->checkState() == Scenario::FINISH)
    {
        transState(FINISH);
    }
}

/******************************************************
 *  関数名：transState
 *    概要：状態を遷移する
 *  　引数：状態
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ScenarioTracer::transState(eState s)
{
    state = s;
}

/******************************************************
 *  関数名：checkState
 *    概要：状態を確認する
 *  　引数：なし
 *  返却値：状態
 *  　備考：constメンバ関数
 ******************************************************/
ScenarioTracer::eState ScenarioTracer::checkState() const
{
    return state;
}
