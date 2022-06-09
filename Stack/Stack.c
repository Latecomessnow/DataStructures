	#define _CRT_SECURE_NO_WARNINGS 1

	#include"Stack.h"

	void StackInit(ST* ps)
	{
		assert(ps);
		ps->data = NULL;
		ps->top = 0;
		ps->capacity = 0;
	}

	void StackDestroy(ST* ps)
	{
		assert(ps);
		free(ps->data);
		ps->data = NULL;
		ps->top = 0;
		ps->capacity = 0;
	}

	void StackPush(ST* ps, STDataType x)
	{
		assert(ps);
		//�ȼ������
		if (ps->top == ps->capacity)
		{
			int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
			STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * newCapacity);
			if (tmp == NULL)
			{
				printf("relloc fail\n");
				exit(-1);
			}
			ps->data = tmp;
			ps->capacity = newCapacity;
		}
		ps->data[ps->top] = x;
		ps->top++;
	}

	void StackPop(ST* ps)
	{
		assert(ps);
		assert(!StackEmpty(ps));
		//��ȻPop���ˣ�����ʵԽ����ʻ����ܹ����ʵ�Ԫ��
		ps->top--;
	}

	STDataType StackTop(ST* ps)
	{
		assert(ps);
		assert(!StackEmpty(ps));
		return ps->data[ps->top - 1];
	}

	bool StackEmpty(ST* ps)
	{
		assert(ps);
		//Ϊ�շ���true����Ϊ�շ���false
		return ps->top == 0;
	}

	int StackSize(ST* ps)
	{
		assert(ps);
		//ֱ�ӷ���top�Ϳ����ˣ���Ϊtop�������±��1
		return ps->top;
	}