#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char * my_strcpy(char * dest, const char * src)	//const使src不能做左值，防止while里dest和src写反
{
	char *ch = dest;
	assert(dest != NULL);						//断言帮助调试
	assert(src != NULL);
	while (*dest++ = *src++)					//while最简	
		;
	return dest;								//链式访问 printf("%s", my_strcpy(dest, src));
}

int main(void)
{
	char arr1[20];
	char arr2[] = "hello world!";
	//char *arr2 = NULL;

	my_strcpy(arr1, arr2);

	printf("%s", arr1);
	system("pause");
	return 0;
}
