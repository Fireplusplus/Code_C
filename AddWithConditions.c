/* 不用加减乘除做加法 */

#include <stdio.h>
#include <limits.h>

int state = 0; //0代表结果有效

int Add(int num1, int num2)
{
	long long sum = num1, carry;

	while (num2 != 0)
	{
		sum = num1 ^ num2;
		if (sum > INT_MAX || sum < INT_MIN)
		{
			state = -1;	//结果无效
			return -1;
		} 
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
		
	}
	
	return sum;
}

int main()
{
	printf("8 + 7 = %d\n", Add(8, 7));
	printf("0 + 7 = %d\n", Add(0, 7));
	printf("2 + 6 = %d\n", Add(2, 6));
	printf("-1 + 5 = %d\n", Add(-1, 5));

	return 0;
}
