#pragma once
#pragma once
#include<iostream>
#include"CaculateInterface.h"

class MultiplyOperate : public CaculateInterface //Ä~©Ó¦Û³W®æ
{
public:

	void Execute();
	void SetInt(BigNumber* Data);

	BigNumber* data;

};