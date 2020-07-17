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

class AddOperate : public CaculateInterface //�~�Ӧ۳W��
{
public:
	void Execute() {
		cout<<"�[�k���榨�\"<<endl;
		
		if (data->isPositiveInt_2 == false) {
			//�p�G��J��Ƭ��t

		}
		else {
			//�p�G��̬���
			int Carry = 0;//�i��
			for (int i = SIZE - 1; i >= 0; i--) 
			{
				data->Result[i] = data-> Integer1[i] + data-> Integer2[i] + Carry;

				if (data->Result[i] < 10)  Carry = 0;
				else {
					//�i��
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
class SubOperate : public CaculateInterface //�~�Ӧ۳W��
{
public:
	void Execute() {
		cout << "��k���榨�\" << endl;
		if (data->isPositiveInt_2 == false) 
		{
			//�p�G��J��Ƭ��t
		}
		else {
			int borrow = 0;//�ɦ�
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

//�i�H���˥\�઺�p���
class Caculator 
{
public:
	//����ˤJ���\��
	void Execute()
	{
		CaculateOperator->Execute();
	}
	//�⴫�\��
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
			CaculateData->Result[i] = 0;//�p�⧹�� �M��
		}
		cout << endl;
	}

private:
	CaculateInterface* CaculateOperator;
	BigNumber* CaculateData;
};

int main() {

	BigNumber* Data = new BigNumber;
	

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

	//��k
	caculator->SetOperator(subFunction);
	caculator->SetOperatorInt(Data);
	caculator->Execute();
	caculator->Show();
	
	


	system("pause");

}