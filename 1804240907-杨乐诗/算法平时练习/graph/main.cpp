#include"graph.h"
int main(int argc, char const *argv[])
{
    int i,j;
    struct graph graph;
    initGraph(&graph);
    bulidGraph(&graph);
    DFS(&graph,0,6);//从0到6访问每个顶点并输出
    for (i=0;i<MAXNUM ;i++)
   {
        for(j=0;j<MAXNUM;j++)
          printf("%7d",graph.G[i][j]);
        printf("\n");
   }
