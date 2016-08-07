#define _CRT_SECURE_NO_WARNINGS

#include "AddressList.h"

PLIST init()
{
	PLIST p_list = (PLIST)malloc(sizeof(LIST));
	FILE *fp = fopen(INPUT_FILE, "r");

	p_list->p_data = (PMAN)malloc(INIT_SIZE * sizeof(MAN));
	p_list->size = INIT_SIZE;
	p_list->len = 0;
	if (NULL == p_list)
	{
		perror("申请内存");
		exit(EXIT_FAILURE);
	}

	if (NULL == fp)
	{
		perror("打开文件");
	}
	else
	{	
		PMAN tmp = p_list->p_data;
		while (fscanf(fp, "%s%s%d%s%s", tmp->name, tmp->sex,
			&(tmp->age), tmp->telephone, tmp->address) != EOF)
		{
			if (p_list->len >= p_list->size)
			{
				PLIST p_tmp = (PLIST)realloc(p_list, (p_list->size + INCREASE_SIZE) * sizeof(LIST));
				if (p_tmp != NULL)
				{
					p_list = p_tmp;
					p_list->size += INCREASE_SIZE;
				}
				else
				{
					printf("内存不足，仅初始化部分数据\n");
					break;
				}
				tmp = p_list->p_data + p_list->len;
			}
			(p_list->len)++;
			tmp++;
		}

		fclose(fp);
	}
	
	return p_list;
}

void distroy(PLIST p_list)
{
	if ((NULL != p_list) && (NULL != p_list->p_data))
	{
		free(p_list->p_data);
		p_list->p_data = NULL;
		free(p_list);
		p_list = NULL;
	}
}

void print_list(PLIST p_list)
{
	int len = 0;
	PMAN p_tmp = NULL;

	if ((NULL == p_list) || (NULL == p_list->p_data))
		return;
	if (p_list->len <= 0)
	{
		printf("电话簿为空\n");
		return;
	}
	len = p_list->len;
	p_tmp = p_list->p_data;

	printf("姓名\t性别\t年龄\t  电话\t\t   地址\n");
	while (len--)
	{
		printf("%-6s %4s\t%3d   %11s\t%s\n", p_tmp->name, p_tmp->sex,
			p_tmp->age, p_tmp->telephone, p_tmp->address);
		p_tmp++;
	}
}

static void print_man(PMAN p_man)
{
	if ((NULL == p_man))
		return;

	printf("姓名\t性别\t年龄\t  电话\t\t   地址\n");
	printf("%-6s %4s\t%3d   %11s\t%s\n", p_man->name, p_man->sex,
		p_man->age, p_man->telephone, p_man->address);
}

PMAN search(PLIST p_list)
{
	char name[NAME_MAX] = {0};
	int len_tmp = 0;
	PMAN p_data_tmp = NULL;

	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len <= 0)
	{
		printf("电话簿为空\n");
		return NULL;
	}

	printf("输入姓名：\n");
	scanf("%s", name);

	len_tmp = p_list->len;
	p_data_tmp = p_list->p_data;
	while (len_tmp--)
	{
		if (0 == strcmp(p_data_tmp->name, name))
		{
			print_man(p_data_tmp);
			return p_data_tmp;
		}
		else 
			p_data_tmp++;
	}
	printf("没有找到\n");
	return NULL;
}

void save_to_file(PLIST p_list)
{
	int len_tmp = 0;
	FILE *fp = NULL; 
	PMAN p_data_tmp = NULL;

	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len < 0)
		return;
	fp = fopen(INPUT_FILE, "w");
	if (NULL == fp)
	{
		perror("打开文件");
		exit(EXIT_FAILURE);
	}

	len_tmp = p_list->len;
	p_data_tmp = p_list->p_data;
	while (len_tmp--)
	{
		fprintf(fp, "%s %s %d %s %s", p_data_tmp->name, p_data_tmp->sex,
			p_data_tmp->age, p_data_tmp->telephone, p_data_tmp->address);
		if (len_tmp != 0)
			fprintf(fp, "\n");
		p_data_tmp++;
	}
	fclose(fp);
}

void insert(PLIST *p_list)
{
	int i = 0, len_tmp = 0;
	PMAN p_last = NULL;

	if ((NULL == p_list) || (NULL == (*p_list)) || (NULL == (*p_list)->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if ((*p_list)->len < 0)
		(*p_list)->len = 0;

	if ((*p_list)->len >= (*p_list)->size)
	{
		PLIST p_tmp = (PLIST)realloc((*p_list), ((*p_list)->size + INCREASE_SIZE) * sizeof(LIST));
		if (p_tmp != NULL)
		{
			(*p_list) = p_tmp;
			(*p_list)->size += INCREASE_SIZE;
		}
		else
		{
			printf("内存不足，无法继续添加\n");
			return;
		}
	}

	p_last = (*p_list)->p_data + (*p_list)->len;
	printf("请依次输入：姓名 性别 年龄 电话号码 地址:\n");
	scanf("%s%s%d%s%s", p_last->name, p_last->sex,
		&(p_last->age), p_last->telephone, p_last->address);
	((*p_list)->len)++;
}
void remv(PLIST p_list)
{
	PMAN p_man = NULL;

	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len <= 0)
	{
		printf("空电话簿\n");
		return;
	}

	p_man = search(p_list);
	if (NULL == p_man)
	{
		printf("没有此人\n");
		return;
	}
	p_man++;
	while (p_man < (p_list->p_data + p_list->len))
	{
		*(p_man - 1) = *p_man;
		p_man++;
	}
	(p_list->len)--;
}

void update(PLIST p_list)
{
	PMAN p_man = NULL;

	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len <= 0)
	{
		printf("空电话簿\n");
		return;
	}

	p_man = search(p_list);
	if (NULL == p_man)
	{
		printf("没有此人\n");
		return;
	}
	printf("请输入更新后的：性别 年龄 电话号码 地址:\n");
	scanf("%s%d%s%s", p_man->sex,
		&(p_man->age), p_man->telephone, p_man->address);
}

static int list_cmp(const void *elem1, const void *elem2)
{
	PMAN e1 = (PMAN)elem1;
	PMAN e2 = (PMAN)elem2;
	return strcmp(e1->name, e2->name);
}

void sort(PLIST p_list)
{
	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len < 0)
		p_list->len = 0;
	qsort(p_list->p_data, p_list->len, sizeof(MAN), list_cmp);
}

void empty(PLIST p_list)
{
	if ((NULL == p_list) || (NULL == p_list->p_data))
	{
		exit(EXIT_FAILURE);
	}
	if (p_list->len < 0)
		p_list->len = 0;

	p_list->len = 0;
}
