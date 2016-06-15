/* 
 * 给定一个递增序列，a1 <a2 <...<an 。定义这个序列的最大间隔为
 * d=max{ai+1 - ai }(1≤i<n),现在要从a2 ,a3 ..an-1 中删除一个元素。
 * 问剩余序列的最大间隔最小是多少 
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//删除一个数后最大间隔的最小间隔应为删除前所有间隔中的最小值
int MinNum(int arr[], int n)
{
    int *p;
    int i, min = MAX_INT;
    if (NULL == arr || n <= 1)
        return -1;
    
    p = (int *)malloc((n - 1) * sizeof(int));
    
    for (i = 0; i < n - 1; i++)
    {
        p[i] = arr[i + 1] - arr[i];		//最大间隔
		
        if (min > p[i])
        	min = p[i];
    }
    
    free(p);
    
	return min;
}


int main()
{
    int n, i;
    int *arr;
    int ret;
    
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
	ret = MinNum(arr, n);
    printf("%d\n", ret);
    
    free(arr);
    return 0;
}
