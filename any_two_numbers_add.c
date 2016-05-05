/* 实现一个函数完成任意两个数的加法 */
#include <stdio.h>
#include <string.h>

void judge_carry(int *s, int *c)
{
	*c = 0;
	if (*s >= 10)
	{
		*c = 1;
		*s %= 10;
	}
	else if (*s < 0)
	{
		
		*c = -1;
		*s = 10 + (*s);
	}
}
void reverse(char *str1, char *str2)
{	
	char tmp = 0;
	while (str1 < str2)	
	{
		tmp = *str1;
		*str1 = *str2;
		*str2 = tmp;
		str1++;
		str2--;
	}
}

char *any_two_unsigned_nums_add_core(const char *elem1, int flag1, const char *elem2, int flag2, char *result)
{
	int carry = 0;
	int sum = 0;
	const char *e1 = elem1;
	const char *e2 = elem2;
	char *ret = result;

	if (('\0' == *elem1) || ('\0' == *elem2))
		return NULL;

	while ((*e1 >= '0') && (*e1 <= '9'))
		e1++;
	while ((*e2 >= '0') && (*e2 <= '9'))
		e2++;
	e1--;
	e2--;

	while ((e1 >= elem1) && (e2 >= elem2))
	{
		if (flag1 == flag2)
			sum = *e1 - '0' + *e2 - '0' + carry;
		else
			sum = flag1 * (*e1 - '0') + flag2 * (*e2 - '0') + carry;
		
		judge_carry(&sum, &carry);
		*result = sum + '0';
		e1--;
		e2--;
		result++;
	}
	while (e1 >= elem1)
	{
		sum = (*e1 - '0') + carry;
		
		*result = sum + '0';
		result++;
		e1--;
	}
	while (e2 >= elem2)
	{
		sum = (*e2 - '0') + carry;
		judge_carry(&sum, &carry);
		*result = sum + '0';
		result++;
		e2--;
	}
	if (1 == carry)		//还有进位
		*result++ = 1 + '0';
	if (flag1 * flag2 == -1)
		*result++ = '-';

	*result = '\0';

	return ret;
}

char *any_two_nums_add(const char *elem1, const char *elem2, char *result)
{
	int flag1 = 1;
	int flag2 = 1;
	char *ret = NULL;
	char *tmp =NULL;
	char *first = NULL;

	if (NULL == elem1 || elem2 == NULL)
		return NULL;
	if (('\0' == *elem1) || ('\0' == *elem2))
		return NULL;

	if ('-' == *elem1)
	{
		flag1 = -1;
		elem1++;
	}
	if ('+' == *elem1)
	{
		elem1++;
	}
	if ('-' == *elem2)
	{	
		flag2 = -1;	
		elem2++;
	}
	if ('+' == *elem2)
	{	
		elem2++;
	}

	if (((-1 == flag1) && (-1 == flag2)) || ((1 == flag1) && (1 == flag2)))
	{	
		ret = any_two_unsigned_nums_add_core(elem1, flag1, elem2, flag2, result);
		tmp = ret;

		if (flag1 == -1)
		{
			while (*tmp)
				tmp++;
			*tmp = '-';
			*(tmp + 1) = '\0';
		}
		reverse(ret, tmp);

		if (-1 == flag1)
			first = ret + 1;
	}
	else
	{
		ret = any_two_unsigned_nums_add_core(elem1, flag1, elem2, flag2, result);
		tmp = ret;
		while (*tmp)
			tmp++;
		reverse(ret, tmp - 1);
		first = ret + 1;
	}
	
	tmp = first;
	while (('0' == *(tmp + 1)) && ('0' == *tmp))
		tmp++;
	if (0 == *tmp)
		tmp++;
	if (*tmp > '0' && *tmp <= '9')
		memmove(first, tmp, strlen(tmp) + 1);
	else
		*(first + 1) = '\0';

	if (('-' == *ret) && ('0' == *(ret + 1)))
	{
		*ret = '0';
		*(ret + 1) = '\0';
	}
	return ret;
}

int main()
{
	char arr[20] = {0};

	char *ret = any_two_nums_add("-99999","-99999999", arr);
	
	if (ret)
		printf("%s\n", arr);
	else
		printf("输入不合法\n");
	return 0;
}
