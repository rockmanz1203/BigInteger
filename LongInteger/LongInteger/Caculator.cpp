#include <iostream>
#include "Caculator.h"

using namespace std;

void Caculator::Execute()
{
	CaculateOperator->Execute();
}
//�⴫�\��
void Caculator::SetOperator(CaculateInterface* CaculateFunction) {
	CaculateOperator = CaculateFunction;
	//CaculateFunction->Caculator = this;//�Ω󥼨ӥi�H�⴫�p��\��
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
		CaculateData->Result[i] = 0;//�p�⧹�� �M��
	}
	cout << endl;
}