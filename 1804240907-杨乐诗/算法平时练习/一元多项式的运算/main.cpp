#include"head.h"

int main(void)
{
	//用链表结构，创建两个多项式
	PDXS Da = creat_dxs();
    traverse(Da);
 
	PDXS Db = creat_dxs();
    traverse(Db);
 
	//求两个多项式的加法
	PDXS Dj = add(Da, Db);
	traverse(Dj);
 
	return 0;
}