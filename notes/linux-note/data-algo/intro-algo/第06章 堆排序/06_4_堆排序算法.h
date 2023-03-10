#pragma once
#include "..\base.h"
#include "06_1_��_2_�ѵ�����.h"
#include "06_3_����.h"

/*
	�������㷨�� �����е����Ԫ�����ڸ��ڵ�1�У�ͨ��������������һ���ڵ㻥����
	Ȼ������һ���ڵ����ȥ����Ȼ�����MaxHeapify����һ���µ����ѣ�֪���ѵĴ�С
	����2
*/

void HeapSort(int a[], int length)
{
	BuildMaxHeap(a, length);
	for (int i = length; i > 1; i--)
	{
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		MaxHeapify(a, 1, i-1);
	}
}

void HeapSortTest()
{
	int a[] = { 0,16,14,10,8,7,9,3,2,4,1 };
	HeapSort(a, 10);
}
