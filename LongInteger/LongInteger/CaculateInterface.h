#pragma once
#include"BigNumber.h"
class CaculateInterface
{
public:
	virtual void Execute() = 0;
	virtual void SetInt(BigNumber* Data) = 0;
	//Caculator* Caculator;//¥Î¨Ó´«operater

};