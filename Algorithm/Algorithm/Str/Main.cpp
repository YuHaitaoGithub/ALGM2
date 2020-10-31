#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\11_CanWinNim.h"
#include "Windows.h"
#include "stdio.h"
#include "malloc.h"




void main()
{
	//	Algm4_Test();
	int n = 0;
	while (scanf_s("%d", &n))
	{
		printf("%d\n", CanWinNim(n));
	}
	
}