/*
 * 把只包含因子2、3、5的数称作丑数。求按照从小到大的顺序的第1500个
 * 丑数。习惯上把1当做第一个丑数
 */

 #include <stdio.h>
#include <stdlib.h>

int IsUgly(int num)
{
	if (num <= 0)
		return 0;

	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;

	return num == 1 ? 1 : 0;
}

int FindNthUglyNum(int n)
{
	int k = 0;
	int i = 0;

	if (n <= 0)
	{
		return 0;
	}
	
	while (k != n)
	{
		++i;
		if (IsUgly(i))
			k++;
	}
	
	return i;
}

int Min(int num1, int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;

	return min;
}

int FindNthUglyNum_2(int index)
{
	int ugly;
	int *pUgly = NULL;
	int next = 1;
	int *p2, *p3, *p5; 
	if (index <= 0)
		return 0;

	pUgly = (int *)malloc(sizeof(int) * index);
	pUgly[0] = 1;
	p2 = pUgly;
	p3 = pUgly;
	p5 = pUgly;

	while (next < index)
	{
		int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
		pUgly[next] = min;

		while (*p2 * 2 <= pUgly[next])
			++p2;
		while (*p3 * 3 <= pUgly[next])
			++p3;
		while (*p5 * 5 <= pUgly[next])
			++p5;

		++next;
	}
	ugly = pUgly[next - 1];
	free(pUgly);

	return ugly;
}

 int main()
 {
 	int ret = FindNthUglyNum_2(10);
	printf("%d\n", ret);

 	return 0;
 }
