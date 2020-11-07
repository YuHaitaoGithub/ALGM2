#include "..\Include\13_MyAtoi.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int MyAtoi(char * s)
{
	if (s[0] == '\0')
		return 0;
	int a[12] = {};
	char *p1 = "2147483648";
	char *p2 = "2147483647";
	char *p = NULL;
	int f, t, i, j, t1, t2;
	f = t = t1 = t2 = 1;
	i = j = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' '&&t2)
			continue;
		if (s[i] == '+' && t)
		{
			f = 1; i++; t = 0;
		}
		if ((s[i] == '-') && t)
		{
			f = -1; i++; t = 0;
		}
		if ((s[i] - '0' <= 9) && (s[i] - '0' >= 0))
		{
			t = 0; t2 = 0;
			if (s[i] == '0'&&t1)continue;
			else {
				a[j++] = s[i] - '0'; t1 = 0;
			}
		}
		else
			break;
		if (j >= 12)
			break;
	}
	j--;
	if (j >= 10)
		return f == 1 ? INT_MAX : INT_MIN;
	else if (j == 9)
	{
		p = (f == 1 ? p2 : p1);
		for (int x = 0; x <= j; x++)
		{
			if (a[x] > p[x] - '0')
				return f == 1 ? INT_MAX : INT_MIN;
			if (a[x] < p[x] - '0')
				break;
		}
	}
	int ret = 0;
	for (int k = 0; k <= j; k++)
	{
		ret = (int)pow(10.0, j - k) * (f * a[k]) + ret;
	}
	return ret;
}