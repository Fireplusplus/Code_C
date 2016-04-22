#include <stdio.h>
#include <stdlib.h>

#define N 1000

/*
* 插入排序---非递减
* 认为数组中第一张牌是已经排好序的
*/
void insert_sort(int *a, int num)
{
	int tmp = 0;				//从牌堆摸一张牌临时存放
	int i = 0, j = 0;

	for (i = 1; i < num; i++) {
		tmp = a[i];
		j = i - 1;
		while ((tmp<a[j]) && (j >= 0)) {
			a[j + 1] = a[j];	//将较大牌后移	
			j--;
		}
		a[j + 1] = tmp;		//将摸出来的牌放入正确的位置
	}
}
int main(void)
{
	int arr[N] = { 0 };
	int i = 0, data = 1000;

	/*初始化待排数组*/
	for (i = 0; i < N; i++){
		arr[i] = data--;
	}

	/*调用统一接口*/
	insert_sort(arr, N);

	/*打印到屏幕*/
	for (i = 0; i < 1000; i++){
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
