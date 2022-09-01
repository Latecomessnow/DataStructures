#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
#include"Stack.h"

void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������---O(N^2)
void InsertSort(int* a, int n)
{
	//ѭ���������ע��˴�end���Ϊn-2
	for (int i = 0; i < n - 1; i++)
	{
		//ÿһ������һ��ʼ�ѵ�һ��Ԫ�ص����������飬����һ��Ԫ�ص��ɲ���Ԫ��ȥ������������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				//���ǲ���Ԫ�غ�Ų��end
				end--;
			}
			else
				//�˴����ż���tmp����a[end]����Ϊ�п���end--������-1����ѭ��
				break;
		}
		//��endΪ-1ʱҲ���Ը�end+1��ֵ��
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	//int gap = n;
	//while (gap > 1)
	//{
	//	//gap > 1ʱ����Ԥ����ֻ��gap = 1ʱ����ֱ�Ӳ�������
	//	//gap�п��ܻ�Ϊ2����3���Ϊ0�ˣ�����Ҫ��1
	//	gap = gap / 3 + 1;
	//	//����ѭ��
	//	for (int j = 0; j < gap; j++)
	//	{
	//		//һ��ѭ��
	//		for (int i = j; i < n - gap; i += gap)
	//		{
	//			//һ���еĵ���ѭ��
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)
	//			{
	//				if (tmp < a[end])
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//				else
	//					break;
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
	//}

	//�Ż�д��
	int gap = n;
	while (gap > 1)
	{
		//gap > 1ʱ����Ԥ����ֻ��gap = 1ʱ����ֱ�Ӳ�������
		//gap�п��ܻ�Ϊ2����3���Ϊ0�ˣ�����Ҫ��1
		gap = gap / 3 + 1;
		//����ѭ��
		for (int i = 0; i < n - gap; i++)
		{
			//һ���еĵ���ѭ��
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[min], &a[begin]);
		//ע���ж�һ�£��������ǵ�һ��������begin == max����ʱmax�ѱ�����min��
		if (begin == max)
			max = min;
		Swap(&a[max], &a[end]);
		//����������С��Χ
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//�Һ����п���Խ��
		if (a[child + 1] > a[child] && (child + 1) < size)
		{
			child++;
		}
		if (a[child] > a[parent])
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

void HeapSort(int* a, int n)
{
	//���½���---O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//�Ž���---С��
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//������λ����Ԫ�أ�����С�ĵ�������ȥ��ѡ��С�������Ѷ�
		Swap(&a[0], &a[end]);
		//Ȼ�����µ���,�ӶѶ���ʼ��
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

//���������Ż�---����ȡ����key��������ʹ�ò���������ٵݹ�
//����ȡ�е��Ż�Ч���Ƿǳ����Եģ����Ա�������O(N^2)
int GetMidIndext(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[end] > a[begin])
		{
			return begin;
		}
		else if (a[end] > a[begin])
		{
			return end;
		}
		return mid;
	}
}

//hoare---��������
int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end;
	//��ߵ�һ����key
	int key = left;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (left < right)
	{
		//�ұ����ߣ���С
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		//������ߣ��Ҵ�
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	//�ٰ�����λ�õ�ֵ��key����
	//��Ϊ���ұ����ߣ�������ߣ���������λ�õ�ֵ��keyС���߾���key��λ��
	Swap(&a[key], &a[left]);
	key = left;
	return key;
}

//�ڿӷ�---��������
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int pit = begin;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (begin < end)
	{
		//����ǿӣ��ұ����ߣ���С�����ߵĿ�λ��
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pit] = a[end];
		//���¿�λ
		pit = end;
		//�ұ��ǿӣ�����Ҵ���ұߵĿ�λ��
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	//����key�ŵ�����λ��
	a[pit] = key;
	return pit;
}

//int PartSort2(int* a, int begin, int end)
//{
//	int key = a[begin];
//	int pit = begin;
//	while (begin < end)
//	{
//		while (begin < end && a[end] >= key)
//		{
//			end--;
//		}
//		a[pit] = a[end];
//		pit = end;
//		while (begin < end && a[begin] <= a[key])
//		{
//			begin++;
//		}
//		a[pit] = a[begin];
//		pit = begin;
//	}
//	a[pit] = key;
//	return pit;
//}

//ǰ��ָ�뷨---��������
int PartSort3(int* a, int begin, int end)
{
	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (cur <= end)
	{
		//cur��key��ֱ���ߣ���keyСҪͣ��������һ��++prev����ͬλ�þͲ���Ҫ����
		if (a[cur] < a[key] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[prev], &a[key]);
	key = prev;
	return key;
}

void QuickSort(int* a, int begin, int end)
{
	//���εݹ飬������ֻ��һ���������䲻����ʱ������
	if (begin >= end)
		return;
	//int key = PartSort1(a, begin, end);
	//int key = PartSort2(a, begin, end);
	//int key = PartSort3(a, begin, end);
	//��ʱkey��λ�þͲ���Ҫ�ı��ˣ�ֻ��Ҫ��key�����߽��з��εݹ�
	//��������Ԫ�ظ����Ƚ�С�ˣ��Ͳ�Ҫ�ݹ���
	if (end - begin > 20)
	{
		int key = PartSort3(a, begin, end);
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
	else
	{
		//������������Ҳ������������
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int key = PartSort3(a, left, right);
		// [left, keyi-1] keyi[keyi+1, right]
		if (key + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, key + 1);
		}
		if (left < key - 1)
		{
			StackPush(&st, key - 1);
			StackPush(&st, left);
		}
	}
	StackDestroy(&st);
}

//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	//ֱ������ֻ��һ�����������䲻����ʱ����
//	if (begin >= end)
//		return;
//	int mid = (end - begin) / 2 + begin;
//	//�ֱ�����Ҳ��ֵݹ�
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	//һֱ�ݹ黮����������
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int i = begin1;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	//�ߵ�����ô��һ���Ѿ������ˣ���һ����ܻ���������
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//	//��tmp�е����ݿ�����ԭ����
//	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
//}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	//������������

	//[begin, mid] , [mid+1, end]���εݹ飬������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//��·�鲢
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	//���ڱ�ʾ�������䶼��ֻ��һ����
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//���ˣ����ܻ����һ�����������ˣ���һ������ܻ�δ����
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//ÿһ�ζ��ѹ鲢������ݿ�����ԭ���飬���鲢����������ԭ�����������
	//�ڵݹ��в�����ÿ���������ʼλ�ö���0��������Ҫ����begin
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//�鲢����
//ʱ�临�Ӷ�O(N*logN),ÿһ�㶼��N��һ����logN��
//�ռ�ĸ��Ӷ�O(N)
void MergeSort(int* a, int n)
{
	//�鲢������Ҫһ�����������ȥ��Ź鲢�������
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//�鲢
	_MergeSort(a, 0, n - 1, tmp);
	//malloc�����Ŀռ�һ��Ҫ�ͷ�
	free(tmp);
}

//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail!\n");
//		exit(-1);
//	}
//	_MergeSort(a, 0, n - 1, tmp);
//	//malloc������������Ҫ�����Է��ڴ�й©
//	free(tmp);
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, begin2 = i + gap;
			int end1 = i + gap - 1, end2 = i + 2 * gap - 1;
			//Ԫ�ظ���δ����2�ı���
			// end1Խ�����begin2Խ�磬����Բ��鲢��
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			//���ڱ�ʾ�������䶼��ֻ��һ����
			int m = end2 - begin1 + 1;
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * m);
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[max])
			max = a[i];
		if (a[i] < a[min])
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	assert(count);
	//��ʼ��Ϊ0��
	memset(count, 0, sizeof(int) * range);
	//ͳ��count�������±��еĴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	//��count�Ĵ�����ʾ��ֵ��д��ԭ����
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}

//void CountSort(int* a, int n)
//{
//	int min = a[0], max = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] < min)
//			min = a[i];
//		if (a[i] > max)
//			max = a[i];
//	}
//	int range = max - min + 1;
//	int* count = (int*)malloc(sizeof(int) * range);
//	assert(count);
//	memset(count, 0, sizeof(int) * range);
//	//ͳ�ƴ���
//	for (int i = 0; i < n; i++)
//	{
//		count[a[i] - min]++;
//	}
//	int j = 0;
//	//��д����
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			a[j++] = count[i] + min;
//		}
//	}
//}