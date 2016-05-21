/* 输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数） */

#include <stdio.h>

void Print(int left, int right)
{
	for (; left <= right; ++left)
		printf("%d ", left);
	printf("\n");
}

void FindContinuousSequence(int s)
{
	int small = 1, big = 2; 
	int mid = (s + 1) / 2;
	int sum = small + big;

	while (small < mid)
	{
		if (sum == s)
		{
			Print(small, big);
			++big;
			sum += big;
		}
		else if (sum < s)
		{
			++big;
			sum += big;
		}
		else 
		{
			sum -= small;
			++small;
		}
	}
}

int main()
{

	FindContinuousSequence(15);

	return 0;
}
