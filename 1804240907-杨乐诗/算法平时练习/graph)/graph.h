#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#define MAXNUM 100
#define INEINITY 65536
#include<stdio.h>
#include<stdlib.h>
static visited[MAXNUM];//ȫ������
struct graph
{
    int nv;//������
    int ne;//����
    int G[MAXNUM][MAXNUM];//�ڽӾ���

};
struct edge
{
    int start;
    int end;
    int weight;
};

struct graph *bulidGraph (struct graph *gm);
void initGraph(struct  graph *gm);
void readFromFile(struct  graph *gm);
void insertEdge(struct graph *gm,struct edge *em);
void DFS(struct graph *gm,int v1,int v2);



#endif // GRAPH_H_INCLUDED
