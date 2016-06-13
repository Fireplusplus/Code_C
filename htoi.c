#define _CRT_SECURE_NO_WARNINGS
/*  
 * 写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。
 * 输入描述:
 * 输入一个十六进制的数值字符串。
 * 输出描述:
 * 输出该数值的十进制字符串 
 */
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int htoi(char *h)
{
	char *str = h;
	long long rs = 0;

	if (NULL == str)
		return -1;

	while (isspace(*str))
		h++;

	if (*str == '0' && *(str + 1) == 'x')
		str += 2;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			rs = rs * 16 + (*str - '0');
		else if (*str >= 'A' && *str <= 'F')
			rs = rs * 16 + (*str - 'A' + 10);
		else if (*str >= 'a' || *str <= 'f')
			rs = rs * 16 + (*str - 'a' + 10);
		else
			break;

		str++;
		if (rs > INT_MAX)
			return -1;
	}

	return (int)rs;
}
int main()
{
	char arr[10];
	int ret;

	while (scanf("%s", arr) != EOF)
	{
		ret = htoi(arr);
		printf("%d\n", ret);
	}

	return 0;
}