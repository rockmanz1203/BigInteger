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

	int borrow = 0;//借位
	int TestResult[SIZE] = { 0 };
	for (int i = SIZE - 1; i >= 0; i--)
	{
		TestResult[i] = data->Integer1[i] - data->Integer2[i] - borrow;//執行減法

		if (TestResult[i] >= 0) borrow = 0;//減出來結果是正的，不需藉位
		else {
			
			TestResult[i] = TestResult[i] + 10;
			borrow = 1;
		}
	}
	
	//A是否比B大
	if (TestResult[0] == 9)
	{//否 A比B小
//		cout << "絕對值比較 A比B小" << endl;
		//for (int i = SIZE - 1; i >= 0; i--) TestResult[i] = 0;
		return false;
	}
	else
	{//是 A比B大
//		cout << "絕對值比較 A >= B" << endl;
		//for (int i = SIZE - 1; i >= 0; i--) TestResult[i] = 0;
		return true;
	}
}


void Add(BigNumber* data) {
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == true) 
	{	//Test後OK
		//7+5
		//如果兩者為正
		int Carry = 0;//進位
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//進位
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
	}
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == false) 
	{	//Test後OK
		//7+-5
		data->isPositiveInt_2 = true;
		Subtract(data);//7-5
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == true) 
	{
			int borrow = 0;//借位
			for (int i = SIZE - 1; i >= 0; i--)
			{
				data->Result[i] = data->Integer2[i] - data->Integer1[i] - borrow;//執行減法

				if (data->Result[i] >= 0) borrow = 0;//減出來結果是正的，不需藉位
				else {
					borrow = 1;
					data->Result[i] = data->Result[i] + 10;
				}
			}
			if (data->Result[0] == 9)
			{
				data->isPositibeResult = false;//設為負值

				//處理數值
				for (int i = 0; i < SIZE; i++)
				{
					data->Result[i] = 9 - data->Result[i];
				}
				data->Result[SIZE - 1]++;

			}
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == false) {
		int Carry = 0;//進位
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//進位
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
		data->isPositibeResult = false;
	}
}

void Subtract(BigNumber* data) {
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == true) //正-正 處理可能為負的print狀況
	{
		//Test後OK
		int borrow = 0;//借位
		//減
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] - data->Integer2[i] - borrow;//執行減法

			if (data->Result[i] >= 0) borrow = 0;//減出來結果是正的，不需藉位
			else {
				borrow = 1;
				data->Result[i] = data->Result[i] + 10;
			}
		}
		//處理為負 如果A-b出來為負? 5-6
		if (data->Result[0] == 9) 
		{
			data->isPositibeResult = false;//設為負值

			//處理數值
			for (int i = 0; i < SIZE; i++) 
			{
				data->Result[i] = 9 - data->Result[i];
			}
			data->Result[SIZE-1]++;

		}

	}
	if (data->isPositiveInt_1 == true && data->isPositiveInt_2 == false) 
	{//5-(-6)
		//Test後OK
		//變號
		data->isPositiveInt_2 = true;
		Add(data);
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == true) {
		//-4-5
		int Carry = 0;//進位
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer1[i] + data->Integer2[i] + Carry;

			if (data->Result[i] < 10)  Carry = 0;
			else {
				//進位
				data->Result[i] = data->Result[i] - 10;
				Carry = 1;
			}
		}
		data->isPositibeResult = false;
	}
	if (data->isPositiveInt_1 == false && data->isPositiveInt_2 == false) {
		int borrow = 0;//借位
		for (int i = SIZE - 1; i >= 0; i--)
		{
			data->Result[i] = data->Integer2[i] - data->Integer1[i] - borrow;//執行減法

			if (data->Result[i] >= 0) borrow = 0;//減出來結果是正的，不需藉位
			else {
				borrow = 1;
				data->Result[i] = data->Result[i] + 10;
			}
		}
		if (data->Result[0] == 9)
		{
			data->isPositibeResult = false;//設為負值

			//處理數值
			for (int i = 0; i < SIZE; i++)
			{
				data->Result[i] = 9 - data->Result[i];
			}
			data->Result[SIZE - 1]++;

		}
	}
}

void PrintBeforeOperate(BigNumber* data) {

	cout << "輸入數1 : " << endl;
	int flag = 0;
	if (data->isPositiveInt_1 == false) cout << "-";
	for (int i = 0; i < SIZE; i++) {

		//用flag處理前面多餘的0
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

	cout << "輸入數2 : " << endl;
	if (data->isPositiveInt_2 == false) cout << "-";
	flag = 0;
	for (int i = 0; i < SIZE; i++) {

		//用flag處理前面多餘的0
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

	
	AddOperate* addFunction = new AddOperate();//加的功能 用new的
	SubOperate* subFunction = new SubOperate();
	MultiplyOperate* multiplyFunction = new MultiplyOperate();
	DivideOperate* divideFunction = new DivideOperate();

	/*
	Caculator使用方法:
	1.先建立Caculator物件
	2.配置要操作的功能function (+-/*)
	3.配置要輸入操作的大數
	4.Execute執行
	*/

	//建立計算機
	Caculator* caculator = new Caculator();

	//加法
	caculator-> SetOperator(addFunction);
	caculator-> SetOperatorInt(Data);
	caculator-> Execute();
	caculator-> Show();
	//caculator-> Show(); //測試，確定清空會連動

	cout << endl;

	BigNumber* Data2 = new BigNumber;
	//減法
	caculator->SetOperator(subFunction);
	caculator->SetOperatorInt(Data2);
	caculator->Execute();
	caculator->Show();
	
	cout << endl;

	//直式乘法
	BigNumber* Data3 = new BigNumber;
	caculator->SetOperator(multiplyFunction);
	caculator->SetOperatorInt(Data3);
	caculator->Execute();
	caculator->Show();

	cout << endl;

	//直式乘法
	BigNumber* Data4 = new BigNumber;
	caculator->SetOperator(divideFunction);
	caculator->SetOperatorInt(Data4);
	caculator->Execute();
	caculator->Show();

	cout << endl;

	system("pause");

}