#define _CRT_SECURE_NO_WARNINGS
#include "..\Include\09_AddBinary.h"
#include "string.h"
#include "malloc.h"
char * AddBinary(char * a, char * b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	if ((lena > 10000) || (lena < 1))return "0";
	if ((lenb > 10000) || (lenb < 1))return "0";
	
	int maxlen = lena >= lenb ? lena : lenb;
	int i, tempa, tempb, carry = 0;
	char *value = (char *)calloc(maxlen + 2, 1);//+2��\0�ͽ�λ
	
	while (lena>0 || lenb>0)
	{
		tempa = (lena--)>0 ? a[lena] - '0' : 0;//�ӵ�λ��ʼ����
		tempb = (lenb--)>0 ? b[lenb] - '0' : 0;
		value[maxlen--] = ((tempa^tempb) ^ carry) + '0';//
		carry = (tempa&tempb) | ((tempa^tempb)&carry);//�ж��Ƿ���Ҫ��λ
	}
	if (carry == 1)//�����һ�μӺ����޽�λ
		value[0] = '1';
	else 
		strcpy(value, value + 1);

	return value;
}