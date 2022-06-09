#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;

typedef struct Stack
{
    STDataType* data;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);

void StackDestroy(ST* ps);

void StackPush(ST* ps, STDataType x);

void StackPop(ST* ps);

//ȡջ��Ԫ��
STDataType StackTop(ST* ps);

int StackSize(ST* ps);

bool StackEmpty(ST* ps);


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

bool isValid(char* s) {
    ST st;
    StackInit(&st);
    while (*s)
    {
        //��������ջ
        if (*s == '{' || *s == '[' || *s == '(')
        {
            StackPush(&st, *s);
            s++;
        }
        else
        {
            //��û��һ��������ջֱ�ӷ���false
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            //ȡ����ҪPop��
            StackPop(&st);
            if ((top == '{' && *s == '}')
                || (top == '[' && *s == ']')
                || (top == '(' && *s == ')'))
            {
                s++;
            }
            else
            {
                //����֮ǰ��Ҫ����ջ
                StackDestroy(&st);
                return false;
            }

        }
    }
    //��û�Ҫ�ж�ջΪ��Ϊ��
    //ջΪ�����Ųű�ʾ����ȫ��ƥ����
    bool ret = StackEmpty(&st);
    //Ȼ��������ջ
    StackDestroy(&st);
    return ret;
}

int main()
{
    char* s = "([)]";
    bool ret = isValid(s);
    return 0;
}