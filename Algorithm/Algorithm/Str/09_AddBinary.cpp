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
		value[i--] = ((tempa^tempb) ^ carry) + '0';//������ֵ��ʱ���н�λ����ǰֵΪ1������ֵ����ʱ���н�λ����ǰλ��Ϊ0
		carry = (tempa&tempb) | ((tempa^tempb)&carry);//�ж��Ƿ���Ҫ��λ
	}

	if (carry == 1)//�����һ�μӺ����޽�λ
	{
		for (i = maxlen + 1; i>0; i--)
		{
			value[i] = value[i - 1];
		}
		value[0] = '1';
	}
	return value;
}