/* 
 * 你作为一名出道的歌手终于要出自己的第一份专辑了，
 * 你计划收录 n 首歌而且每首歌的长度都是 s 秒，
 * 每首歌必须完整地收录于一张 CD 当中。每张 CD 的容量长度都是 L 秒，
 * 而且你至少得保证同一张 CD 内相邻两首歌中间至少要隔 1 秒。
 * 为了辟邪，你决定任意一张 CD 内的歌数不能被 13 这个数字整除，
 * 那么请问你出这张专辑至少需要多少张 CD ？
 * 输入描述:
 * 每组测试用例仅包含一组数据，每组数据第一行为三个正整数 n, s, L。 
 * 保证 n ≤ 100 , s ≤ L ≤ 10000 
 */

#include <stdio.h>

int num(int n, int s, int l)
{
	int NumOfEachCD = l / (s + 1);
	int sum;
	
	if (n < 0 || s < 0 || l <= 0)
		return -1;

	if (NumOfEachCD % 13 == 0)
		NumOfEachCD--;
		
	sum = n / NumOfEachCD;
	if (n % NumOfEachCD != 0)
		sum++;
		
	return sum;
}

int main()
{
	int ret = num(7, 2, 6);

	printf("%d\n", ret);

	return 0;
}
