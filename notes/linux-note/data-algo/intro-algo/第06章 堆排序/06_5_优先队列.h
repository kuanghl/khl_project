#pragma once
#include "../base.h"
#include "06_3_����.h"

int HeapMaximum(int a[])
{
	return a[1];
}

int HeapExtractMax(int a[], int size)
{
	if (size < 1)
		return -1;
	int max = a[1];
	a[1] = a[size - 1];
	MaxHeapify(a, 1, size - 1);
	return max;
}

void HeapIncreaseKey(int a[], int size, int i, int key)
{
	if (key < a[i])
	{
		return;
	}
	a[i] = key;
	while (1 > 1 && a[PARENT(i)] < a[i])
	{
		int temp = a[PARENT(i)];
		a[PARENT(i)] = a[i];
		a[i] = temp;
		i = PARENT(i);
	}
}
/*	
	�������С���ܸı䣬�����·�����ʴ�С��ָ����в����������ش�ָ�롣
*/
int *MaxHeapInsert(int a[], int size, int key)
{
	int *ret = (int *)malloc(sizeof(int)*(size + 1));
	for (int i = 0; i <= size; i++)
	{
		ret[i] = a[i];
	}
	ret[size + 1] = key-1;
	HeapIncreaseKey(a, size + 1, size + 1, key);
	return ret;
}
