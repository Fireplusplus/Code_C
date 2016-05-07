/*
 * 输入一个整型数组，实现一个函数来调整该数组中数字的顺序，是的所有奇数
 * 位于数组的前半部分，所有偶数位于数组的后半部分
 */
#include <stdio.h>
#include <assert.h>

void swap(int *e1, int *e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void let_odd_in_front_of_even(int *arr, int n)
{
	int even = -1, odd = 0;
	assert(arr);
	if (n <= 0)
		return;

	for (odd = 0; odd < n; odd++)
	{
		if (1 == (arr[odd] & 1))
		{
			even++;
			if (even != odd)
			{
				swap(&arr[even], &arr[odd]);
			}
		}
			
	}
}

int main()
{
	int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int i = 0;

	let_odd_in_front_of_even(test, 10);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", test[i]);
	}
	printf("\n");

	return 0;
}
