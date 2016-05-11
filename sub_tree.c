/* 输入两棵二叉树A和B，判断B是不是A的子结构 */
#include <stdio.h>

typedef struct BinaryTreeNode
{
	int	value;
	struct BinaryTreeNode	*pLeft;
	struct BinaryTreeNode	*pRight;
}BT, *PBT;

int does_tree1_has_tree2(PBT pa, PBT pb)
{
	if (NULL == pb)
		return 1;
	if (NULL == pa)
		return 0;
	if (pa->value != pb->value)
		return 0;

	return does_tree1_has_tree2(pa->pLeft, pb->pLeft) && does_tree1_has_tree2(pa->pRight, pb->pRight);

}

int sub_tree(PBT pa, PBT pb)
{
	int ret = 0;	//不存在

	if (NULL != pa && NULL != pb)
	{
		if (pa->value == pb->value)
		{
			ret = does_tree1_has_tree2(pa, pb);
		}
		if (!ret)
		{
			ret = sub_tree(pa->pLeft, pb);
		}
		if (!ret)
		{
			ret = sub_tree(pa->pRight, pb);
		}
	}

	return ret;
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
	PBT root_a = NULL;
	PBT root_b = NULL;

	BT p1 = {8, NULL, NULL};
	BT p2 = {8, NULL, NULL};
	BT p3 = {7, NULL, NULL};
	BT p4 = {9, NULL, NULL};
	BT p5 = {2, NULL, NULL};

	BT p6 = {8, NULL, NULL};
	BT p7 = {9, NULL, NULL};
	BT p8 = {1, NULL, NULL};
	
	root_a = &p1;
	root_a->pLeft = &p2;
	root_a->pRight = &p3;
	root_a->pLeft->pLeft = &p4;
	root_a->pLeft->pRight = &p5;

	root_b = &p6;
	root_b->pLeft = &p7;
	root_b->pRight = &p8;

	pre_traverse(root_a);
	printf("\n");
	pre_traverse(root_b);
	printf("\n");

	if(sub_tree(root_a, root_b))
		printf("exist\n");
	else
		printf("not exist\n");

}

int main()
{

	test();

	return 0;
}
