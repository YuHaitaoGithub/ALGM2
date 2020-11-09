#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\13_MyAtoi.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int MyAtoi(char * s)
{
	int len = strlen(s);
	if (len == 0)return 0;
	int f = 1;
	while (*s == ' ')
		s++;
	switch (*s)
	{
		case '-':{f = -1; s++; break; }
		case '+':{s++; break; }
	}
	if (len > 12)
	{
		if (f == 1)
			return INT_MAX;
		else
			return INT_MIN;
	}
	if ((*s - '0' < 0) || (*s - '0' > 9))
		return 0;
	long long ret = 0;
	while ((*s - '0' >= 0) && (*s - '0' <= 9))
	{
		ret = ret * 10 + (*s - '0');
		if (ret != ((int)ret))
			return f == 1 ? INT_MAX : INT_MIN;
		s++;
	}
	ret = ret * f;
	return (int)ret;
}






