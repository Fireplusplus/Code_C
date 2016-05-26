#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdarg.h>
using namespace std;

bool state = false;
int Sum(int val, ...)
{
	int n = val;

	if (val <= 0)
		return 0;

	va_list arg;
	va_start(arg, val);

	int sum = 0;
	while (n--)
	{
		sum += va_arg(arg, int);
	}

	return sum;
}

int main()
{
	int ret = Sum(3, 1, 2, 3);

	return 0;
}