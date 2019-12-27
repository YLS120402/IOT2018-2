#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 

#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 

typedef int ElemType;
 
typedef struct {
    ElemType *elem; 
    int length;     
    int listsize;   
} SqList;
 

int InitList(SqList *L)
{
    
    L->elem = (ElemType *) malloc(sizeof(ElemType));
    
    if (!L->elem) return ERROR; 
    
    L->length = 0; 
    
    L->listsize = LIST_INIT_SIZE;   
   
    return OK;
}
 
// 获取顺序表第i个元素
ElemType GetListElem(SqList *L, int i)
{
   
    if (i < 1 || i > L->length) 
        return ERROR;
    else    
        return L->elem[i-1];
}
 
// 查询目标元素在顺序表中位置
int LocateListElem(SqList *L, ElemType e)
{
    int i = 1;
   
    ElemType *p = L->elem;
    
    while (*p != e && i <= L->length) 
    {
        i++;
        p++;
    }
    if (i > L->length)
        return 0;
    else
        return i;
}
 
// 在顺序表第i个位置插入元素
int InsertListElem(SqList *L, int i, ElemType e)
{
    int k;  
   
    if (i < 1 || i > L->length + 1) return ERROR;
    
    if (L->length >= L->listsize)
    {
        
        L->elem = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!L->elem) return ERROR;
       
        L->listsize += LISTINCREMENT;       
    }
    
    
    for (k = L->length - 1; k >= i - 1; k--) 
        L->elem[k + 1] = L->elem[k];        
    
    L->elem[i-1] = e;
    
    L->length++;
    
    return OK;  
}
 
// 删除顺序表第i个元素
int DeleteListElem(SqList *L, int i)
{
    int k;
    
    if (i < 1 || i >L->length) return ERROR;
    
    for (k = i; k <= L->length; k++) 
        L->elem[k-1] = L->elem[k];
    
    L->length--;
    
    return OK;
}
 
// 修改顺序表第i个元素
int UpdateListElem(SqList *L, int i, ElemType e)
{
   
    if (i < 1 || i >L->length) return ERROR;
    
    L->elem[i-1] = e;
    
    return OK;
}
 
// 输出顺序表全部元素
void PrintList(SqList *L) 
{
    int i;
    if (L->length == 0)
        printf("\n顺序表为空！\n\n");
    else
        for (i = 1; i <= L->length; i++)
            printf("%d ", L->elem[i-1]);
    printf("\n");
}
 
int main()
{   
    int i, choice, position;  
    ElemType data, elem;  
    int isRunning = 1;
    
    SqList *pl = (SqList *)malloc(sizeof(SqList));      
    
    while(isRunning)  
    {  
        printf("======顺序表操作演示=======\n");  
        printf("1. 创建一个空的顺序表\n");  
        printf("2. 输出顺序表的全部数据\n");  
        printf("3. 查询顺序表某个位置的数据\n");  
        printf("4. 查询数据在顺序表中的位置\n");  
        printf("5. 向顺序表指定位置插入数据\n");  
        printf("6. 删除顺序表指定位置的数据\n");  
        printf("7. 更新顺序表指定位置的数据\n");  
        printf("8. 退出顺序表操作演示程序\n");  
        printf("===========================\n");  
        printf("\n输入1-8，选择所需功能号：");  
        scanf("%d", &choice);  
        printf("\n您选择的功能号为：%d\n", choice);  
  
        switch(choice)  
        {  
            case 1:
                if (InitList(pl)) 
                    printf("\n顺序表创建成功！\n\n");    
                else 
                    printf("\n顺序表创建失败！\n\n");
                system("pause");
                break;
            case 2:
                PrintList(pl);
                system("pause");
                break;
            case 3:
                printf("i=");
                scanf("%d", &i);
                elem = GetListElem(pl, i);
                if (elem) 
                    printf("L[%d]=%d\n\n", i, elem);  
                else
                    printf("输入的位置不合法！");
                system("pause");            
                break;
            case 4:
                printf("data=");
                scanf("%d", &data);
                position = LocateListElem(pl, data);
                if (position)
                    printf("%d is at [%d] of the list.\n\n", data, position);
                else 
                   printf("%d is not in the list.\n\n", data);
                system("pause");
                break;
            case 5:
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (InsertListElem(pl, i, data))
                    printf("\n数据插入成功！\n\n");
                else 
                    printf("\n数据插入失败！\n\n");
                system("pause");
                break;
            case 6:
                printf("i=");
                scanf("%d", &i);
                if (DeleteListElem(pl, i))
                    printf("\n数据删除成功！\n\n");
                else
                    printf("\n数据删除失败！\n\n");
                system("pause");
                break;
            case 7:
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (UpdateListElem(pl, i, data))
                    printf("\n数据更新成功！\n\n");
                else
                    printf("\n数据更新失败！\n\n");
                system("pause");
                break;
            case 8:
                isRunning = 0;              
                break;
        }
    }
    
    printf("\n谢谢使用本程序");
    
    return 0;
}
