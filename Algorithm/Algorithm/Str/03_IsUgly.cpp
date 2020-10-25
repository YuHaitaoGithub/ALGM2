#include "..\Include\03_IsUgly.h"
#include "string.h"

bool IsUgly(int num)
{
	if (num <= 0) return false;
	if (num == 1)return true;
	int arr[3] = { 2, 3, 5 };
	for (int i = 0; i < 3; i++)
	{
		while (num % arr[i] == 0)
		{
			num /= arr[i];
		}
	}
	// 1 ÊÇ³óÊý
	return num == 1;
}