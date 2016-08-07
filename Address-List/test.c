/* 顺序表实现通讯录管理系统 */
#define _CRT_SECURE_NO_WARNINGS

#include "AddressList.h"

void menu()
{
	printf("****************************\n");
	printf("*****   1.查找联系人   *****\n");
	printf("*****   2.添加联系人   *****\n");
	printf("*****   3.删除联系人   *****\n");
	printf("*****   4.显示所有人   *****\n");
	printf("*****   5.修改联系人   *****\n");
	printf("*****   6.清空电话簿   *****\n");
	printf("*****   0.  退出       *****\n");
	printf("****************************\n");
}
int main()
{
	int input = 1;

	PLIST p_list = init();
	sort(p_list);

	while (input)
	{	
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			search(p_list);
			break;
		case 2:
			insert(&p_list);
			sort(p_list);
			break;
		case 3:
			remv(p_list);
			break;
		case 4:
			print_list(p_list);
			printf("\n");
			break;
		case 5:
			update(p_list);
			break;
		case 6:
			empty(p_list);
			break;
		case 0:
			input = 0;
			save_to_file(p_list);
			break;
		default:
			break;
		}
	}

	distroy(p_list);
	system("pause");
	return 0;
}
