#pragma once
#pragma once
#include<iostream>
#include"CaculateInterface.h"

class MultiplyOperate : public CaculateInterface //�~�Ӧ۳W��
{
public:

	void Execute();
	void SetInt(BigNumber* Data);

	BigNumber* data;

};