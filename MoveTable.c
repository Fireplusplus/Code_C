/* 
 * 现在有一张半径为r的圆桌，其中心位于(x,y)，现在他想把圆桌的中心移到(x1,y1)。
 * 每次移动一步，都必须在圆桌边缘固定一个点然后将圆桌绕这个点旋转。问最少需要移动几步 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void steps()
{
	int r, x, y, x1, y1;
	double d;
	int cnt;

	while (scanf("%d%d%d%d%d", &r, &x, &y, &x1, &y1) != EOF)
	{
		d = sqrt((double)(x - x1) * (x - x1) + (y - y1) * (y - y1));
		
		cnt = 0;
		while (d > 0)
		{
			d -= (1 + r * 2);
			cnt++;
		}
		printf("%d\n", cnt);
	}
}

int main()
{
	steps();

	return 0;
}