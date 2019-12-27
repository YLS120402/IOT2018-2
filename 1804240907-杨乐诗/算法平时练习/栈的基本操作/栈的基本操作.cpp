#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100//初始分配量
#define STACKINCREMENT 10//分配增量

typedef struct
{
	int *base;
	int *top;
	int stacksize;//当前栈使用的最大容量
}SqStack;

void InitStack(SqStack &S)//构建一个空栈
{
	S.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
	{
	   printf("存储分配失败！");
	}
	else
	{
       S.top=S.base;
	   S.stacksize=STACK_INIT_SIZE;
	   printf("构造成功！");
	}
}

void Push(SqStack &S,int e)
{
     if(S.top-S.base>=S.stacksize)
	 {
	    S.base =(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int)) ;
		if(!S.base)
			printf("存储分配失败！");
		else
		{
		    S.stacksize+=STACKINCREMENT;
			S.top=S.base+S.stacksize;
		}
	 }
	 *S.top++=e;
}

void DisplayStack(SqStack &S)//从栈底到栈顶逐次显示栈中的元素
{
    int *p;
	p=S.base;
	if(S.base==S.top)
		printf("当前栈为空栈！");
	else
	{
	   printf("当前栈内元素为：");
		   while(p!=S.top)
		   {
		     printf("%d",*p);
			 p++;

		   }
		   printf("\n");
	}

}

int StackLength(SqStack S)//求长度
{
   int *p;
   p=S.base ;
   int i=0;
   while(p!=S.top)
	   p++;
       i++;
	return i;
}

void pop(SqStack &S,int &e)//出栈
{
  if(S.top==S.base)
	  printf("操作失败！");
  else
  {
     e=*--S.top;
	 DisplayStack(S);
  }
}

void ClearStack(SqStack &S)//清空
{
   int b;
   while(S.top!=S.base)b=*--S.top;
   if(S.top==S.base)
	   printf("顺序栈已清空！");
}

void StackEmpty(SqStack S)//判空
{
  if(S.top==S.base)
	  printf("顺序栈为空！");
	  else
	  printf("顺序栈不为空！");
}

void DestroyStack(SqStack &S)//销毁
{
   S.base=NULL;
   printf("顺序栈已销毁！");
}

void GetTop(SqStack S,int &e)//返回栈顶元素
{
   if(S.top==S.base)
	   printf("操作失败！");
   else
   {
     printf("栈顶元素为：");
		 e=*(S.top-1);
	 printf("%d",e);
   }
}

int menu()
{
     printf("1.构造一个空栈\n");
	 printf("2.输入栈的元素\n"); 
	 printf("3.输出栈的元素\n");
     printf("4.求栈的长度\n")  ;
	 printf("5.求栈顶元素\n")  ;
	 printf("6.删除栈顶元素\n") ; 
	 printf("7.清空已存在的栈\n");  
	 printf("8.判断栈是否为空\n") ; 
	 printf("9.销毁栈\n") ;

     SqStack S;
     int choice;
     InitStack(S);
     while(1)
	 {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if(choice==9) break;
        switch(choice)
		{
           case 1: InitStack(S);
	          break;
           case 2: char a;
			       Push(S,a);
	          break;
           case 3: DisplayStack(S);
	          break;
           case 4: StackLength(S);
	          break;
           case 5: int b;
			       GetTop(S,b);
	          break;
           case 6: int c;
			       pop(S,c);
	          break;
           case 7: ClearStack(S);
	          break;
           case 8: StackEmpty(S);
	          break;
           case 9: DestroyStack(S);
	          break;

           default:printf("输入错误！！！\n");
		}
	 }
    return 0;
}
