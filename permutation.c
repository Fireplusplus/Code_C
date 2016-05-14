#include <stdio.h>
#include <string.h>

void Swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void permutation_core(char *str, char *head)
{
	int i = 0, len = 0;

	if ('\0' == *str)
	{
		printf("%s\n", head);
		return;
	}

	len = strlen(str);
	
	while (i < len)
	{
		Swap(str, str + i);
		permutation_core(str + 1, head);
		Swap(str, str + i);
		i++;
	}
}

void permutation(char *str)
{
	if (NULL == str)
		return;
	permutation_core(str, str);
}

int main()
{
	char arr[] = "abc";

	permutation(arr);
	return 0;
}
