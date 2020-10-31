#include "..\Include\11_CanWinNim.h"

bool CanWinNim(int n)
{
	if (n & 3 == 0)return true;
	return false;
}