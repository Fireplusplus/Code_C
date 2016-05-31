#include <stdio.h>

int cmp(int job[][2], int index1, int index2)
{
	if (job[index1][0] < job[index2][0])
		return -1;
	else if (job[index1][0] > job[index2][0])
		return 1;
	else
	{
		if (job[index1][1] < job[index2][1])
			return -1;
		else if (job[index1][1] > job[index2][1])
			return 1;
		else
			return 0;
	}
}

void Swap(int job[][2], int index1, int index2)
{
	int tmp = job[index1][0];
	job[index1][0] = job[index2][0];
	job[index2][0] = tmp;
	tmp = job[index1][1];
	job[index1][1] = job[index2][1];
	job[index2][1] = tmp;
}

void BubbleSort(int job[][2], int n)
{
	int i, j;
	int flag;

	for (i = 1; i < n; i++)
	{
		flag = 1;
		for (j = 0; j < n - i; j++)
		{
			if (cmp(job, j, j + 1) == 1)
			{
				Swap(job, j,j + 1);
				flag = 0;
			}
		}
		if (1 == flag)
			break;
	}
}

double AvgTime(int job[][2], int n)
{
	int i;
	int time = 0;

	if (NULL == job || n <= 0)
		return -1;

	BubbleSort(job, n);
	
	for (i = 0; i < n - 1; i++)
	{
		time += job[i][1];
	}
	return time / (double)n;
}

int main()
{
	int job[][2] = {{1, 5}, {1, 3}, {1, 4}, {2, 1}};
	double ret = AvgTime(job, 4);
	printf("%f\n", ret);
	return 0;
}
