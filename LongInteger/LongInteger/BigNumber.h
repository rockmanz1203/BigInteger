#pragma once
#define SIZE 50

class BigNumber {
public:
	//第一位會被用作於判斷正負號
	int Integer1[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,5 };
	int Integer2[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,5 };

	int Result[SIZE] = { 0 };//result
	bool isPositiveInt_1 = true;//
	bool isPositiveInt_2 = false;//
	bool isPositibeResult = true;
};