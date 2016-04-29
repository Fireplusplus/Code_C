#include <stdio.h>
#include <assert.h>
#include <limits.h>

int my_atoi(const char *str)
{
	int flag = 1;
	long long ret = 0;

	assert(str);
	
	if ('\0' == *str)
		return 0;

	if ('-' == *str)
		flag = -1;
	if (('-' == *str) || ('+' == *str))
		str++;

	while ('\0' != *str)
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			ret = ret * 10 + flag * (*str - '0');	
			if (ret > INT_MAX)
			{
				ret = 0;	//溢出
				break;
			}	
		}
		else				//异常字符也作为结束标志
			break;

		str++;
	}
	
	return (int)ret;

}

int main()
{
	char *arr1 = NULL;
	char arr2[1] = {0};
	char arr3[] = "12345";
	char arr4[] = "12345678987654321";
	char arr5[] = "abc";
	char arr6[] = "123abc";

	//int ret1 = my_atoi(arr1);
	//printf("%d\n", ret1);
	//int ret2 = my_atoi(arr2);
	//printf("%d\n", ret2);
	int ret3 = my_atoi(arr3);
	printf("%d\n", ret3);
	int ret4 = my_atoi(arr4);
	printf("%d\n", ret4);
	int ret5 = my_atoi(arr5);
	printf("%d\n", ret5);
	int ret6 = my_atoi(arr6);
	printf("%d\n", ret6);

	return 0;
}
