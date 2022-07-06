#define _CRT_SECURE_NO_WARNINGS 1

//可以使用链表实现，但使用链表实现时要注意空和满的判断，可以加一个size记录或者多开一个空间
//不存储有效数据当tail->next == head时为满，tail == head为空，但链表实现时取尾的数据较为麻烦
//也可以使用数组实现，但下标到边界时要进行处理
typedef struct {
    int* a;
    int k;
    int head;
    int tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL)
        exit(-1);
    obj->a = (int*)malloc(sizeof(int) * (k + 1));//多开一个空间
    if (obj->a == NULL)
        exit(-1);
    obj->k = k;
    obj->head = obj->tail = 0;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //head和tail相等即为空
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //要处理head == 0, tail == 4的特殊情况
    int next = obj->tail + 1;
    if (next == obj->k + 1)
        next = 0;
    //如果tail + 1 == head为满
    return next == obj->head;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //如果满了就插入失败
    if (myCircularQueueIsFull(obj))
        return false;
    obj->a[obj->tail] = value;
    obj->tail++;
    //如果head == 1,tail == 4,要处理一下这类情况，把越界的tail置0
    if (obj->tail == obj->k + 1)
        obj->tail = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return false;
    //出队列，头删,如果头到了尾也要处理一下
    obj->head++;
    if (obj->head == obj->k + 1)
        obj->head = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;
    //
    int prev = obj->tail - 1;
    if (obj->tail == 0)
        prev = obj->k;
    return obj->a[prev];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    //先释放数组，在释放队列
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/