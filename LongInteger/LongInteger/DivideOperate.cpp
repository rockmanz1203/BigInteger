#include<iostream>
#include "DivideOperate.h"
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);

bool AbsCompare(BigNumber* data);

int One[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

void DivideOperate::Execute()
{
	cout << "除法策略執行成功" << endl;

	//處理除法正負號
	if (data->isPositiveInt_1 != data->isPositiveInt_2) {
		// 6/-2=-3
		data->isPositibeResult = false;
	}
	else {
		// 6/2 or -6/-2
		data->isPositibeResult = true;
	}


	data->isPositiveInt_1 = true;
	data->isPositiveInt_2 = true;

	//如果可以除
	while (AbsCompare(data) == true) 
	{	
		int borrow = 0;//借位
		//減
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Integer1[i] = data->Integer1[i] - data->Integer2[i] - borrow;//執行減法

			if (data->Integer1[i] >= 0) borrow = 0;//減出來結果是正的，不需藉位
			else {
				borrow = 1;
				data->Integer1[i] = data->Integer1[i] + 10;
			}
		}

		int Carry = 0;//進位
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Result[i] + One[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//進位
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}

	}

}
void DivideOperate::SetInt(BigNumber* Data)
{
	data = Data;
}