#define _CRT_SECURE_NO_WARNINGS 1

typedef int HPDataType;

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//堆——向下调整算法

void AdjustDown(HPDataType* a, int size, int parent)
{
	//先假设左孩子比右孩子小
	int child = parent * 2 + 1;
	//最坏的情况是根节点一直往下调，调到size
	while (child < size)
	{
		if (a[child + 1] < a[child])
		{
			//右孩子大的话就调到右孩子
			child++;
		}
		//孩子比父亲小，孩子就往上调
		//堆是一棵完全二叉树，左孩子存在时，右孩子不一定存在，加个条件防止越界
		if (child + 1 < size && a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}