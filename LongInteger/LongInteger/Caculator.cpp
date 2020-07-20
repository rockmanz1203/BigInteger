#include <iostream>
#include "Caculator.h"

using namespace std;

void Caculator::Execute()
{
	CaculateOperator->Execute();
}
//抽換功能
void Caculator::SetOperator(CaculateInterface* CaculateFunction) {
	CaculateOperator = CaculateFunction;
	//CaculateFunction->Caculator = this;//用於未來可以抽換計算功能
}
void Caculator::SetOperatorInt(BigNumber* Data)
{
	CaculateOperator->SetInt(Data);
	CaculateData = Data;
}
void Caculator::Show() {

	if (CaculateData->isPositibeResult == false) cout << "-";

	for (int i = 0; i < SIZE; i++) {
		cout << CaculateData->Result[i];
		CaculateData->Result[i] = 0;//計算完畢 清空
	}
	cout << endl;
}