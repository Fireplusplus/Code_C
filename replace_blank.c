#include <stdio.h>
#include <assert.h>
#include <string.h>

//将字符串中的空格替换为%20
void replace_blank(char *str)
{
	int cnt = 0;
	int len = strlen(str);
	char *left = NULL;
	char *right = NULL;

	assert(str);

	left = str + len;

	while (*str != 0)
	{
		if (' ' == *str)
			cnt++;
		str++;
	}
	if (cnt < 0)
		return;
	right = left + cnt*2;

	while (left < right)
	{
		if (' ' !=  *left)
		{
			*right-- = *left--;
		}
		else
		{
			*right-- = '0';
			*right-- = '2';
			*right-- = '%';
			left--;
		}
	}

}

int main()
{
	char arr[] = "we are happy";
	replace_blank(arr);

	printf("%s\n", arr);
	return 0; 
}
