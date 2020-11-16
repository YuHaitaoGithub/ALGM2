#include "..\Include\03_IsUgly.h"
#include "string.h"

bool IsUgly(int num)
{
	if (num == 0) return false;
	if (num == 1)return true;
	int i = 2;
	while (num % i == 0)num /= i;
	i = 3;
	while (num % i == 0)num /= i;
	i = 5;
	while (num % i == 0)num /= i;
	return num == 1;
}



