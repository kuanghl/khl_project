#pragma once
#include "..\base.h"

/*
	����������
	������a[p...q]�ֳ�����������ʹ��a[p...r-1]�е�Ԫ��С�ڻ����a[r],
	a[r+1....q]�е�Ԫ�ش��ڻ����a[r]��Ȼ��ͨ���ݹ���ÿ��ţ���a[p...r-1]
	��a[r+1...q]��������
*/

int Partition(int a[], int start, int end)	 //point ..
{
	int x = a[start];
	int j = start;		//j�±�ָ��Ľڵ㼰֮ǰ���нڵ�ض�С��x
						//����������j�±��������нڵ�ض����ڻ����x
	for (int i = start + 1; i <= end; i ++ )	//i ���������ҳ�����С��x��
	{											//ʹ֮���j�±������
		if (a[i] < x)
		{
			j++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[start] = a[j];
	a[j] = x;
	return j;
}
//������������Partition��	
int _Partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[r] = a[i + 1];
	a[i + 1] = x;

	/*
		��ϰ7.1-2
		if((i+2)==x)
			return (p+r)/2;
	*/
	return i + 1;
}


void QuickSort(int a[], int start, int end)
{
	if (start < end)
	{
		int i = Partition(a, start, end);
		QuickSort(a, start, i - 1);
		QuickSort(a, i + 1, end);
	}
}

void QuickSortTest()
{
	int a[] = { 5,6,1,3,7,8,9,10,2,4 };
	QuickSort(a, 0, 9);
}