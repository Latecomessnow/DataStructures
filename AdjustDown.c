#define _CRT_SECURE_NO_WARNINGS 1

typedef int HPDataType;

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//�ѡ������µ����㷨

void AdjustDown(HPDataType* a, int size, int parent)
{
	//�ȼ������ӱ��Һ���С
	int child = parent * 2 + 1;
	//�������Ǹ��ڵ�һֱ���µ�������size
	while (child < size)
	{
		if (a[child + 1] < a[child])
		{
			//�Һ��Ӵ�Ļ��͵����Һ���
			child++;
		}
		//���ӱȸ���С�����Ӿ����ϵ�
		//����һ����ȫ�����������Ӵ���ʱ���Һ��Ӳ�һ�����ڣ��Ӹ�������ֹԽ��
		if (child + 1 < size && a[child] < a[parent])
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