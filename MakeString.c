/*
 * 现在有一个字符串，你要对这个字符串进行 n 次操作，
 * 每次操作给出两个数字：(p, l) 表示当前字符串中从下标为 p 的字符开始
 * 的长度为 l 的一个子串。你要将这个子串左右翻转后插在这个子串原来位置
 * 的正后方，求最后得到的字符串是什么。字符串的下标是从 0 开始的，
 * 你可以从样例中得到更多信息。每组测试用例仅包含一组数据，
 * 每组数据第一行为原字符串，长度不超过 10 ，仅包含大小写字符与数字。
 * 接下来会有一个数字 n 表示有 n 个操作，再接下来有 n 行，每行两个整数，
 * 表示每次操作的(p , l)。保证输入的操作一定合法 
 */
#include <stdio.h>
#include <string.h>

void MakeString(char *str, int start, int len)
{
	int size;
	char *tail;
	int right = start + len - 1;
	if (NULL == str || start < 0 || len <= 0)
		return;
	size = strlen(str);
	tail = str + size;

	while (right >= start)
	{
		*tail++ = str[right--];
	}
	*tail = '\0';
}

int main()
{
	char str[100] = {0};
	int n;
	scanf("%s", str);
	scanf("%d", &n);

	while (n--)
	{
		int left, right;
		scanf("%d%d", &left, &right);
		MakeString(str, left, right);
	}
	printf("%s\n", str);

	return 0;
}
