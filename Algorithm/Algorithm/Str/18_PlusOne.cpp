#include "..\Include\18_PlusOne.h"
#include "stdio.h"
#include "malloc.h"


int* PlusOne(int* digits, int digitsSize, int * returnSize)
{
	if (digits == NULL)return 0;
	if (returnSize == NULL)return 0;
	if (digitsSize == 0)return 0;
	for (int j = 0; j < digitsSize; j++)
		if (digits[j] >= 10 || digits[j] < 0)
			return 0;
	int carry = 1;
	if (digits[digitsSize - 1] == 9)
	digits[digitsSize - 1] = digits[digitsSize - 1];
	for (int i = digitsSize-1; i >= 0; i--){
		if (digits[i] == 9&&carry){
			digits[i] = 0; carry = 1;
		}
		else{
			digits[i] = digits[i] + carry;
			carry = 0;
		}
	}
	if (carry){
		*returnSize = digitsSize + 1;
		int *ret_digits = (int*)calloc(*returnSize, sizeof(int));
		ret_digits[0] = 1;
		return ret_digits;
	}
	else{
		*returnSize = digitsSize;
		return digits;
	}
}