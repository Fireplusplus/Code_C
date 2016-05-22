/*
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s，
 * 输入n，打印出s的所有可能的值出现的概率
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max = 6;

void Pro(int num, int cur, int sum, int *pro)
{
	if (cur == 1)
		pro[sum - num]++;
	else
	{
		int i = 1;

		for (; i <= max; ++i)
			Pro(num, cur - 1, i + sum, pro);
	
	}

}


void Probability(int num, int *pro)
{
	int i = 1;
	
	for (; i <= max; ++i)
		Pro(num, num, i, pro);
}

void PrintProbability(int num)
{
	int max_sum = num * max;
	int *pro = (int *)calloc(max_sum - num + 1,  sizeof(int));
	int total, i;

	if (num < 1)
		return;
	
	Probability(num, pro);
	total = pow((double)max, num);

	for (i = num; i <= max_sum; ++i)
	{
		double ratio = (double)pro[i - num] / total;
		printf("%d: %e\n", i, ratio);
	}

	free(pro);
}

 int main()
 {
 	PrintProbability(2);
 
 	return 0;
 }
