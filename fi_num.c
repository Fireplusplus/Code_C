#include <stdio.h>

/*long long fi_num(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	return fi_num(n - 1) + fi_num(n - 2);
}*/

long long fi_num(unsigned int n)
{
	long long num1 = 1, num2 = 1, num3 = 1;
	int i = 0;

	if (n == 0)
		return 0;

	for (i = 2; i < n; i++)
	{
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
	}
	
	return num3;
}

int main()
{
	int ret = fi_num(5);

	printf("%d\n", ret);

	return 0;
}
