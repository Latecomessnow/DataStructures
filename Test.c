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

//取栈顶元素
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
    //先检查容量
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
    //虽然Pop掉了，但其实越界访问还是能够访问到元素
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
    //为空返回true，不为空返回false
    return ps->top == 0;
}

int StackSize(ST* ps)
{
    assert(ps);
    //直接返回top就可以了，因为top比最大的下标大1
    return ps->top;
}

bool isValid(char* s) {
    ST st;
    StackInit(&st);
    while (*s)
    {
        //左括号入栈
        if (*s == '{' || *s == '[' || *s == '(')
        {
            StackPush(&st, *s);
            s++;
        }
        else
        {
            //若没有一个括号入栈直接返回false
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            //取出后要Pop掉
            StackPop(&st);
            if ((top == '{' && *s == '}')
                || (top == '[' && *s == ']')
                || (top == '(' && *s == ')'))
            {
                s++;
            }
            else
            {
                //结束之前都要销毁栈
                StackDestroy(&st);
                return false;
            }

        }
    }
    //最好还要判断栈为不为空
    //栈为空括号才表示括号全部匹配完
    bool ret = StackEmpty(&st);
    //然后再销毁栈
    StackDestroy(&st);
    return ret;
}

int main()
{
    char* s = "([)]";
    bool ret = isValid(s);
    return 0;
}