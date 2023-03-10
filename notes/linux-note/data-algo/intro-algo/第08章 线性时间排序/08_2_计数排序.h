#pragma once
#include "..\base.h"
/*
	��������
	����ÿһ��Ԫ��x��ȷ��С��xԪ�صĸ�����Ȼ��ֱ�Ӱ�x�ŵ�������������е�λ����
*/

void CountSort(int a[], int b[],int size, int k)
{
	int i;
	int *c = (int *)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		c[a[i]] += 1;
	}
	for (int i = 1; i < size; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	
	for (int j = size - 1; j >= 0; j--)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
	/*	//��ϰ8.2-3 �����ȫһ����8
	for (int j = 0; j < size; j++)
	{
		b[c[a[j]] - 1] = a[j];
		c[a[j]]--;
	}
	*/
	free(c);
}

void MyCountSort(int a[],int size)
{
	int i;
	int max = a[0];
	for (i = 1; i < size; i++)
	{
		max = max > a[i] ? max : a[i];
	}

	int *b = (int *)malloc(sizeof(int)*size);
	int *c = (int *)malloc(sizeof(int)*(max+1));	
	for (i = 0; i < max+1; i++)
	{
		c[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		c[a[i]] += 1;
	}
	for (int i = 1; i < max+1; i++)
	{
		c[i] = c[i] + c[i - 1];
	}

	for (int j = size - 1; j >= 0; j--)
	{
		b[c[a[j]] - 1] = a[j];
		c[a[j]]--;
	}

	for (int i = 0; i < size; i++)
	{
		a[i] = b[i];
	}

	free(b);
	free(c); 
}


void CountSortTest()
{
	int a[] = { 2,5,3,0,2,3,0,3 };
	int b[8];
	MyCountSort(a,8);
}

/*
	��ϰ 8.2-1 
		c[10]={2,2,2,2,1,0,2,0,0,0}
*/

//��ϰ 8.2-4

int BetweenAB(int a[], int size, int k,int x,int y)
{
	int i;
	int sum = 0;
	int *c = (int *)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)
	{
		c[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		c[a[i]] += 1;
	}
	// ������Ԥ����O(n)

	//	����Ϊ�ش��������ɡ�����������(1)  y-x
	for (i = x; i <= y; i++)
	{
		sum += c[i];
	}
	return sum;
}