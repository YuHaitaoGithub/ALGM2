#include "..\Include\01_ContainsNearbyDuplicate.h"
#include "stdio.h"
void main()
{
	int num = 0;
	int nums[4] = {1,3,3,2};
	while (scanf_s("%d", &num)){
	printf("%d\n", ContainsNearbyDuplicate(nums, 4, num));
}

}