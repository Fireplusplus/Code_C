/* 求连续字数组的最大和 */
#include <stdio.h>
//#include <limts.h>

enum
{
	VALID,
	INVALID
}state;

int FindGreatestSumOfSubArray(int arr[], int n)
{
	int sum = 0;
	int old_sum = 0x80000000;
	int i = 0;
	state = INVALID;
	
	if (NULL == arr || n <= 0)
		return 0;

	for (i = 0; i < n; i++)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}

		if (sum > old_sum )
		{
			old_sum = sum;
		}
	}
	state = VALID;

	return old_sum;
}

int main()
{
	int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};

	int ret = FindGreatestSumOfSubArray(arr, 8);
	
	if (VALID == state)
		printf("%d\n", ret);
	else
		printf("Invalid Input!\n");
	return 0;
}
