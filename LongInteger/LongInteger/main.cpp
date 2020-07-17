#include <iostream>
#define SIZE 50

using namespace std;

class BigNumber {
public:
	int Integer1[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 };
	int Integer2[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

	int Result[SIZE] = { 0 };//result
	bool isPositiveInt_1 = true;
	bool isPositiveInt_2 = true;
};

class CaculateInterface 
{
public:
	virtual void Execute() = 0;
	virtual void SetInt(BigNumber* Data) = 0;

};

class AddOperate : public CaculateInterface //繼承自規格
{
public:
	void Execute() {
		cout<<"加法執行成功"<<endl;
		
		if (data->isPositiveInt_2 == false) {
			//如果輸入減數為負

		}
		else {
			//如果兩者為正
			int Carry = 0;//進位
			for (int i = SIZE - 1; i >= 0; i--) 
			{
				data->Result[i] = data-> Integer1[i] + data-> Integer2[i] + Carry;

				if (data->Result[i] < 10)  Carry = 0;
				else {
					//進位
					data->Result[i] = data->Result[i]-10;
					Carry = 1;
				}
			}
		}
	}
	void SetInt(BigNumber* Data) 
	{
		data = Data;	
	}
	BigNumber* data;
};
class SubOperate : public CaculateInterface //繼承自規格
{
public:
	void Execute() {
		cout << "減法執行成功" << endl;
		if (data->isPositiveInt_2 == false) 
		{
			//如果輸入減數為負
		}
		else {
			int borrow = 0;//借位
			for (int i = SIZE - 1; i >= 0; i--)
			{
				data->Result[i] = data->Integer1[i] - data->Integer2[i] - borrow;
				if (data->Result[i] >= 0) borrow = 0;
				else {
					borrow = 1;
					data->Result[i] = data->Result[i] + 10;
				}
			}
		}
	}
	void SetInt(BigNumber* Data) {
		data = Data;
	}
	BigNumber* data;
};

//可以換裝功能的計算機
class Caculator 
{
public:
	//執行裝入的功能
	void Execute()
	{
		CaculateOperator->Execute();
	}
	//抽換功能
	void SetOperator(CaculateInterface* CaculateFunction) {
		CaculateOperator = CaculateFunction;
	}
	void SetOperatorInt(BigNumber* Data)
	{
		CaculateOperator->SetInt(Data);
		CaculateData = Data;
	}
	void Show() {
		for (int i = 0; i < SIZE; i++) {
			cout << CaculateData->Result[i];
			CaculateData->Result[i] = 0;//計算完畢 清空
		}
		cout << endl;
	}

private:
	CaculateInterface* CaculateOperator;
	BigNumber* CaculateData;
};

int main() {

	BigNumber* Data = new BigNumber;
	

	AddOperate* addFunction = new AddOperate();//加的功能 用new的
	SubOperate* subFunction = new SubOperate();


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

	//減法
	caculator->SetOperator(subFunction);
	caculator->SetOperatorInt(Data);
	caculator->Execute();
	caculator->Show();
	
	


	system("pause");

}