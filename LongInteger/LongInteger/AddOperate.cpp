#include<iostream>
#include "AddOperate.h"
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

void AddOperate::Execute() 
{
	cout << "加法策略執行成功" << endl;
	Add(data);
}
void AddOperate::SetInt(BigNumber* Data)
{
	data = Data;
}