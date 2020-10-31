#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\13_MyAtoi.h"
#include "Windows.h"
#include "stdio.h"
#include "malloc.h"




void main()
{
	/*while (1)
	{
		char s[100] = {};
		gets(s);
		printf("%d\n", IsValid(s));
	}*/
	while (1)
	{
		char s[100] = {};
		gets(s);
		printf("%d\n", MyAtoi(s));
	}
}