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

//直接插入排序---O(N^2)
void InsertSort(int* a, int n)
{
	//循环插入过程注意此处end最大为n-2
	for (int i = 0; i < n - 1; i++)
	{
		//每一趟排序，一开始把第一个元素当成有序数组，把下一个元素当成插入元素去插入有序数组
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				//覆盖插入元素后，挪动end
				end--;
			}
			else
				//此处不着急把tmp赋给a[end]，因为有可能end--后变成了-1跳出循环
				break;
		}
		//当end为-1时也可以给end+1赋值了
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	//int gap = n;
	//while (gap > 1)
	//{
	//	//gap > 1时都是预排序，只有gap = 1时才是直接插入排序
	//	//gap有可能会为2，除3后就为0了，所以要加1
	//	gap = gap / 3 + 1;
	//	//多组循环
	//	for (int j = 0; j < gap; j++)
	//	{
	//		//一组循环
	//		for (int i = j; i < n - gap; i += gap)
	//		{
	//			//一组中的单趟循环
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

	//优化写法
	int gap = n;
	while (gap > 1)
	{
		//gap > 1时都是预排序，只有gap = 1时才是直接插入排序
		//gap有可能会为2，除3后就为0了，所以要加1
		gap = gap / 3 + 1;
		//多组循环
		for (int i = 0; i < n - gap; i++)
		{
			//一组中的单趟循环
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
		//注意判断一下，如果最大是第一个数，即begin == max，此时max已被换到min处
		if (begin == max)
			max = min;
		Swap(&a[max], &a[end]);
		//两边向里缩小范围
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//右孩子有可能越界
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
	//向下建堆---O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//排降序---小堆
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//交换首位两个元素，把最小的的数沉下去，选次小的数到堆顶
		Swap(&a[0], &a[end]);
		//然后向下调整,从堆顶开始调
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

//快速排序优化---三数取中做key、后三层使用插入排序减少递归
//三数取中的优化效果是非常明显的，可以避免最坏情况O(N^2)
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

//hoare---单趟排序
int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end;
	//左边第一个做key
	int key = left;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (left < right)
	{
		//右边先走，找小
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		//左边再走，找大
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	//再把相遇位置的值和key交换
	//因为是右边先走，左边再走，所以相遇位置的值比key小或者就是key的位置
	Swap(&a[key], &a[left]);
	key = left;
	return key;
}

//挖坑法---单趟排序
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int pit = begin;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (begin < end)
	{
		//左边是坑，右边先走，找小，填到左边的坑位上
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pit] = a[end];
		//更新坑位
		pit = end;
		//右边是坑，左边找大，填到右边的坑位上
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	//最后把key放到相遇位置
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

//前后指针法---单趟排序
int PartSort3(int* a, int begin, int end)
{
	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	int mid = GetMidIndext(a, begin, end);
	Swap(&a[key], &a[mid]);
	while (cur <= end)
	{
		//cur比key大直接走，比key小要停下来处理一下++prev，相同位置就不需要换了
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
	//分治递归，当区间只有一个或者区间不存在时不处理
	if (begin >= end)
		return;
	//int key = PartSort1(a, begin, end);
	//int key = PartSort2(a, begin, end);
	//int key = PartSort3(a, begin, end);
	//此时key的位置就不需要改变了，只需要对key的两边进行分治递归
	//如果数组的元素个数比较小了，就不要递归了
	if (end - begin > 20)
	{
		int key = PartSort3(a, begin, end);
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
	else
	{
		//可能是左区间也可能是右区间
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
//	//直到区间只有一个数或者区间不存在时返回
//	if (begin >= end)
//		return;
//	int mid = (end - begin) / 2 + begin;
//	//分别对左右部分递归
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	//一直递归划分左右区间
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
//	//走到这那么有一组已经走完了，另一组可能还存在数据
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//	//把tmp中的数据拷贝回原数组
//	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
//}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	//划分左右区间

	//[begin, mid] , [mid+1, end]分治递归，让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//二路归并
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	//等于表示两个区间都是只有一个数
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
	//至此，可能会出现一个区间走完了，另一区间可能还未走完
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//每一次都把归并后的数据拷贝回原数组，当归并完所有区间原数组就有序了
	//在递归中并不是每个区间的起始位置都是0，所以需要加上begin
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//归并排序
//时间复杂度O(N*logN),每一层都是N，一共有logN层
//空间的复杂度O(N)
void MergeSort(int* a, int n)
{
	//归并排序需要一个额外的数组去存放归并后的数据
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//归并
	_MergeSort(a, 0, n - 1, tmp);
	//malloc出来的空间一定要释放
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
//	//malloc出来的数组需要销毁以防内存泄漏
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
			//元素个数未必是2的倍数
			// end1越界或者begin2越界，则可以不归并了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			//等于表示两个区间都是只有一个数
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
	//初始化为0次
	memset(count, 0, sizeof(int) * range);
	//统计count数组下下标中的次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	//将count的次数表示的值回写到原数组
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
//	//统计次数
//	for (int i = 0; i < n; i++)
//	{
//		count[a[i] - min]++;
//	}
//	int j = 0;
//	//回写排序
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			a[j++] = count[i] + min;
//		}
//	}
//}