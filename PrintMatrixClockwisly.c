#include <stdio.h>
#include <assert.h>

#define ROWS 4
#define COLS 4

void PrintMatrixInCircle(int (*arr)[COLS], int rows, int cols, int start)
{
	int end_x = cols - 1 - start;
	int end_y = rows - 1 - start;
	int i = 0;

	for (i = start; i <= end_x; i++)	//从左至右打印一行
	{
		printf("%d ", arr[start][i]);
	}
	
	if (end_y > start)			//从上到下打印一列
	{
		for (i = start + 1; i <= end_y; i++)
		{
			printf("%d ", arr[i][end_x]);
		
		}
	}
	if (end_x > start && end_y > start)	//从右至左打印一行
	{
		for (i = end_x - 1; i >= start; i--)
		{
			printf("%d ", arr[end_y][i]);
		}
	}
	if (end_x > start && end_y > start + 1)	//从下至上打印一列
	{
		for (i = end_y - 1; i > start; i--)
		{
			printf("%d ", arr[i][start]);
		}
	}

}

void PrintMatrixClockwisly(int (*arr)[COLS], int rows, int cols)
{
	int start = 0;

	assert(NULL != arr);
	
	if (0 >= rows || 0 >= cols)
	{
		return;
	}
	
	while (rows > start * 2 && cols > start * 2)
	{
		PrintMatrixInCircle(arr, rows, cols, start);
		++start;
	}
	printf("\n");
}

int main()
{
	int arr[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	PrintMatrixClockwisly(&arr[0], ROWS, COLS);

	return 0;
}
