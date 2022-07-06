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

//���ϵ����㷨
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//��������ܹ��������ڵ�
	while (child > 0)
	{
		//С����
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			//����������
			child = parent;
			parent = (child - 1) / 2;
		}
		//���ױȺ���С������
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
	AdjustUp(php->a, php ->size - 1);//���Ӵ�Ҷ�ӽڵ㿪ʼ����
}

//���µ����㷨
//С����
//������ӽڵ�ȸ���С����ô���׾�Ҫ���µ�
void AdjustDown(HPDataType* a, int size, int parent)//�˴�ҲҪ�����ڵ��λ�ã���Ϊ����漰���ĸ��ڵ�δ�ؾ��Ǹ��ڵ�
{
	//Ҳ����ʹ��������Һ��ӽ��бȽϵķ�ʽ
	//���·����ǱȽϹٷ���д�������ӽڵ㶼�������ӣ�����Һ��ӱ����ӻ�ҪС����ô��++child
	//��������������������������һֱ���µ�����ȫ��������Ҷ�ӽڵ�Ϊֹ
	int child = parent * 2 + 1;
	while (child < size)
	{
		//ѡ�����Һ���С������һ��
		if ((child + 1) < size && a[child + 1] < a[child])//ע��child + 1�Һ����п����ǲ����ڵģ�Ҫ�ж�һ��
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
	//���һ�¶�
	assert(php->size > 0);
	//ɾ��ʱɾ�����ǶѶ������ݣ�ɾ������λ�õ�������û�������
	//�ȰѶѶ������ݺ����һ�����ݽ�����size--ɾ�����ٽ������µ���
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
	return php->size;//���ü�һ��php->size���Ƕ����ݸ�����
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	//���һ�¶��Ƿ�Ϊ��
	assert(php->size > 0);
	return php->a[0];
}