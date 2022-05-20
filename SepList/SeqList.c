#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//��ʼ��˳���
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
	ps->a = (SLDataType*)malloc(ps->capacity * sizeof(SLDataType));
	if (ps->a == NULL)
	{
		perror("SLInit::malloc");
		return;
	}
	else
	{
		memset(ps->a, 0, ps->capacity * sizeof(SLDataType));
	}
}

//�������
void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("CheckCapacity::realloc");
			return;

		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//��ӡ˳���
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//β��----O(1)
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��----O(n)
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		//�Ӻ���ǰŲ
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//βɾ----O(1)
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size >= 0);
	ps->size--;
}

//ͷɾ----O(n)
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	//1
	//for (int i = 0; i < ps->size - 1; i++)
	//{
	//	//��ǰ����Ų
	//	ps->a[i] = ps->a[i + 1];
	//}

	//2
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

//����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//���룬�Ӻ���ǰŲ
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//ɾ��
void SLErase(SL* ps, int pos)  
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}

//����
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;//�ҵ�
		}
	}
	return -1;//�Ҳ���
}

//�޸�
void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}