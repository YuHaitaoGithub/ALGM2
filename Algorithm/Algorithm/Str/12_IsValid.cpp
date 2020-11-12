#include "..\Include\12_IsValid.h"
#include "string.h"
#include "malloc.h"
bool IsValid(char *s)
{
	int len = strlen(s);
	char *arr = (char*)calloc(len + 1, sizeof(char));   
	if (arr == NULL)
		return false;
	int point = -1;       
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')arr[++point] = ')';
		else if (s[i] == '[')
			arr[++point] = ']';
		else if (s[i] == '{')
			arr[++point] = '}';
		else if (point == -1 || s[i] != arr[point])
			return false;
			else point--;
	}
	free(arr);
	return (point == -1);
}

//bool IsValid(string s)
//{
//	if (s.size() == 0)
//		return false;
//	stack<char>my_stack;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '(')
//			my_stack.push(')');
//		else if (s[i] == '{')
//			my_stack.push('}');
//		else if (s[i] == '[')
//			my_stack.push(']');
//		else if (my_stack.empty() || s[i] != my_stack.top())
//			return false;
//		else
//			my_stack.top();
//	}
//	return my_stack.empty();
//}