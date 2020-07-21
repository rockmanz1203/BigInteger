#include<iostream>
#include "MultiplyOperate.h"
#define SIZE 50
using namespace std;

void Add(BigNumber* data);
void Subtract(BigNumber* data);
void Multiply(BigNumber* data);
void Divide(BigNumber* data);

void MultiplyOperate::Execute()
{
	cout << "乘法策略執行成功" << endl;
	//Add(data);
	//+5*-4 = -20
	if (data->isPositiveInt_1 != data->isPositiveInt_2) 
	{
		data->isPositibeResult = false;
	}
	else {
		data->isPositibeResult = true;
	}
	int carry = 0;
	int temp = 0;
	int i = 0;
	int j = 0;
	int resultIndex = SIZE - 1;
	
	for (int j = SIZE - 1; j >= 0; j--) {//B數index 乘數int_2
		carry = 0;
		resultIndex = j;
		for (int i = SIZE - 1; i >= 0; i--) 
		{
			
			//A數index 被乘數 int_1
			temp = data->Integer1[i] * data->Integer2[j] + data->Result[resultIndex] + carry;
			//有問題，這樣第一位會是A[49]*B[49]=>result[98]
			//但是沒有[98]這個index空間 所以不能用[i+j]這個方法來存

			carry = temp / 10;
			if (resultIndex >= 0)
			{
				//超出50位的就不處理了
			data->Result[resultIndex] = temp % 10;
			resultIndex--;
			//cout << temp << endl;
			}
		}
		//cout << "出迴圈" << endl;
	}

}
void MultiplyOperate::SetInt(BigNumber* Data)
{
	data = Data;
}
