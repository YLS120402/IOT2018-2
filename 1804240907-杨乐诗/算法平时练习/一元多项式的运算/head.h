#include"stdio.h"
#include"stdlib.h"

typedef struct dxs  //多项式节点
{
	float coe;  //系数
	int exp;   //指数
	struct dxs * pNext;  //指针域
 
}DXS, * PDXS;
  
PDXS creat_dxs();   //创建多项式
void traverse(PDXS pHead);   //遍历多项式链表
PDXS add(PDXS Da, PDXS Db);  //多项式求和
 