#include<iostream>
#include "AddOperate.h"
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

void AddOperate::Execute() 
{
	cout << "�[�k�������榨�\" << endl;
	Add(data);
}
void AddOperate::SetInt(BigNumber* Data)
{
	data = Data;
}