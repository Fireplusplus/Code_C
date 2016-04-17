#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 写冒泡排序可以排序多个字符串 */
void string_bubble_sort(char * str[], int sz)	//字符串指针数组， 字符串指针个数
{
	int i = 0,  j= 1;
	int flag = 0;
	for (i = 1; i < sz; i++)
	{
		flag = 0;
		for (j = 1; j < sz; j++)
		{
			if (strcmp(str[j - 1], str[j]) > 0)
			{
				char * tmp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

}

int main()
{	
	int i = 0;

	char * str[5] = {
		"abcde",
		"abcdfg",
		"cbce",
		"abcde",
		"ebe"
	};
	string_bubble_sort(str, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", str[i]);
	}

	system("pause");
	return 0;
}