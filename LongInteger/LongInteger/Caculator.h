#pragma once
#include"CaculateInterface.h"

//�i�H���˥\�઺�p���
class Caculator
{
public:
	//����ˤJ���\��
	void Execute();
	//�⴫�\��
	void SetOperator(CaculateInterface* CaculateFunction);
	void SetOperatorInt(BigNumber* Data);
	void Show();

private:
	CaculateInterface* CaculateOperator;
	BigNumber* CaculateData;
};