/* 
 * 给定 x, k ，求满足 x + y = x | y 的第 k 小的正整数 y 。
 * | 是二进制的或(or)运算，例如 3 | 5 = 7。
 * 比如当 x=5，k=1时返回 2，因为5+1=6 不等于 5|1=5，
 * 而 5+2=7 等于 5 | 2 = 7。
 */
#include <stdio.h>

int Num(int x, int k)
{
	int cnt = 0;
	int y = 1;

	if (k <= 0)
		return 0;

	while (cnt != k)
	{
		if (x + y == x | y)
			cnt++;
		y++;
	}

	return y;
}


int main()
{
	int ret = Num(5, 1);
	printf("%d\n", ret);

	return 0;
}
