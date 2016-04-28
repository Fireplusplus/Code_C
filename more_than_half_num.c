/* 查找数组中出现次数超过一半的数字 */
#include <stdio.h>

void swap(int *elem1, int *elem2)
{
	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}
//快速排序中的parition函数
int partition(int *data, int len, int start, int end)
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
/* 
 * 数组中有一个数字出现的次数超过了数组长度的一半。如果把这个数组排序，
 * 那么排序后位于数组中间的数字一定就是那个出现次数超过数组长度一半的数字。也就是说，这个数字就是统计学上的中位数，
 * 即长度为n的数组中第n/2大的数字。我们有成熟的O（n）的算法得到数组中任意地k大的数字，这种算法是受快排启发。
 * 在快速排序算法中，我们先在数组中选一个数字，然后调整数组中数字的顺序，使得比选中的数字小的数字都排在它的左边，
 * 比选中的数字大的数字都排在它的右边。如果选中的数字的下标（调整后的）刚好是n/2，那么这个数字就是中位数。
 * 如果它的下标大于n/2，那么中位数应该位于它的左边，我们可以接着在左边部分的数组中查找。如果下标小于n/2，
 * 那么中位数应该位于它的右边，我们可以接着在它的右边部分的数组中查找。这是一个典型的递归过程
 */
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
	index = partition(data, len, 0, len - 1);
	while (index != mid)
	{
		if (index > mid)
		{	
			end = index - 1;
			index = partition(data, len, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(data, len, start, end);
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

/*
 * 数组中有一个数字出现的次数超过数组长度的一半，也就是说它出现的次数比其它所有数字出现的次数和还多，
 * 因此可以考虑在遍历数组的时候保存两个值：一个是数组中的一个数子，一个是次数。当我们遍历到下一个数字的时候，
 * 如果下一个数字和我们之前保存的数字相同，则次数+1，如果不同，则次数-1.如果次数为0，我们需要保存下一个数字，
 * 并把次数设为2.由于我们要找的数字出现的次数比其它所有数字出现的次数和还要多，
 * 那么要找的数字肯定是最后一次把次数设为1时对应的数字
 */
int more_than_half_num_2(int data[], int len)
{
	int i = 0;
	int result = 0;
	int cnt = 1;
	if (data == NULL || len <= 0)
		return -1;


	for (i = 1; i < len; i++)
	{
		if (0 == cnt)
		{
			result = i;
			cnt = 1;
		}
		else if (data[i] == data[result])
			cnt++;
		else
			cnt--;
	}

	for (i = 0; i < len; i++)
	{
		if (data[i] == data[result])
			cnt++;
	}
	if (cnt > len / 2)
		return result;
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

/*	int ret1 = more_than_half_num(test1, 5);
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
*/
	int ret1 = more_than_half_num_2(test1, 5);
	int ret2 = more_than_half_num_2(test2, 1);
	int ret3 = more_than_half_num_2(test3, 0);
	int ret4 = more_than_half_num_2(test4, 0);
	int ret5 = more_than_half_num_2(test5, 5);
	int ret6 = more_than_half_num_2(test6, 5);

	printf("\n");
	printf("not exist ? %d\n", ret1);
	printf("0 ? %d\n", test2[ret2]);
	printf("not exist ? %d\n", ret3);
	printf("not exist ? %d\n", ret4);
	printf("2 ? %d\n",test5[ret5]);
	printf("0 ? %d\n", test6[ret6]);
	return 0;
}
