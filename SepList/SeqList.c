#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//初始化顺序表
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

//检查容量
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

//打印顺序表
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//尾插----O(1)
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头插----O(n)
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		//从后往前挪
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//尾删----O(1)
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size >= 0);
	ps->size--;
}

//头删----O(n)
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	//1
	//for (int i = 0; i < ps->size - 1; i++)
	//{
	//	//从前往后挪
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

//插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//插入，从后往前挪
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//删除
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

//查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;//找到
		}
	}
	return -1;//找不到
}

//修改
void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}