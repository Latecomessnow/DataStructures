#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

extern int count;

void TestOrder()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
}

void TestLeafSize()
{
	BTNode* root = CreatBinaryTree();
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));

}

void TestTreeFind()
{
	BTNode* root = CreatBinaryTree();
	BTNode* ret = TreeFind(root, 2);
	if (ret)
	{
		printf("找到了，值为%d\n", ret->data);
	}
	else
	{
		printf("找不到\n");
	}
}

void TestTreeDepth()
{
	BTNode* root = CreatBinaryTree();
	printf("TreeDepth:%d\n", TreeDepth(root));
}


void TestBinaryTreeComplete()
{
	BTNode* root = CreatBinaryTree();
	if (BinaryTreeComplete(root))
		printf("yes\n");
	else
		printf("no\n");

}

int main()
{
	//TestOrder();
	//count = 0;
	BTNode* root = CreatBinaryTree();
	//count = 0;
	//TreeSize1(root);
	//printf("TreeSize:%d\n", count);
	//count = 0;
	//TreeSize1(root);
	//printf("TreeSize:%d\n", count);
	printf("TreeSize:%d\n", TreeSize2(root));
	TestLeafSize();
	printf("TreeKLevel:%d\n", TreeKLevel(root, 3));
	TestTreeFind();
	TestTreeDepth();
	LevelOrder(root);
	TestBinaryTreeComplete();
	return 0;
}