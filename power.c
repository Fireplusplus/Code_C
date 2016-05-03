#include <stdio.h>

/*
double power(double base, int exponent)
{
	double result = 1.0;
	int i = 0;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}

	return result;
}

*/
//0, -1 //-1 0 // 0 0

int invalid_input = 0;		//1代表输入不合法，0代表合法

int equal(double elem1, double elem2)
{
	if ((elem1 - elem2 < 0.0000001) && (elem1 - elem2 > -0.0000001))
		return 1;	//相等
	else
		return 0;	//不相等
}

double power_unsigned_exp(double base, unsigned int exponent)
{
	double result = 0.0;
	
	if (0 == exponent)
		return 1.0;
	if (1 == exponent)
		return base;

	result = power_unsigned_exp(base, exponent / 2);
	if (exponent & 1 == 1)
		result *= base;
	
	return result;
}

double power(double base, int exponent)
{
	unsigned int abs_exponent = exponent;
	double result = 0.0;
	invalid_input = 0;
	
	if (equal(base, 0.0) && exponent < 0)
	{
		invalid_input = 1;
		return 0.0;
	}

	if (exponent < 0)
		abs_exponent = (unsigned int)(-exponent);
	
	result = power_unsigned_exp(base, abs_exponent >> 1);
	result *= result;

	if (result < 0)
		result = 1.0 / result;
	
	return result;
}

int main()
{
	double ret = power(0, -1);
	if (invalid_input == 1)
		printf("invalid input\n");
	else
		printf("%lf\n", ret);

	ret = power(-1, 0);
	if (invalid_input == 1)
		printf("invalid input\n");
	else
		printf("%lf\n", ret);

	ret = power(0, 0);
	if (invalid_input == 1)
		printf("invalid input\n");
	else
		printf("%lf\n", ret);

	ret = power(2.0, 3);
	if (invalid_input == 1)
		printf("invalid input\n");
	else
		printf("%lf\n", ret);

	return 0;
}
