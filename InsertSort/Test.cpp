#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

namespace my
{
	void InsertSort(int* a, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + 1] = a[end];
				}
				else
					break;
				end--;
			}
			a[end + 1] = tmp;
		}
	}
}

int main()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int b[] = { 10, 27, 1, 0, 9, 37, 29, 10, 2, 9, 4, 1};
	my::InsertSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	my::InsertSort(b, sizeof(b) / sizeof(int));
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}