#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}


void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//孩子最多能够调到根节点
	while (child > 0)
	{
		//小根堆
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//孩子向上走
			child = parent;
			parent = (child - 1) / 2;
		}
		//父亲比孩子小不调整
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		assert(tmp);
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php ->size - 1);//孩子从叶子节点开始调整
}

//向下调整算法
//小根堆
//如果孩子节点比父亲小，那么父亲就要往下调
void AdjustDown(HPDataType* a, int size, int parent)//此处也要传父节点的位置，因为后边涉及到的父节点未必就是根节点
{
	//也可以使用算出左右孩子进行比较的方式
	//如下方法是比较官方的写法，孩子节点都先算左孩子，如果右孩子比左孩子还要小，那么再++child
	//结束的条件就是最坏的情况，父亲一直往下调到完全二叉树的叶子节点为止
	int child = parent * 2 + 1;
	while (child < size)
	{
		//选出左右孩子小或大的那一个
		if ((child + 1) < size && a[child + 1] < a[child])//注意child + 1右孩子有可能是不存在的，要判断一下
		{
			child++;
		}
		if (a[child] < a[parent])
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

void HeapPop(HP* php)
{
	assert(php);
	//检查一下堆
	assert(php->size > 0);
	//删除时删除的是堆顶的数据，删除其他位置的数据是没有意义的
	//先把堆顶的数据和最后一个数据交换，size--删除，再进行向下调整
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP* php)
{
	assert(php);
	//int count = 0;
	//for (int i = 0; i < php->size; i++)
	//{
	//	count++;
	//}
	//return count;
	if (HeapEmpty(php))
		return 0;
	return php->size;//不用减一，php->size就是堆数据个数了
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	//检查一下堆是否为空
	assert(php->size > 0);
	return php->a[0];
}