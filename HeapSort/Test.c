#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


//O(logN)
void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent] && (child + 1) < size)
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

//升序---建大堆
//降序---建小堆
void HeapSort(int* a, int size)
{
	//把第一个元素当成堆，后边的元素依次插入
	//建堆方式1
	////O(N*logN)
	//for (int i = 1; i < size; i++)
	//{
	//	AdjustUp(a, i);
	//}
	//建堆方式2
	//从倒数第一个非叶子节点开始建堆，再--依次往上建堆
	//O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}
	//堆排序时间复杂度O(N*logN),每一次调整都是logN，有N个数需要调整
	//每次先把最大的数据换到最后一个数，在进行向下调整选出次大的数
	int end = size - 1;

	while (end > 0)
	{
		//把最大的数换到尾，这时候左右子树都还是堆满足向下调整的条件
		Swap(&a[0], &a[end]);
		//从根节点开始调
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}