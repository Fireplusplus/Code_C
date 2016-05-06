/* 给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点 */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
	int val;
	struct ListNode *p_next;
}NODE, *PNODE;

void delete_node(PNODE *pListHead, PNODE pToDeleted)
{
	//假设前提：链表中存在pToDeleted这个结点
	if ((NULL == pListHead) || (NULL == *pListHead) || (NULL == pToDeleted))	//待删结点是头指针
		return;

	if ((*pListHead)->val == pToDeleted->val)
	{
		PNODE tmp = *pListHead;
		*pListHead = tmp->p_next;
		free(tmp);
		tmp = NULL;
	}
	else if (NULL != pToDeleted->p_next && (*pListHead)->val != pToDeleted->val)	//待删结点不是尾指针也不是头指针
	{
		PNODE next = pToDeleted->p_next;
		pToDeleted->val = next->val;
		pToDeleted->p_next = next->p_next;
		free(next);
		next = NULL;
	}
	else										//是尾指针但不是头指针，需要遍历整个链表
	{
		PNODE tmp = *pListHead;

		while (tmp->p_next->val != pToDeleted->val)
		{
			tmp = tmp->p_next;
		}
		free(pToDeleted);
		pToDeleted = NULL;
		tmp->p_next = NULL;
	}
}

void print(PNODE head)
{
	while (NULL != head)
	{
		printf("%d ", head->val);
		head = head->p_next;
	}
	printf("\n");
}
int main()
{
	PNODE p1, p2, p3;
	PNODE head = NULL;
	
	p1 = (PNODE)malloc(sizeof(NODE));
	p2 = (PNODE)malloc(sizeof(NODE));
	p3 = (PNODE)malloc(sizeof(NODE));

	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p1->p_next = p2;
	p2->p_next = p3;
	p3->p_next = NULL;
	
	head = p1;

	print(head);
	delete_node(&head, p1);
	print(head);
	delete_node(&head, p3);
	print(head);
	delete_node(&head, p2);

}
