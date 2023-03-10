#pragma once
#include "..\base.h"
/* 
��������˼�룺
		�������±� i ��ʾ��ǰ�����Ԫ�أ�
		��ô0��i-1Ϊ�Ѿ�����õ�Ԫ�أ�
		�������ҵ�i��λ�ò�����
*/

void InsertSort(int *array, int length)
{
	int key,j;
	for (int i = 1; i < length; i++)
	{
		key = array[i];
		j = i - 1;
		while ((j >= 0)&&(array[j]>key)) //��ϰ2.1-2  �ĳ� array[j]<key
		{
			array[j + 1] = array[j--];
		}
		array[j + 1] = key;
	}
}

//��������򵥲���
void InsertSortTest()
{
	int a[5] = { 1,4,5,2,3 };
	InsertSort(a, 5);
}

//��ϰ2.1 - 3
void FindV(int array[], int length,int v)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (array[i] == v)
		{
			return;
		}
	}
	if (i == length)
		v = -1;	// vδ���ָ�ֵΪ����ֵ
}

//��ϰ2.1 - 4
void TwoBinNumAdd(int first[], int second[],int sum[] ,int length)
{
	for (int i = 0; i < length; i++)
	{
		sum[i + 1] = first[i] + second[i];
	}
	for (int i = length; i > 0; i--)
	{
		if (sum[i] >= 2)
		{
			sum[i] -= 2;
			sum[i - 1] += 1;
		}
	}
}
// ��ϰ2.1 - 4 ����
void TwoBinNumAddTest()
{
	int first[4] = { 1,1,0,1 };
	int second[4] = { 1,1,0,0 };
	int sum[5] = { 0 };
	TwoBinNumAdd(first, second, sum, 5);
}
/*
	��ϰ2.1-1	A{31,41,59,26,41,58}	
				A{31,41,59,26,41,58}	i=1
				A{31,41,59,26,41,58}		2
				A{26,31,41,59,41,58}		3
				A{26,31,41,41,59,58}		4
				A{26,31,41,41,58,59}		5
*/

