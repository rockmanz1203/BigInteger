#pragma once
#include"CaculateInterface.h"

//可以換裝功能的計算機
class Caculator
{
public:
	//執行裝入的功能
	void Execute();
	//抽換功能
	void SetOperator(CaculateInterface* CaculateFunction);
	void SetOperatorInt(BigNumber* Data);
	void Show();

private:
	CaculateInterface* CaculateOperator;
	BigNumber* CaculateData;
};