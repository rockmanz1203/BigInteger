#pragma once
#include<iostream>
#include"CaculateInterface.h"

class AddOperate : public CaculateInterface //�~�Ӧ۳W��
{
public:

	void Execute();
	void SetInt(BigNumber* Data);

	BigNumber* data;

};