//查找第一次只出现一次的字符
#include <stdio.h>
#include <assert.h>

int find_first_appear_once(const char *str)
{
	char hash[128] = {0};
	char *tmp = (char *)str;
	assert(str);

	while ('\0' != *tmp)
	{
		hash[*tmp]++;
		tmp++;
	} 
	while ('\0' != *str)
	{
		if (1 == hash[*str])
		{
			break;	
		}
		else
			str++;
	}

	return *str;
}

int main()
{
	char arr[10] = "abcedabc";

	int ret = find_first_appear_once(arr);
	printf("%c\n", ret);
	
	return 0;
}
