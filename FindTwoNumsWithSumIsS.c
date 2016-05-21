/* 
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，
 * 使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对
*/

#include <stdio.h>

typedef struct result
{
	int flag;
	int index1;
	int index2;
}RESULT;

struct result FindTwoNumsWithSumIsS(int *arr, int size, int s)
{
	int left = 0, right = size - 1;
	RESULT rs;

	rs.flag = 0;		//0代表无效
	if (NULL == arr || size <= 0)
		return rs;
	
	while (left < right)
	{
		long long sum = arr[left] + arr[right];

		if (sum > s)
			--right;
		else if (sum < s)
			++left;
		else
		{
			rs.index1 = left;
			rs.index2 = right;
			rs.flag = 1;
			return rs;
		}
	}
	return rs;
}


int main()
{
	int arr[] = {1, 2, 4, 7, 11, 15};
	
	RESULT ret = FindTwoNumsWithSumIsS(arr, 6, 15);
	if (1 == ret.flag)
		printf("%d %d\n", arr[ret.index1], arr[ret.index2]);
	else 
		printf("Not Exist!\n");


	return 0;
}
