#pragma once
#include "..\base.h"
#include "06_1_��_2_�ѵ�����.h"

/*
	�������ѣ� n/2 ������������n ����Ҷ�ڵ�
	�����е�ÿһ���ڵ����MaxHeapify
*/

void BuildMaxHeap(int a[], int length)
{
	for (int i = length / 2; i > 0; i--)
	{
		MaxHeapify_(a, i, length);
	}
}

void BuildTest()
{
	int a[] = { 0,4,1,3,2,16,9,10,14,8,7 };
	BuildMaxHeap(a, 10);
}

/*	
	��ϰ6.3-2  ��ΪMaxHeapify�����ļٶ����ڵ�Ķ������������ѡ�
	�����1��ʼ�����������ӽڵ��ϵ�ָ���ܲ������ֵ��Ȼ�����ͽ����ˡ����Զ���i��˵
	����ݼ���
*/