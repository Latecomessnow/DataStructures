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

//����---�����
//����---��С��
void HeapSort(int* a, int size)
{
	//�ѵ�һ��Ԫ�ص��ɶѣ���ߵ�Ԫ�����β���
	//���ѷ�ʽ1
	////O(N*logN)
	//for (int i = 1; i < size; i++)
	//{
	//	AdjustUp(a, i);
	//}
	//���ѷ�ʽ2
	//�ӵ�����һ����Ҷ�ӽڵ㿪ʼ���ѣ���--�������Ͻ���
	//O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}
	//������ʱ�临�Ӷ�O(N*logN),ÿһ�ε�������logN����N������Ҫ����
	//ÿ���Ȱ��������ݻ������һ�������ڽ������µ���ѡ���δ����
	int end = size - 1;

	while (end > 0)
	{
		//������������β����ʱ���������������Ƕ��������µ���������
		Swap(&a[0], &a[end]);
		//�Ӹ��ڵ㿪ʼ��
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