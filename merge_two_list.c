/*
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增
 * 排序的。
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	struct ListNode *p_next;
}NODE, *PNODE;

PNODE merge_two_list_recur(PNODE head1, PNODE head2)
{
	PNODE new_head = NULL;

	if (NULL == head1)
		return head2;
	else if (NULL == head2)
		return head1;

	if (head1->val <= head2->val)
	{
		new_head = head1;
		new_head->p_next = merge_two_list_recur(head1->p_next,head2);
	}
	else
	{
		new_head = head2;
		new_head->p_next = merge_two_list_recur(head1, head2->p_next);
	}

	return new_head;
}

PNODE merge_two_list(PNODE head1, PNODE head2)
{
	PNODE new_head = NULL, tmp = NULL, next = NULL;
	int flag = 0;

	/*if (NULL == head1)
		return head2;
	else if (NULL == head2)
		return head1;
	*/

	while (NULL != head1 && NULL != head2)
	{
		if (head1->val <= head2->val)
		{
			tmp = head1;
			head1 = head1->p_next; 
		}
		else
		{
			tmp = head2;
			head2 = head2->p_next;
		}
		
		if (flag)	
		{
			next->p_next = tmp;
			next = next->p_next;
		}
		else			//只进来一次
		{
			new_head = tmp;
			next = new_head;
			flag = 1;
		}
	}
	
	if (NULL != head1)
	{
		next->p_next = head1;
	}

	else if (NULL != head2)
	{
		next->p_next = head2;
	}

	return new_head;
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

void test()
{

	PNODE p1 = (PNODE)malloc(sizeof(NODE));	
	PNODE p2 = (PNODE)malloc(sizeof(NODE));	
	PNODE p3 = (PNODE)malloc(sizeof(NODE));	
	
	PNODE p4 = (PNODE)malloc(sizeof(NODE));	
	PNODE p5 = (PNODE)malloc(sizeof(NODE));	
	PNODE p6 = (PNODE)malloc(sizeof(NODE));	
	PNODE p7 = (PNODE)malloc(sizeof(NODE));	
	
	PNODE ret = NULL;

	p1->val = 1;
	p1->p_next = p2;
	p2->val = 3;
	p2->p_next = p3;
	p3->val = 5;
	p3->p_next = NULL;
	
	p4->val = 2;
	p4->p_next = p5;
	p5->val = 4;
	p5->p_next = p6;
	p6->val = 6;
	p6->p_next = p7;
	p7->val = 8;
	p7->p_next = NULL;

	print_list(p1);	
	print_list(p4);	
	ret = merge_two_list(p1, p4);
	print_list(ret);
	distroy(ret);
}

int main()
{
	test();
	return 0;
}
