#pragma once

#include "../��22�� ������ͼ�㷨/22_1_ͼ�ı�ʾ.h"


void InitializeSingleSource(LGraph *graph, int source)
{
	for (int i = 1; i <= graph->vexnum; i++)
	{
		graph->vexs[i]->d = INT_MAX;
		graph->vexs[i]->pre = 0;
	}
	graph->vexs[source]->d = 0;
}

void Relax(LGraph *graph, int front, int behand)
{
	ENode *edge =graph->vexs[front]->first_edge;
	while (graph->vexs[edge->ivex]!= graph->vexs[behand])
	{
		edge = edge->next_edge;
	}
	if (graph->vexs[edge->ivex] == graph->vexs[behand])
	{
		if (graph->vexs[behand]->d > graph->vexs[front]->d + edge->weight)
		{
			graph->vexs[behand]->d = graph->vexs[front]->d + edge->weight;
			graph->vexs[behand]->pre = front;
		}
	}

	
}
