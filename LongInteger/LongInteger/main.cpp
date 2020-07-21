#include <iostream>
#include "BigNumber.h"
#include "CaculateInterface.h"

#include "AddOperate.h"
#include "SubOperate.h"
#include "MultiplyOperate.h"
#include "DivideOperate.h"

#include "Caculator.h"

#define SIZE 50

using namespace std;


//int One[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

void Add(BigNumber* data);
void Subtract(BigNumber* data);

//int TestResult[SIZE] = { 0 };
bool AbsCompare(BigNumber* data) {

	int borrow = 0;//�ɦ�
	int TestResult[SIZE] = { 0 };
	for (int i = SIZE - 1; i >= 0; i--)
	{
		TestResult[i] = data->Integer1[i] - data->Integer2[i] - borrow;//�����k

		if (TestResult[i] >= 0) borrow = 0;//��X�ӵ��G�O�����A�����Ǧ�
		else {
			
			TestResult[i] = TestResult[i] + 10;
			borrow = 1;
		}
	}
	
	//A�O�_��B�j
	if (TestResult[0] == 9)
	{//�_ A��B�p
//		cout << "����Ȥ�� A��B�p" << endl;
		//for (int i = SIZE - 1; i >= 0; i--) TestResult[i] = 0;
		return false;
	}
	else
	{//�O A��B�j
//		cout << "����Ȥ�� A >= B" << endl;
		//for (int i = SIZE - 1; i >= 0; i--) TestResult[i] = 0;
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

void PrintBeforeOperate(BigNumber* data) {

	cout << "��J��1 : " << endl;
	int flag = 0;
	if (data->isPositiveInt_1 == false) cout << "-";
	for (int i = 0; i < SIZE; i++) {

		//��flag�B�z�e���h�l��0
		if (data->Integer1[i] != 0)
		{
			flag = 1;
		} 

		if (flag == 1)
		{ 
			cout << data->Integer1[i];
		}
	}
	cout << endl;

	cout << "��J��2 : " << endl;
	if (data->isPositiveInt_2 == false) cout << "-";
	flag = 0;
	for (int i = 0; i < SIZE; i++) {

		//��flag�B�z�e���h�l��0
		if (data->Integer2[i] != 0)
		{
			flag = 1;
		}

		if (flag == 1)
		{
			cout << data->Integer2[i];
		}
	}
	cout << endl;
}

int main() {

	BigNumber* Data = new BigNumber;

	PrintBeforeOperate(Data);
	
	cout << endl;

	
	AddOperate* addFunction = new AddOperate();//�[���\�� ��new��
	SubOperate* subFunction = new SubOperate();
	MultiplyOperate* multiplyFunction = new MultiplyOperate();
	DivideOperate* divideFunction = new DivideOperate();

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

	cout << endl;

	BigNumber* Data2 = new BigNumber;
	//��k
	caculator->SetOperator(subFunction);
	caculator->SetOperatorInt(Data2);
	caculator->Execute();
	caculator->Show();
	
	cout << endl;

	//�������k
	BigNumber* Data3 = new BigNumber;
	caculator->SetOperator(multiplyFunction);
	caculator->SetOperatorInt(Data3);
	caculator->Execute();
	caculator->Show();

	cout << endl;

	//�������k
	BigNumber* Data4 = new BigNumber;
	caculator->SetOperator(divideFunction);
	caculator->SetOperatorInt(Data4);
	caculator->Execute();
	caculator->Show();

	cout << endl;

	system("pause");

}