/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct BinaryTreeNode
{
	int value;
	struct BinaryTreeNode *pleft;
	struct BinaryTreeNode *pright;
}NODE, *PNODE;

int free_node(PNODE pnode)
{
	free(pnode);
	pnode = NULL;
	return OK;
}

int post_order_traverse(PNODE root, int (*visit)(PNODE pnode))
{
	if (root)
	{
		if(post_order_traverse(root->pleft, visit))
		{
			if (post_order_traverse(root->pright, visit))
				visit(root);
		}
		else
			return ERROR;
	}
	
	return OK;
}

int print(PNODE pnode)
{
	printf("%d ", pnode->value);
	return OK;
}

int pre_order_traverse(PNODE root, int (*visit)(PNODE pnode))
{
	if (root)
	{
		if (visit(root))
		{
			if (pre_order_traverse(root->pleft, visit))
			{
				if(pre_order_traverse(root->pright, visit))
					return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

PNODE  ConstructCore(int *pre_start, int *pre_end, 
				int *ino_start, int *ino_end)
{
	//前序遍历第一个数字是根结点的值
	int root_val = pre_start[0];
	PNODE root = (PNODE)malloc(sizeof(NODE));
	root->value = root_val;
	root->pleft = root->pright = NULL;

	if (pre_start == pre_end)
	{
		if (ino_start == ino_end && *pre_start == *ino_start)
			return root;
		else
			exit(1);	//输入有误
	}
	
	//在中序遍历中找到根结点的值

	int *ino_root = ino_start;
	while (ino_root <= ino_end && *ino_root != root_val)
		ino_root++;

	if (ino_root == ino_end && *ino_root != root_val)
		exit(1);		//输入有误
	
	int len_left = ino_root - ino_start;
	int *pre_end_left = pre_start + len_left;	//跳过最开始的根结点
	if (len_left > 0)
	{
		//构建左子树
		root->pleft = ConstructCore(pre_start + 1, pre_end_left, 
					ino_start, ino_root - 1);
	}
	if (len_left < pre_end - pre_start)
	{	
		//构建右子树
		root->pright = ConstructCore(pre_end_left + 1, pre_end, 
					ino_root + 1, ino_end);
	}

	return root;
}

PNODE Construct(int *preorder, int *inorder, int len)
{
	if (preorder == NULL || inorder == NULL || len <= 0)
		return NULL;
	
	return ConstructCore(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

int main()
{
	int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int ino[] = {4, 7, 2, 1, 5, 3, 8, 6};
	
	PNODE tree = Construct(pre, ino, 8);
	pre_order_traverse(tree, print);
	printf("\n");
	
	post_order_traverse(tree, free_node);

	return 0;
}
