/* 
 * 给定一组英文单词，确定是否可以将这些单词排列在一个列表中，
 * 使得该列表中任何单词的首字母与前一单词的首字母相同 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *word[], int n)
{
	char *head = (char *)malloc(n * sizeof(char));
	char *tail = (char *)malloc(n * sizeof(char));
	int i = 0;
	char **p = word;

	for (i = 0; i < n; i++)
	{
		head[i] = **p;
		while ('\0' != **p)
			(*p)++;
		(*p)--;
		tail[i] = **p;
		p++;
	}
	tail[n - 1] = '\0';
	if (0 == strcmp(head + 1, tail))
	{
		free(head);
		free(tail);
		return 1;
	}
	else
	{
		free(head);
		free(tail);
		return 0;
	}
}

void Swap(char **c1, char **c2)
{
	char *tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int CanConnet(char *word[],char *word_cur[], int n, int cur)
{
	int i = 0;

	if (NULL == word)
		return -1;
	if (1 == cur)
	{	
		return judge(word, n);	
	}
	
	while (i < cur)
	{
		int ret;
		Swap(&word_cur[0], &word_cur[i]);
		ret = CanConnet(word, word + 1, n, cur - 1);
		Swap(&word_cur[0], &word_cur[i]);
		if (1 == ret)
			return 1;
		i++;
	}
	return 0;
}

 int main()
 {
 	char *arr[] = {"abck", "kbcd", "dab"};

	int ret = CanConnet(arr, arr, 3, 3);
	if (1 == ret)
		printf("yes\n");
	else
		printf("no\n");
 
 	return 0;
 }
