/* 给定一个字符串，问是否能通过添加一个字母将其变为回文串 */

#include <stdio.h>
#include <string.h>

int IsPalin(char *start, char *end)
{
	while (start < end)
	{
		if (*start++ != *end--)
			return 0;
	}

	return 1;
}

int judge(char *start, char *end)
{
	if (start >= end)
		return 0;
	
	//判断是否可以通过在左边添加一个字母使其成为回文串
	if (IsPalin(start, end - 1))
		return 1;
	//判断是否可以通过在右边添加一个字母使其成为回文串
	else if (IsPalin(start + 1, end))
		return 1;
	else //在中间加
	{
		while (start < end)
		{
			if (*start++ != *end--)
			{
				if (IsPalin(start, end + 1))
					return 1;
				else if (IsPalin(start - 1, end))
					return 1;
				else
					return 0;
			}
		}
	}
}

int main()
{
	char *arr = "abcdba";
	int len = strlen(arr);
	char *end = arr + len - 1;
	int ret = judge(arr, end);

	if (ret)
		printf("yes\n");
	else
		printf("no\n");
	
	return 0;
}
