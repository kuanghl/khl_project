#pragma once
#include "..//base.h"

enum Color { white,gray,black };

// �ڽӱ��б��Ӧ������Ķ���
typedef struct _ENode
{
	int ivex;                   // �ñ���ָ��Ķ����λ��
	int source;				//ǰ�ڵ�
	int weight;				//Ȩ��
	struct _ENode *next_edge;   // �ñ�ָ����һ������ָ��
}ENode, *PENode;

// �ڽӱ��б�Ķ���
typedef struct _VNode
{
	char data;              // ������Ϣ
	enum Color color;		//��ɫ
	int pre;		//ǰ�����
	int category;
	int d;					//Դ�ڵ㵽��ǰ�ڵ�ľ���
	int f;
	//  dfs�� d ��ʼʱ�䣬f ����ʱ�䡣
	ENode *first_edge;      // ָ���һ�������ö���Ļ�
}VNode;

// �ڽӱ�
typedef struct _LGraph
{
	int vexnum;             // ͼ�Ķ������Ŀ
	int edgnum;             // ͼ�ıߵ���Ŀ
	VNode *vexs[SIZE];
}LGraph;


LGraph *CreateGraph(int msg[][10], int vexs,int edges)
{
	LGraph *G = (LGraph *)malloc(sizeof(LGraph));
	G->vexnum = vexs;
	G->edgnum = edges;

	for (int i = 0; i < vexs; i++)
	{
		VNode *vnode = (VNode *)malloc(sizeof(VNode));
		vnode->data = i + 'a' ;
		vnode->first_edge = NULL;
		vnode->pre = 0;

		for (int j = 0; j <vexs; j++)
		{
			if (msg[i][j] != 0)
			{
				if (vnode->first_edge == NULL)
				{
					ENode *edge = (ENode *)malloc(sizeof(ENode));

					edge->ivex = j+1;
					edge->weight = msg[i][j];
					edge->next_edge = NULL;
					vnode->first_edge = edge;
				}
				else
				{
					ENode * pre_Lnode = vnode->first_edge;
					while (pre_Lnode->next_edge != NULL)
					{
						pre_Lnode = pre_Lnode->next_edge;
					}
					ENode *edge = (ENode *)malloc(sizeof(ENode));

					edge->ivex = j + 1;
					edge->weight = msg[i][j];
					edge->next_edge = NULL;
					pre_Lnode->next_edge = edge;
				}
			}
		}
		G->vexs[i+1] = vnode;
	}
	return G;
}



void DestroyGraph(LGraph *G)
{
	for (int i = 1; i <= G->vexnum; i++)
	{
		if (G->vexs[i]->first_edge == NULL)
		{
			free(G->vexs[i]);
		}
		else
		{
			ENode *temp = G->vexs[i]->first_edge;
			while (temp!=NULL)
			{
				ENode *del_node = temp;
				temp = temp->next_edge;
				free(del_node);	
			}
		}
		free(G->vexs[i]);
	}
	free(G);
}

LGraph *TransposeGraph(LGraph *G)
{
	LGraph *new_graph = (LGraph *)malloc(sizeof(LGraph));
	new_graph->vexnum = G->vexnum;
	new_graph->edgnum = G->edgnum;
	for (int i = 1; i <= G->vexnum; i++)
	{
		new_graph->vexs[i] = (VNode *)malloc(sizeof(VNode));
		new_graph->vexs[i]->color = G->vexs[i]->color;
		new_graph->vexs[i]->d = G->vexs[i]->d;
		new_graph->vexs[i]->f = G->vexs[i]->f;
		new_graph->vexs[i]->data = G->vexs[i]->data;
		new_graph->vexs[i]->first_edge = NULL;

	}
	for (int i = 1; i <= G->vexnum; i++)
	{

		ENode *edge = G->vexs[i]->first_edge;
		while (edge != NULL)
		{
			if (new_graph->vexs[edge->ivex]->first_edge == NULL)
			{
				new_graph->vexs[edge->ivex]->first_edge = (ENode *)malloc(sizeof(ENode));
				new_graph->vexs[edge->ivex]->first_edge->ivex = i;
				new_graph->vexs[edge->ivex]->first_edge->next_edge = NULL;
			}
			else
			{
				ENode *par_edge = new_graph->vexs[edge->ivex]->first_edge;
				while (par_edge->next_edge != NULL)
					par_edge = par_edge->next_edge;
				par_edge->next_edge= (ENode *)malloc(sizeof(ENode));
				par_edge->next_edge->ivex = i;
				par_edge->next_edge->next_edge = NULL;

			}
			edge = edge->next_edge;
		}

	}
	return new_graph;
}
