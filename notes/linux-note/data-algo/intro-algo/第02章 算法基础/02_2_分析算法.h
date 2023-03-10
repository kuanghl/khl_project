#pragma once
#include "..\base.h"

/*
	ѡ������˼�룺
	�����ҳ���������СԪ�����һ��Ԫ�ؽ��н�����
	�����ҳ���СԪ����ڶ���Ԫ�ؽ�����
	���ν��У�ֱ���������

	ѭ������������Ԫ�ظ���-1������Ѱ�Ҹ���Ԫ�غ�
	���ʣ�µľ��Ǿ�������Ԫ�ء�����������λ�á�
*/

//��ϰ2.2 - 2 ѡ���㷨
void SelectionSort(int array[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		int min = array[i];
		int min_index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				min_index = j;
			}
		}
		int temp = array[i];
		array[i] = min;
		array[min_index] = temp;
	}
}

//ֱ��ѡ������򵥲���
void SelectionSortTest()
{
	int a[5] = { 1,4,5,2,3 };
	SelectionSort(a, 5);
}

/*
��ϰ2.3 - 3
	�����鳤��Ϊn
	average:		(1+2+3+4+...+n)/2=(n+1)/2
	worset(max) :	n
*/