#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MaxSize 100
#define ElemType int
#define Status int
using namespace std;
//˳������ݽṹ
typedef struct
{
	ElemType data[MaxSize];//˳���Ԫ��
	int length;            //˳���ǰ����
}SqList;
//��ʼ��˳�����������һ���յ�˳���
Status InitList(SqList &L)
{
	memset(L.data,0,sizeof(L));//��ʼ������Ϊ0
	L.length=0;//��ʼ������Ϊ0
	return 0;
}
//����˳����� ��ʼ��ǰn������
bool CreatList(SqList &L,int n)
{
	if(n<0||n>MaxSize)false;//n�Ƿ�
	for(int i=0;i<n;i++)
	{
		scanf("%d",&L.data[i]);
		L.length++;
	}
	return true;
}
//���뺯�� λ��i�������� i��֮��Ԫ�غ���  1=<i<=length+1
bool InsertList(SqList &L,int i,ElemType e)
{
	if(i<1||i>L.length+1)
     {
		printf("λ����Ч������\n");
    	return false;
	 }
	if(L.length>=MaxSize)//�жϴ洢�ռ��Ƿ�����
	{
		printf("��ǰ�洢�ռ�����������\n");
		return false;
	}
	for(int j=L.length;j>=i;j--)//λ��i��֮��Ԫ�غ���
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}
//ɾ������ ɾ��λ��i��Ԫ�� i֮���Ԫ������ǰ��
bool  ListDelete(SqList &L,int i)
{
	if(i<1||i>L.length)
     {
		printf("λ����Ч������\n");
    	return false;
	 }
	for(int j=i;j<=L.length-1;j++)//λ��i֮��Ԫ������ǰ�Ƹ���
	{
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return true;
}
//���Һ��� ��λ�ô�С������ҵ�һ��ֵ����e��Ԫ�� ������λ��
int LocateElem(SqList L,ElemType e)
{
 for(int i=0;i<L.length;i++)//�ӵ�λ�ò���
	{
		if(L.data[i]==e)
			return i+1;
	}
 return 0;

}
//������ܺ��� ��λ�ô�С�������˳�������Ԫ��
void PrintList(SqList L)
{
	printf("��ǰ˳�������Ԫ��:");
	for(int i=0;i<L.length;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
}
//����˳�����
void Create(SqList &L)
{
	int n;bool flag;
	printf("������Ҫ������˳�����:");
	scanf("%d",&n);
	printf("������%d�������ո������:",n);
	flag=CreatList(L,n);
	if(flag){
		printf("�����ɹ���\n");
		PrintList(L);
	}
	else printf("���볤�ȷǷ���\n");

}
//���빦�ܺ��� ����InsertList���˳���Ԫ�ز��� ����PrintList������ʾ����ɹ���Ľ��
void Insert(SqList &L)
{
  int place;ElemType e;bool flag;
  printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
  scanf("%d%d",&place,&e);
  flag=InsertList(L,place,e);
  if(flag)
  {
	printf("����ɹ�������\n");
	PrintList(L);
  }
}
//ɾ�����ܺ��� ����ListDelete�������˳����ɾ�� ����PrintList������ʾ����ɹ���Ľ��
void Delete(SqList &L)
{
  int place;bool flag;
  printf("������Ҫɾ����λ��(��1��ʼ):\n");
  scanf("%d",&place);
  flag=ListDelete(L,place);
  if(flag)
  {
	printf("ɾ���ɹ�������\n");
	PrintList(L);
  }
}
//���ҹ��ܺ��� ����LocateElem����Ԫ��
void Search(SqList L)
{
  ElemType e;
  int flag;
  printf("������Ҫ���ҵ�ֵ:\n");
  scanf("%d",&e);
  flag=LocateElem(L,e);
  if(flag)
  {
	printf("��Ԫ��λ��Ϊ:%d\n",flag);
  }
  else
	  printf("δ�ҵ���Ԫ�أ�\n");
}
//�ϲ�����˳���
void Exchange(SqList *A,SqList *B,SqList *L)
{
    int i=0,j=0,k=0;
    SqList M,N,P;
     A=&M;
     B=&N;
     L=&P;
    printf("�봴������˳���:\n");
    InitList(M);
    Create(M);
    InitList(N);
    Create(N);
    while(i<A->length&&j<B->length)
    {
        if(A->data[i]<B->data[j])
            L->data[k++]=A->data[i++];
        else if(A->data[i]>B->data[j])
            L->data[k++]=B->data[j++];
    }
    while(i<A->length)
        L->data[k++]=A->data[i++];
    while(j<B->length)
        L->data[k++]=B->data[j++];

    L->length=k;
    printf("�ϲ��ɹ�\n");
    PrintList(P);

}
//����˳���
void DestroyList(SqList &L)
{
    delete[]L.data;
    L.length=0;
}
void menu()
{
   printf("***************MENU**************\n");
   printf("********1.����    2.����*********\n");
   printf("********3.ɾ��    4.����*********\n");
   printf("********5.���    6.�ϲ�*********\n");
   printf("********7.����    8.�˳�*********\n");
   printf("*********************************\n");
}
int main()
{
 SqList L;
 SqList C,D;
 int choice;
 InitList(L);
 while(1)
 {
  menu();
  printf("��ѡ��\n");
  scanf("%d",&choice);
  while(8==choice) break;
  switch(choice)
  {
  case 1:Create(L);break;
  case 2:Insert(L);break;
  case 3:Delete(L);break;
  case 4:Search(L);break;
  case 5:PrintList(L);break;
  case 6:Exchange(&C,&D,&L);break;
  case 7:DestroyList(L);break;
  default:printf("������󣡣���\n");break;
  }
 }
 return 0;
}
