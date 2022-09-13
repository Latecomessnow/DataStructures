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

//�ִ�һ�ö�����,���ظ��ڵ�
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

//ǰ�����
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

//����1---ȫ�ֱ���������ÿ��ʹ��ǰ��Ҫ�ÿ�
int count = 0;
void TreeSize1(BTNode* root)
{
	if (root == NULL)
		return;
	count++;
	TreeSize1(root->left);
	TreeSize1(root->right);
}

//����2---����˼��
int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

//����Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//�����k��ڵ���
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

//�ҵ�ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//����������������ȥ��
	//����һ��ָ����ܷ���ֵ�������ĺô�������ҵ��˾��ܹ������ˣ����ü����ݹ����
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	//�������Ҳ�������ȥ������ȥ��
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

//����������ٶ�����
void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//root��Ϊ��ֱ�����
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);
		//���ΰѵڶ��㡢������...���Һ������
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
		//ȡ��ͷ���ݣ���ͷ��Ϊ�������Һ��������Ƿ�Ϊ�ն�push������
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		//���������һ����������ѭ��
		//��ȫ��������һ���պ�߶��ǿգ����պ�߲�ȫΪ��������ȫ������
		else
		{
			break;
		}
	}
	while (!QueueEmpty(&q))
	{
		//ȡ�������пպ�ߵĽڵ�ָ�룬������ڷǿգ�ֱ�ӷ���false
		BTNode* front = QueueFront(&q);
		//ȡ����pop���¶�ͷ
		QueuePop(&q);
		if (front)
		{
			//����ǰ��Ҫ���ٶ����Է��ڴ�й¶
			QueueDestroy(&q);
			return false;
		}
	}
	//������⻹û�з��أ���ô����true
	//�ú�������push����Ҫ���ж��е������ٷ��أ���������ڴ�й©
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