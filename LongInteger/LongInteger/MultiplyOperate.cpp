#include<iostream>
#include "MultiplyOperate.h"
#define SIZE 50
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

void MultiplyOperate::Execute()
{
	cout << "���k�������榨�\" << endl;
	//Add(data);
	//+5*-4 = -20
	if (data->isPositiveInt_1 != data->isPositiveInt_2) 
	{
		data->isPositibeResult = false;
	}
	else {
		data->isPositibeResult = true;
	}
	int carry = 0;
	int temp = 0;
	int i = 0;
	int j = 0;
	int resultIndex = SIZE - 1;
	
	for (int j = SIZE - 1; j >= 0; j--) {//B��index ����int_2
		carry = 0;
		resultIndex = j;
		for (int i = SIZE - 1; i >= 0; i--) 
		{
			
			//A��index �Q���� int_1
			temp = data->Integer1[i] * data->Integer2[j] + data->Result[resultIndex] + carry;
			//�����D�A�o�˲Ĥ@��|�OA[49]*B[49]=>result[98]
			//���O�S��[98]�o��index�Ŷ� �ҥH�����[i+j]�o�Ӥ�k�Ӧs

			carry = temp / 10;
			data->Result[resultIndex] = temp % 10;
			resultIndex--;
			//cout << temp << endl;
			
		}
		//cout << "�X�j��" << endl;
	}

}
void MultiplyOperate::SetInt(BigNumber* Data)
{
	data = Data;
}