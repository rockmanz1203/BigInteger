#include <iostream>
#include "BigNumber.h"
#include "CaculateInterface.h"
#include "AddOperate.h"
#include "SubOperate.h"
#include "Caculator.h"

#define SIZE 50

using namespace std;


int One[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

bool AbsCompare(BigNumber* data) {
	int borrow = 0;//�ɦ�
	for (int i = SIZE - 1; i >= 0; i--)
	{
		data->Result[i] = data->Integer1[i] - data->Integer2[i] - borrow;//�����k

		if (data->Result[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
		else {
			borrow = 1;
			data->Result[i] = data->Result[i] + 10;
		}
	}
	//A�O�_��B�j
	if (data->Result[0] == 9) 
	{//�_ A��B�p
		cout << "����Ȥ�� A��B�p" << endl;
		return false;
	}
	else
	{//�O A��B�j
		cout << "����Ȥ�� A��B�j" << endl;
		return true;
	}
}


void Add(BigNumber* data) {
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == true) 
	{	//Test��OK
		//7+5
		//�p�G��̬���
		int Carry = 0;//�i��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//�i��
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
	}
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == false) 
	{	//Test��OK
		//7+-5
		data->isPositiveInt_2 = true;
		Subtract(data);//7-5
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == true) 
	{
			int borrow = 0;//�ɦ�
			for (int i = SIZE - 1; i >= 0; i--)
			{
				data->Result[i] = data->Integer2[i] - data->Integer1[i] - borrow;//�����k

				if (data->Result[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
				else {
					borrow = 1;
					data->Result[i] = data->Result[i] + 10;
				}
			}
			if (data->Result[0] == 9)
			{
				data->isPositibeResult = false;//�]���t��

				//�B�z�ƭ�
				for (int i = 0; i < SIZE; i++)
				{
					data->Result[i] = 9 - data->Result[i];
				}
				data->Result[SIZE - 1]++;

			}
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == false) {
		int Carry = 0;//�i��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//�i��
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
		data->isPositibeResult = false;
	}
}

void Subtract(BigNumber* data) {
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == true) //��-�� �B�z�i�ର�t��print���p
	{
		//Test��OK
		int borrow = 0;//�ɦ�
		//��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] - data->Integer2[i] - borrow;//�����k

			if (data->Result[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
			else {
				borrow = 1;
				data->Result[i] = data->Result[i] + 10;
			}
		}
		//�B�z���t �p�GA-b�X�Ӭ��t? 5-6
		if (data->Result[0] == 9) 
		{
			data->isPositibeResult = false;//�]���t��

			//�B�z�ƭ�
			for (int i = 0; i < SIZE; i++) 
			{
				data->Result[i] = 9 - data->Result[i];
			}
			data->Result[SIZE-1]++;

		}

	}
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == false) 
	{//5-(-6)
		//Test��OK
		//�ܸ�
		data->isPositiveInt_2 = true;
		Add(data);
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == true) {
		//-4-5
		int Carry = 0;//�i��
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//�i��
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
		data->isPositibeResult = false;
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == false) {
		int borrow = 0;//�ɦ�
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer2[i] - data->Integer1[i] - borrow;//�����k

			if (data->Result[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
			else {
				borrow = 1;
				data->Result[i] = data->Result[i] + 10;
			}
		}
		if (data->Result[0] == 9)
		{
			data->isPositibeResult = false;//�]���t��

			//�B�z�ƭ�
			for (int i = 0; i < SIZE; i++)
			{
				data->Result[i] = 9 - data->Result[i];
			}
			data->Result[SIZE - 1]++;

		}
	}
}



int main() {

	BigNumber* Data = new BigNumber;
	AbsCompare(Data);
	
	AddOperate* addFunction = new AddOperate();//�[���\�� ��new��
	SubOperate* subFunction = new SubOperate();

	/*
	Caculator�ϥΤ�k:
	1.���إ�Caculator����
	2.�t�m�n�ާ@���\��function (+-/*)
	3.�t�m�n��J�ާ@���j��
	4.Execute����
	*/

	//�إ߭p���
	Caculator* caculator = new Caculator();

	//�[�k
	caculator-> SetOperator(addFunction);
	caculator-> SetOperatorInt(Data);
	caculator-> Execute();
	caculator-> Show();
	//caculator-> Show(); //���աA�T�w�M�ŷ|�s��


	BigNumber* Data2 = new BigNumber;
	//��k
	caculator->SetOperator(subFunction);
	caculator->SetOperatorInt(Data2);
	caculator->Execute();
	caculator->Show();
	
	


	system("pause");

}