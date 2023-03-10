#pragma once
#include "../��07�� ��������\07_3_���������������汾.h"

/*
	�ҳ������е�iС�����ݣ�
	�㷨һ�����µĿ�������Ϊģ�ͣ�������������еݹ黮�֣�Ȼ�����ֵ�һ�ߡ�
*/

int RandomizedSelect(int a[], int start, int end, int i)
{
	if (start == end)
		return a[start];
	int middle = RandomizedPartition(a, start, end);
	int k = middle - start + 1;  //shit....
	if (k == i)
		return a[middle];
	else if (i < k)
	{
		return RandomizedSelect(a, start, middle - 1, i);
	}
	else
	{
		return RandomizedSelect(a, middle + 1, end, i - k);
	}

}


//��ϰ9.2-3
int CircleSelect(int a[], int start, int end, int i)
{
	int middle,k;
	while (start<end)
	{
		middle = RandomizedPartition(a, start, end);
		k = middle - start + 1;
		if (k == i)
			return a[middle];
		else if (i < k)
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
			i = i - k;
		}
	}
	return a[start];
}

void RandomizedSelectTest()
{
	int a[] = { 5,6,1,3,7,8,9,10,2,4 };
	int i = CircleSelect(a, 0, 9, 1);
}

/*
	��ϰ9.2-1 �������Ϊ�������࣬�Ǹ�k�ض�����1��i�ض�����k�����Բ�����ѡ�񳤶�Ϊ0��
	��һ���֣��Ҳ����ơ�

	��ϰ9.2-4 ÿ�ζ��������Ǹ�ֵ���м�ֵ��
*/