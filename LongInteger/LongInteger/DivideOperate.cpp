#include<iostream>
#include "DivideOperate.h"
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);

bool AbsCompare(BigNumber* data);

int One[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

void DivideOperate::Execute()
{
	cout << "���k�������榨�\" << endl;

	//�B�z���k���t��
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

	//�p�G�i�H��
	while (AbsCompare(data) == true) 
	{	
		int borrow = 0;//�ɦ�
		//��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Integer1[i] = data->Integer1[i] - data->Integer2[i] - borrow;//�����k

			if (data->Integer1[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
			else {
				borrow = 1;
				data->Integer1[i] = data->Integer1[i] + 10;
			}
		}

		int Carry = 0;//�i��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Result[i] + One[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//�i��
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