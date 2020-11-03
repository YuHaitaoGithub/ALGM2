#include "..\Include\12_IsValid.h"
#include "string.h"
#include "malloc.h"
bool IsValid(char *s)
{
	int len = strlen(s);
	char *arr = (char*)calloc(len + 1, sizeof(char));   
	if (arr == NULL)return false;
	int point = -1;       
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')arr[++point] = ')';
		else if (s[i] == '[')arr[++point] = ']';
		else if (s[i] == '{')arr[++point] = '}';
		else if (point == -1 || s[i] != arr[point])
		return false;
		else point--;
	}
	free(arr);
	return (point == -1);
}
