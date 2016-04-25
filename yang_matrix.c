#include <stdio.h>

#define ROW 4
#define COL 4

int search(int *matrix, int rows, int cols, int val)
{
	if ((NULL != matrix) && (rows > 0) && (cols > 0))
	{
		int row = rows - 1;
		int col = 0;

		while ((row >= 0) && (col < cols))
		{
			if (val == *(matrix + row*cols + col))
			{
				return 1;	//找到			
			}
			else if (val < *(matrix + row*cols + col))
			{
				row--;	
			}
			else
			{
				col++;
			}
		}
	}
	
	return 0;				//没找到
}

int main()
{
	int yang[4][4] = {
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};	
	int ret = search(&yang[0][0], ROW, COL, 14);

	if (ret == 1)
		printf("exist\n");
	else
		printf("not exist\n");

	return 0;
}
