/* 输入一个字符串，将字符串的小写字放在大写字母前面，保持字符相对顺序不变 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Move(char *str)
{
	char *left = str, *right;
	int len;
	char tmp;
	if (NULL == str)
		return NULL;

	len = strlen(str);
	right = str + len - 1;
	
	while (left < right)
	{
		while (*left < 'z' && *left > 'a')		//让left指向大写字母
			left++;
		while (*right < 'Z' && *right > 'A')	//让right指向小写字母
			right--;
		tmp = *left;
		memmove(left, left + 1, (right - left) * sizeof(char));
		*right = tmp;
	}
}

int main()
{
	char arr[] = "AkleBiCeilD";
	Move(arr);
	printf(arr);

	return 0;
}