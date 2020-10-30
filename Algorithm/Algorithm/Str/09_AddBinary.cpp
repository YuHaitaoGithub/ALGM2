#include "..\Include\09_AddBinary.h"
#include "string.h"
#include "malloc.h"
char * AddBinary(char * a, char * b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	if ((lena > 10000) || (lena < 1))return NULL;
	if ((lenb > 10000) || (lenb < 1))return NULL;
	
	int maxlen = lena >= lenb ? lena : lenb;
	int i, tempa, tempb, carry = 0;
	char *value = (char *)calloc(maxlen + 2, 1);
	
	i = maxlen - 1;
	while (lena>0 || lenb>0)
	{
		tempa = (lena--)>0 ? a[lena] - '0' : 0;
		tempb = (lenb--)>0 ? b[lenb] - '0' : 0;
		value[i--] = ((tempa^tempb) ^ carry) + '0';//当两个值等时，有进位，则当前值为1，两个值不等时，有进位，当前位则为0
		carry = (tempa&tempb) | ((tempa^tempb)&carry);//判断是否需要进位
	}

	if (carry == 1)//看最后一次加后有无进位
	{
		for (i = maxlen + 1; i>0; i--)
		{
			value[i] = value[i - 1];
		}
		value[0] = '1';
	}
	return value;
}