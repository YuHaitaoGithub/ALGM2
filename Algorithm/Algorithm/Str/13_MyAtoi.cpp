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
	if ((*s - '0' < 0) || (*s - '0' > 9))
		return 0;
	int ret = 0;
	while ((*s - '0' >= 0) && (*s - '0' <= 9))
	{
		if ((ret > INT_MAX / 10 || (ret == INT_MAX / 10 && (*s - '0') > 7))&&f == 1)
			return INT_MAX;
		if ((ret < INT_MIN / 10 || (ret == INT_MIN / 10 && (*s - '0') > 8))&&f == -1)
			return INT_MIN;
		ret = ret * 10 + (*s - '0') * f;
		s++;
	}
	return ret;
}






