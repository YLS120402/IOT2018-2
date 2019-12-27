#ifndef HEADFILE_H_INCLUDED
#define HEADFILE_H_INCLUDED
#define T 3
#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<math.h> // floor(),ceil(),abs()
#include<iostream> // cout,cin
using  namespace std;
#define MAXSIZE 20
#define N 15

typedef int KeyType;    //����ؼ�������Ϊ����
typedef int InfoType;   //�������������������

typedef struct
{
	KeyType key;       //�ؼ�����
	InfoType otherinfo;//����������
}RedType;              //��¼����
typedef struct
{
	RedType r[MAXSIZE + 1];//r[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;//˳�������
typedef SqList HeapType; // �Ѳ���˳���洢��ʾ
void menu();//�˵�

//�۰��������
void BInsertSort(SqList &L);

void HeapAdjust(HeapType &H, int s, int m);
void HeapSort(HeapType &H);

//�鲢����
void Merge(RedType SR[], RedType TR[], int i, int m, int n);
void MSort(RedType SR[], RedType TR1[], int s, int t);
void MergeSort(SqList &L);

void BubbleSort(SqList &L);
void print(SqList L);
void print_H(HeapType H);


#endif // HEADFILE_H_INCLUDED
