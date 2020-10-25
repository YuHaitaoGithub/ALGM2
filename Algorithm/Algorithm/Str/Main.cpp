#include "..\Include\03_IsUgly.h"
#include "Windows.h"
#include "stdio.h"
void main()
{
	int num;
	while (scanf_s("%d", &num))
	{
		printf("%d\n", IsUgly(num));
	}


}