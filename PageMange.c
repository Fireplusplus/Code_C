/*
 * 在计算机中，页式虚拟存储器实现的一个难点是设计页面调度（置换）算法。
 * 其中一种实现方式是FIFO算法。
 * FIFO算法根据页面进入内存的时间先后选择淘汰页面，
 * 先进入内存的页面先淘汰，后进入内存的后淘汰。
 * 假设Cache的大小为2,有5个页面请求，分别为 2 1 2 3 1，
 * 则Cache的状态转换为：(2)->(2,1)->(2,1)->(1,3)->(1,3)，
 * 其中第1,2,4次缺页，总缺页次数为3。
 * 现在给出Cache的大小n和m个页面请求，请算出缺页数。
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int traverse(int *pCache, int cache, int request)
{
	while (cache--)
	{
		if (*pCache == request)
			return 1;
	}
	return 0;
}

void Insert(int *pCache, int cache, int page)
{
	int i = 0;
	for (i = 0; i < cache; i++)
	{
		if (0 == pCache[i])
			break;
	}
	if (i == cache)
	{
		memmove(pCache, pCache + 1, (cache - 1) * sizeof(int));
		pCache[cache - 1] = page;
	}
	else
	{
		pCache[i] = page;
	}
}

int TimesOfNoPage(int cache, int *request, int n)
{
	int *pCache = (int *)calloc(cache,  sizeof(int));
	int i, cnt = 0;

	if (NULL == pCache)
		exit(0);
	for (i = 0; i < n; i++)
	{
		if (!traverse(pCache, cache, request[i]))
		{	
			cnt++;
			Insert(pCache, cache, request[i]);
		}
	}
	free(pCache);
	pCache = NULL;
	return cnt;
}

int main()
{
	int request[] = {2, 1, 2, 3, 1};
	int cache = 2;
	int ret = TimesOfNoPage(cache, request, 5);

	printf("%d\n", ret);

	return 0;
}
