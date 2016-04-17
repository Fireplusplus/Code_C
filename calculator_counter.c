/* 
 * 使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，
 * 第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，
 * “-d”选项执行除法，后面两个参数为操作数 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int dev(int x, int y)
{
	return x / y;
}

int main(int argc, char * argv[])
{
	int ret = 0;
	int x = (*argv[2] - '0');
	int y = (*argv[3] - '0');

	if (argc != 4)
		exit(0);
	
	if (strcmp(argv[1], "-a") == 0)
		ret = add(x, y);
	else if (strcmp(argv[1], "-s") == 0)
		ret = sub(x, y);
	else if (strcmp(argv[1], "-m") == 0)
		ret = mul(x, y);
	else if (strcmp(argv[1], "-d") == 0)
		ret = dev(x, y);
	else
		exit(0);
	printf("%d\n", ret);

	return 0;
}