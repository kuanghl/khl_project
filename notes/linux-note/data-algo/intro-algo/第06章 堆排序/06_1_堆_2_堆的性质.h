#pragma once
#include "..\base.h"

#define PARENT(i) (i/2)
#define LEFT(i)	(2*i)
#define RIGHT(i) (2*i+1)

//	�����±�Ϊ0��Ԫ��ʹ��

 /*
	��ϰ6.1-1	�߶�Ϊh
	max	1*2*4*8.....*2^(n)=2^(n+1)-1
	min	1*2*4*8.....*2(n-1)=2^n

	��ϰ6.1-2 lgn �߶ȵ�Ԫ�غͷ�ΧΪ(n,2n-1)
	��ԭ���֤
*/

//6.2	 

// �� i��left��right ��ѡ�����ģ��±�洢��max�У����max==i ����
//	����max��i����Ӧ��ֵ����ʱmax��Ӧ��ԭ����i��ֵ��Ȼ��ݹ����MaxHeapify 
void MaxHeapify(int a[], int i,int heap_size)
{
	int left = LEFT(i);
	int right = RIGHT(i);
	int max = i;
	if (left <= heap_size )
	{
		max = a[max] > a[left] ? max : left;
	}
	if (right <= heap_size)
	{
		max = a[max] > a[right] ? max : right;
	}
	if (max != i)
	{
		int temp = a[max];
		a[max] = a[i];
		a[i] = temp;
		MaxHeapify(a, max, heap_size);
	}
}


// ��ϵ6.2-2 ��С��
void MinHeapify(int a[], int i, int heap_size)
{
	int left = LEFT(i);
	int right = RIGHT(i);
	int min = i;
	if (left <= heap_size)
	{
		min = a[min] < a[left] ? min : left;
	}
	if (right <= heap_size)
	{
		min = a[min] < a[right] ? min : right;
	}
	if (min != i)
	{
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
		MinHeapify(a, min, heap_size);
	}
}

//6.2-5	�ǵݹ�����
void MaxHeapify_(int a[], int i, int heap_size)
{
	int max,right,left;
	max = i;
	do
	{
		i = max;
		left = LEFT(i);
		right = RIGHT(i);
		if (left <= heap_size)
		{
			max = a[max] > a[left] ? max : left;
		}
		if (right <= heap_size)
		{
			max = a[max] > a[right] ? max : right;
		}

		int temp = a[max];
		a[max] = a[i];
		a[i] = temp;
	} while (max != i);
}

void Test()
{
	int a[11] = { 0,16,4,10,14,7,9,3,2,8,1 };
	MaxHeapify(a, 2, 10);
}

