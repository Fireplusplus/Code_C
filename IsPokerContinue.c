/* 从扑克牌中随机抽5张牌，判断是不是一个顺子 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;
}

int IsPokerContinue(int *num, int len)
{
	int small, big;
	int zero = 0, sub = 0;
	int i = 0;

	if (NULL == num || len < 1)
		return 0;	//不是顺子

	qsort(num, len, sizeof(int), cmp);

	for (i = 0; i < len && 0 == num[i]; ++i)
		++zero;

	small = zero;
	big = small + 1;
	for (; big < len;++big)
	{
		if (num[big] == num[small])	//相等不为顺子
			return 0;

		sub += num[big] - num[small] - 1;
		++small;
	}

	return sub <= zero ? 1 : 0;
}


int main()
{
	int arr[] = {6, 2, 0, 3, 5};

	if (IsPokerContinue(arr, 5))
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
