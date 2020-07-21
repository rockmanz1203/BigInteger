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
	
	int flag = 0;
	if (CaculateData->isPositibeResult == false) cout << "-";


	//處理前面多餘的0
	for (int i = 0; i < SIZE; i++) {

		//用flag處理前面多餘的0
		if (CaculateData->Result[i] != 0) flag = 1;

		if(flag==1) cout << CaculateData->Result[i];
		
		
		CaculateData->Result[i] = 0;//計算完畢 清空
	}
	cout << endl;
}