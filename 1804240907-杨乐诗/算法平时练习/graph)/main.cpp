#include"graph.h"
int main(int argc, char const *argv[])
{
    int i,j;
    struct graph graph;
    initGraph(&graph);
    bulidGraph(&graph);
    DFS(&graph,0,6);//��0��6����ÿ�����㲢���
    for (i=0;i<MAXNUM ;i++)
   {
        for(j=0;j<MAXNUM;j++)
          printf("%7d",graph.G[i][j]);
        printf("\n");
   }
