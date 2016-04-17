#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
* 实现一个函数，可以左旋字符串中的k个字符。
* AABCD左旋一个字符得到ABCDA
* AABCD左旋两个字符得到BCDAA
*/
char * left_move(char * src, int k)
{
	int i = 0;
	int len = strlen(src);
	char tmp = 0;
	assert(src);

	for (i = 0; i < len / 2; i++)			//整体逆序
	{
		tmp = *(src + i);
		*(src + i) = *(src + len - 1 - i);
		*(src + len - 1 - i) = tmp;
	}

	for (i = 0; i < (len - k) / 2; i++)		//左串逆序
	{
		tmp = *(src + i);
		*(src + i) = *(src + len - k - 1 - i);
		*(src + len - k - 1 - i) = tmp;
	}

	for (i = 0; i < k / 2; i++)		//右串逆序
	{
		tmp = *(src + len - k + i);
		*(src + len - k + i) = *(src + len - 1 - i);
		*(src + len - 1 - i) = tmp;
	}

	return src;
}

/* 
 * 判断一个字符串是否为另外一个字符串旋转之后的字符串。
 * 例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0.
 */
int is_string_move(char * left, char * right)
{
	int len1 = strlen(left);
	int len2 = strlen(right);
	int i = 0;
	assert(left);
	assert(right);
	for (i = 0; i < len1; i++)		//依次左移left串与right比较，循环len次后，刚好回到初始位置
	{
		if (0 == strcmp(left_move(left, 1), right))
			return 1;
	}
	for (i = 0; i < len1; i++)		//依次左移right串与left比较,相当于右移left串与right比较
	{
		if (0 == strcmp(left_move(left, 1), right))
			return 1;
	}
	return 0;
}
int is_string_move2(char * left, char * right)
{
	int len_left = strlen(left);
	int len_right = strlen(right);

	assert(left);
	assert(right);
	
	if (len_left != len_right)		//长度不等，必不存在
		return 0;

	strncat(left, left, len_left);		
	if (strstr(left, right) != NULL)
		return 1;
	else
		return 0;
}
int main()
{
	char arr[] = "aabcd";
	char arr2[20] = "abcda";
	//char *ret = left_move(arr, 2);

	if (is_string_move2(arr2, arr))
		printf("yes\n");
	else
		printf("no\n");

	//printf("%s\n", ret);
	system("pause");
	return 0;
}