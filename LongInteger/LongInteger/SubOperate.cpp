#include<iostream>
#include "SubOperate.h"
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

void SubOperate::Execute() 
{
	cout << "��k�������榨�\" << endl;
	Subtract(data);
}
void SubOperate::SetInt(BigNumber* Data) 
{
	data = Data;
}