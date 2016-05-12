/* 完成一个函数，输入一个二叉树，该函数输出它的镜像 */
#include <stdio.h>

typedef struct BinaryTreeNode
{
	int	value;
	struct BinaryTreeNode	*pLeft;
	struct BinaryTreeNode	*pRight;
}BT, *PBT;

void BinaryTreeMirroring(PBT root)
{
	if (NULL == root)
		return;
	else
	{
		PBT tmp = root->pLeft;
		root->pLeft = root->pRight;
		root->pRight = tmp;
		BinaryTreeMirroring(root->pLeft);
		BinaryTreeMirroring(root->pRight);
	}
}


int pre_traverse(PBT root)
{
	if (NULL != root)
	{
		printf("%d ", root->value);
		pre_traverse(root->pLeft);
		pre_traverse(root->pRight);
	}
}

void test()
{
	PBT root = NULL;

	BT p1 = {8, NULL, NULL};
	BT p2 = {8, NULL, NULL};
	BT p3 = {7, NULL, NULL};
	BT p4 = {9, NULL, NULL};
	BT p5 = {2, NULL, NULL};

	root = &p1;
	root->pLeft = &p2;
	root->pRight = &p3;
	root->pLeft->pLeft = &p4;
	root->pLeft->pRight = &p5;

	pre_traverse(root);
	BinaryTreeMirroring(root);
	printf("\n");
	pre_traverse(root);
}

int main()
{

	test();

	return 0;
}
