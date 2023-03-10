#pragma once

#include "22_1_ͼ�ı�ʾ.h"
#include "22_3_�����������.h"



/*

	�㷨���̣�
	1.������ȱ���G,���ÿ�����u�Ľ���ʱ��f[u],������ѡ������ν��

	2.������ȱ���G��ת��ͼG T ,ѡ����������ʱ,���ս��Ľ���ʱ��Ӵ�С���С������Ĺ�����,һ�߱���,
	һ�߸������������,ÿ�ҵ�һ���µ����,������ֵ�ͼ�1��
*/

void StronglyDFSVisit(LGraph *G, int u, int *time,int c)
{
	(*time)++;
	G->vexs[u]->d = *time;
	G->vexs[u]->color = gray;
	G->vexs[u]->category = c;
	ENode *edge = G->vexs[u]->first_edge;
	printf("%c ", G->vexs[u]->data);
	while (edge != NULL)
	{
		if (G->vexs[edge->ivex]->color == white)
		{
			G->vexs[edge->ivex]->pre = u;
			StronglyDFSVisit(G, edge->ivex, time,c);
		}
		edge = edge->next_edge;
	}
	G->vexs[u]->color = black;
	(*time)++;
	G->vexs[u]->f = *time;
}



void StronglyDFS(LGraph * G)
{
	VNode *sort[SIZE] = { 0 };
	int category = 1;
	for (int i = 1; i <= G->vexnum; i++)
	{
		G->vexs[i]->color = white;
		G->vexs[i]->pre = 0;
		sort[G->vexs[i]->f] = G->vexs[i];
	}
	int time = 0;
	for (int i = SIZE-1; i >=0; i--)
	{
		if(sort[i]!=NULL&& sort[i]->color == white)
		{
			StronglyDFSVisit(G, i, &time,category++);
		}
	}

}



LGraph *StronglyConnectedComponents(LGraph *G)
{
	DFS(G);
	LGraph *GT = TransposeGraph(G);
	StronglyDFS(GT);
	return GT;
}



void test()
{
	

	int msg[8][10] =
	{
		2,0,0,0,0,0,0,0,0,0,
		3,5,6,0,0,0,0,0,0,0,
		4,7,0,0,0,0,0,0,0,0,
		3,8,0,0,0,0,0,0,0,0,
		1,6,0,0,0,0,0,0,0,0,

		7,0,0,0,0,0,0,0,0,0,
		6,8,0,0,0,0,0,0,0,0,
		8,0,0,0,0,0,0,0,0,0,
	};

	LGraph *G = CreateGraph(msg, 8, 14);
	
	LGraph *GT = StronglyConnectedComponents(G);

	printf("\n");
	DestroyGraph(G);
	DestroyGraph(GT);

}