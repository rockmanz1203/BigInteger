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
	
	int flag = 0;
	if (CaculateData->isPositibeResult == false) cout << "-";


	//�B�z�e���h�l��0
	for (int i = 0; i < SIZE; i++) {

		//��flag�B�z�e���h�l��0
		if (CaculateData->Result[i] != 0) flag = 1;

		if(flag==1) cout << CaculateData->Result[i];
		
		
		CaculateData->Result[i] = 0;//�p�⧹�� �M��
	}
	cout << endl;
}