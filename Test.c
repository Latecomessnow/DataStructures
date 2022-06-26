#define _CRT_SECURE_NO_WARNINGS 1

//����ʹ������ʵ�֣���ʹ������ʵ��ʱҪע��պ������жϣ����Լ�һ��size��¼���߶࿪һ���ռ�
//���洢��Ч���ݵ�tail->next == headʱΪ����tail == headΪ�գ�������ʵ��ʱȡβ�����ݽ�Ϊ�鷳
//Ҳ����ʹ������ʵ�֣����±굽�߽�ʱҪ���д���
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
    obj->a = (int*)malloc(sizeof(int) * (k + 1));//�࿪һ���ռ�
    if (obj->a == NULL)
        exit(-1);
    obj->k = k;
    obj->head = obj->tail = 0;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //head��tail��ȼ�Ϊ��
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //Ҫ����head == 0, tail == 4���������
    int next = obj->tail + 1;
    if (next == obj->k + 1)
        next = 0;
    //���tail + 1 == headΪ��
    return next == obj->head;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    //������˾Ͳ���ʧ��
    if (myCircularQueueIsFull(obj))
        return false;
    obj->a[obj->tail] = value;
    obj->tail++;
    //���head == 1,tail == 4,Ҫ����һ�������������Խ���tail��0
    if (obj->tail == obj->k + 1)
        obj->tail = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return false;
    //�����У�ͷɾ,���ͷ����βҲҪ����һ��
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
    //���ͷ����飬���ͷŶ���
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