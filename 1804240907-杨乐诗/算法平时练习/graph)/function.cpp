#include"graph.h"
struct graph *bulidGraph (struct graph *gm)
{

    initGraph(gm);
    readFromFile(gm);
}

 void initGraph(struct  graph *gm)
{
    int i,j;
    printf("Enter NV and NE :\n");
    scanf("%d%d",&gm->ne,&gm->nv);
    for (i=0;i<MAXNUM ;i++)
        for(j=0;j<MAXNUM;j++)
           gm->G[i][j]=INEINITY;



}
 void readFromFile(struct  graph *gm)
 {
   FILE *fp;
   struct edge e;
   fp=fopen("graph.txt","r");//���ļ�
   if (fp=NULL)
   {
      printf("read file error!!");
      exit(-1);
   }
   while (!feof(fp))//һֱ���ļ������ļ�����
   {
      fscanf(fp,"%d %d %d\n",e.start,e.end,e.weight);//���ļ������
      insertEdge(gm,&e);//��������Ϣ����insert
   }
   fclose(fp);
 }

   void insertEdge (struct graph *gm,struct edge *em)
   {
    gm->G[em->start][em->end]=em->weight;
   }

   void DFS(struct graph *gm,int v1,int v2)
   {
       if (v1==v2)
       {
           return 1;//��ʾ�ҵ���
       }

       printf("Visiting %d\n",v1);
       visited[v1]=1;
       for(int i =0;i<MAXNUM;i++)
       {
           if (gm->G[v1][i]<INEINITY&&visited[i]==0)
           {

             DFS(gm,i,v2);


                }
       return 0;
   }
