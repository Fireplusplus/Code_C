#ifndef ADDRESS_LIST_H
#define ADDRESS_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "list.txt"
#define INIT_SIZE 30
#define INCREASE_SIZE 10
#define MAX_SIZE 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELEPHONE_MAX 12
#define	ADDRESS_MAX 36


typedef struct man
{
	int age;
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char telephone[TELEPHONE_MAX];
	char address[ADDRESS_MAX];
}MAN, *PMAN;

typedef struct list
{
	int len;				//人数
	int size;				//容量
	PMAN p_data;			//数据
}LIST, *PLIST;



//初始化
PLIST init();		
//销毁
void distroy(PLIST p_list);
//输出至屏幕
void print_list(PLIST p_list);
//按名字查找联系人
PMAN search(PLIST p_list);
//添加新联系人
void insert(PLIST *p_list);
//按名字删除联系人
void remv(PLIST p_list);
//按名字修改联系人
void update(PLIST p_list);
//按名字排序
void sort(PLIST p_list);
//清空
void empty(PLIST p_list);
//保存至文件
void save_to_file(PLIST p_list);


#endif // !ADDRESS_LIST_H
