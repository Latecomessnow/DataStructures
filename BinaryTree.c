#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"


BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->left = newnode->right = NULL;
	newnode->data = x;
	return newnode;
}

//手搓一棵二叉树,返回根节点
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	//BTNode* node5 = BuyNode(5);
	//BTNode* node6 = BuyNode(6);
	//BTNode* node7 = BuyNode(7);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	//node3->right = node7;
	//node4->left = node5;
	//node4->right = node6;
	return node1;
}

//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//方法1---全局变量计数，每次使用前需要置空
int count = 0;
void TreeSize1(BTNode* root)
{
	if (root == NULL)
		return;
	count++;
	TreeSize1(root->left);
	TreeSize1(root->right);
}

//方法2---分治思想
int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

//计算叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//计算第k层节点数
int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->left, k - 1) 
		+ TreeKLevel(root->right, k - 1);
}

//找到值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//继续往下左右子树去找
	//创建一个指针接受返回值，这样的好处是如果找到了就能够返回了，不用继续递归查找
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	//左子树找不到，再去右子树去找
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	return NULL;
}

int TreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = TreeDepth(root->left) + 1;
	int right = TreeDepth(root->right) + 1;
	return left > right ? left : right;
}

//后序遍历销毁二叉树
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//root不为空直接入队
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);
		//依次把第二层、第三层...左右孩子入队
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
}

//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		printf("%d ", front->data);
//		QueuePop(&q);
//		if (front->left)
//			QueuePush(&q, front->left);
//		if (front->right)
//			QueuePush(&q, front->right);
//	}
//	printf("\n");
//}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//取队头数据，队头不为空则左右孩子无论是否为空都push队列中
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		//如果遇到第一个空则跳出循环
		//完全二叉树第一个空后边都是空，若空后边不全为空则不是完全二叉树
		else
		{
			break;
		}
	}
	while (!QueueEmpty(&q))
	{
		//取出队列中空后边的节点指针，如果存在非空，直接返回false
		BTNode* front = QueueFront(&q);
		//取出后pop更新队头
		QueuePop(&q);
		if (front)
		{
			//返回前需要销毁队列以防内存泄露
			QueueDestroy(&q);
			return false;
		}
	}
	//如果到这还没有返回，那么就是true
	//该函数中有push，需要进行队列的销毁再返回，否则会有内存泄漏
	QueueDestroy(&q);
	return true;
}

//bool BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front)
//		{
//			QueuePush(&q, front->left);
//			QueuePush(&q, front->right);
//		}
//		else
//			break;
//	}
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front)
//		{
//			QueueDestroy(&q);
//			return false;
//		}
//	}
//	QueueDestroy(&q);
//	return true;
//}