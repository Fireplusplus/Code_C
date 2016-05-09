/*
 * 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	struct ListNode *p_next;
}NODE, *PNODE;

PNODE reverse_list_recur(PNODE head)
{
	if (NULL == head || NULL == head->p_next)
		return head;
	else
	{
		PNODE new_head = reverse_list_recur(head->p_next);
		head->p_next->p_next = head;
		head->p_next = NULL;
		
		return new_head;
	}
}

PNODE reverse_list(PNODE head)
{
	PNODE first = NULL, second = NULL, precur = NULL;

	assert(head);
	
	first = head;
	while (NULL != first)
	{
		second = first->p_next;
		if (NULL == second)
			head = first;
		first->p_next = precur;
		precur = first;
		first = second;
	}
	return head;
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

void print_list(PNODE head)
{
	while (NULL != head)
	{
		printf("%d ", head->val);
		head= head->p_next;
	}
	printf("\n");
}

int main()
{
	PNODE p1 = (PNODE)malloc(sizeof(NODE));	
	PNODE p2 = (PNODE)malloc(sizeof(NODE));	
	PNODE p3 = (PNODE)malloc(sizeof(NODE));	
	PNODE ret = NULL;

	p1->val = 1;
	p1->p_next = p2;
	p2->val = 2;
	p2->p_next = p3;
	p3->val = 3;
	p3->p_next = NULL;

	print_list(p1);	
	p1 = reverse_list_recur(p1);
	print_list(p1);

	distroy(p1);
	return 0;
}
