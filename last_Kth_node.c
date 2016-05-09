/*
 * 输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1
 * 开始计数，即链表的尾结点是倒数第一个结点。
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	struct ListNode *p_next;
}NODE, *PNODE;

/*PNODE find_Kth_to_tail(PNODE head, int k)
{
	static int cnt = 0;
	static int flag = 0;
	
	PNODE ret = NULL;
	//assert(head);
	
	if (NULL == head)
		return NULL;
	if (k <= 0)
		return NULL;

	if (NULL == head->p_next)
	{
		cnt++;
		flag = 1;
		if (cnt == k)
			return head;
		else
			return NULL;
	}
	ret = find_last_Kth(head->p_next, k);
	if (NULL != ret)
		return ret;

	if (1 == flag)
	{
		cnt++;
		if (cnt == k)
			return head;
		else
			return NULL;
	}
	
}*/

PNODE find_Kth_to_tail(PNODE head, int k)
{
	PNODE left = NULL;
	PNODE right = NULL;
	int i = 0;

	assert(head);
	
	if (k <= 0)
		return NULL;

	left = right = head;

	for (i = 0; (i < k-1) && (NULL != right->p_next); i++)
	{
		right = right->p_next;;
	}
	if (i != k-1)
		return NULL;
	while (NULL != right->p_next)
	{
		left = left->p_next;
		right = right->p_next;
	}
	
	return left;
}

void distroy(PNODE head)
{
	PNODE tmp = NULL;

	while (NULL != head)
	{
		tmp = head;
		head = head->p_next;
		free(tmp);
	}
}

int main()
{
	PNODE p1 = (PNODE)malloc(sizeof(NODE));	
	PNODE p2 = (PNODE)malloc(sizeof(NODE));	
	PNODE p3 = (PNODE)malloc(sizeof(NODE));	
	PNODE p4 = (PNODE)malloc(sizeof(NODE));	
	PNODE ret = NULL;

	p1->val = 1;
	p1->p_next = p2;
	p2->val = 2;
	p2->p_next = p3;
	p3->val = 3;
	p3->p_next = p4;
	p4->val = 4;
	p4->p_next = NULL;

	ret = find_Kth_to_tail(p1, 5);
	if (ret)
		printf("%d\n", ret->val);
	else
		printf("没找到\n");

	distroy(p1);
	return 0;
}
