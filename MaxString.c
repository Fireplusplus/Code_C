/* 
 * 有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。
 * 现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。
 * 这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且
 * 它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的
 * 整数之和最大？
 * 输入描述:
 * 每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 
 * 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 
 * n 不大于 50，且至少存在一个字符不是任何字符串的首字母。
 * 输出描述:
 * 输出一个数，表示最大和是多少。
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int sum;
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

int StrToNum(char *str)
{
    int s = 0;
    int len = strlen(str);
    char *tail = str + len - 1;
    
    while (tail >= str)
    {
    	s = s * 10 + arr[*tail - 'A'];
        tail--;
    }
    return s;
}

void Sum(char **p, int n)
{
    int i = 0;
    int s = 0;
    while (i < n)
    {
        if (0 == arr[(**(p + i) - 'A')])
            return;
	i++;
    }
    i = 0;
    while (i < n)
    {
        s += StrToNum(*(p+i));
  	i++;
    }
    if (s > sum)
        sum = s;               
}

void permutation(int cur, int num, char **p, int n)
{
    int i;

    if (cur == num - 1)
    {
    	Sum(p, n);
	return;
    }
    
    for (i = cur; i < num; i++)
    {
        swap(&arr[cur], &arr[i]);
        permutation(cur + 1, num, p, n);
        swap(&arr[cur], &arr[i]); 
    }
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    char **p = (char **)malloc(n * sizeof(char **));
    if (NULL == p)
        return -1;
    tmp = 0;
    while (tmp < n)
    {
        *(p + tmp) = (char *)malloc(13 * sizeof(char));
        scanf("%s", *(p + tmp));
	tmp++;
    }
    permutation(0, 10, p, n);
    printf("%d\n", sum);
    
    while(n--)
    	free(*(p+n));
    free(p);
    
    return 0;
}
