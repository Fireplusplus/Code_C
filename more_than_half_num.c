/* 查找数组中出现次数超过一半的数字 */
#include <stdio.h>

void swap(int *elem1, int *elem2)
{
	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}
//快速排序中的parition函数
int parition(int *data, int len, int start, int end)
{
	int small = 0;
	int index = 0;
	if (NULL == data || len <= end - start || start < 0 || end >= len)
		return -1;
	
	index = (end - start) / 2 + start;
	swap(&data[index], &data[end]);
	
	small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{		
			small++;
			if (small != index)
				swap(&data[index], &data[small]);
		}
	}
	 
	small++;
	swap(&data[small], &data[end]);
	
	return small;
}

int more_than_half_num(int data[], int len)
{
	int i = 0; 
	int index = 0;
	int cnt = 0;
	int mid = 0;
	int start = 0;
	int end = len - 1;
	if (NULL == data || len <= 0)
		return -1;
	
	mid = len >> 1;
	index = parition(data, len, 0, len - 1);
	while (index != mid)
	{
		if (index > mid)
		{	
			end = index - 1;
			index = parition(data, len, start, end);
		}
		else
		{
			start = index + 1;
			index = parition(data, len, start, end);
		}
	}

	for (i = 0; i < len; i++)
	{
		if (data[i] == data[index])
			cnt++;
	}
	if (cnt > mid)		//存在出现次数超过一半的数
		return index;
	else
		return -1;
}

int main()


{
	int test1[] = {1, 2, 3, 2, 3};	//not exist
	int test2[] = {0};		//0
	int *test3 = NULL;		//not exist
	int *test4;			//not exist
	int test5[] = {1, 2, 1, 2, 2};	//2
	int test6[5] = {0};		//0 

	int ret1 = more_than_half_num(test1, 5);
	int ret2 = more_than_half_num(test2, 1);
	int ret3 = more_than_half_num(test3, 0);
	int ret4 = more_than_half_num(test4, 0);
	int ret5 = more_than_half_num(test5, 5);
	int ret6 = more_than_half_num(test6, 5);
	
	printf("not exist ? %d\n", ret1);
	printf("0 ? %d\n", test2[ret2]);
	printf("not exist ? %d\n", ret3);
	printf("not exist ? %d\n", ret4);
	printf("2 ? %d\n",test5[ret5]);
	printf("0 ? %d\n", test6[ret6]);

	return 0;
}
