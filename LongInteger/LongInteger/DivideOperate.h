#pragma once
#include<iostream>
#include"CaculateInterface.h"

class DivideOperate : public CaculateInterface //�~�Ӧ۳W��
{
public:

	void Execute();
	void SetInt(BigNumber* Data);

	BigNumber* data;

};