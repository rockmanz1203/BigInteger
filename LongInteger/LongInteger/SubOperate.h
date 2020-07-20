#pragma once
#include<iostream>
#include"CaculateInterface.h"

using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

class SubOperate : public CaculateInterface //Ä~©Ó¦Û³W®æ
{
public:
	void Execute();
	void SetInt(BigNumber* Data);

	BigNumber* data;
};