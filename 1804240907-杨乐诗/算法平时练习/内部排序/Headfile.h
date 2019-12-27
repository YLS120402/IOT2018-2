#ifndef HEADFILE_H_INCLUDED
#define HEADFILE_H_INCLUDED
#define T 3
#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()等
#include<stdio.h> // EOF(=^Z或F6),NULL
#include<stdlib.h> // atoi()
#include<math.h> // floor(),ceil(),abs()
#include<iostream> // cout,cin
using  namespace std;
#define MAXSIZE 20
#define N 15

typedef int KeyType;    //定义关键字类型为整型
typedef int InfoType;   //定义其它数据项的类型

typedef struct
{
	KeyType key;       //关键字项
	InfoType otherinfo;//其他数据项
}RedType;              //记录类型
typedef struct
{
	RedType r[MAXSIZE + 1];//r[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;//顺序表类型
typedef SqList HeapType; // 堆采用顺序表存储表示
void menu();//菜单

//折半插入排序
void BInsertSort(SqList &L);

void HeapAdjust(HeapType &H, int s, int m);
void HeapSort(HeapType &H);

//归并排序
void Merge(RedType SR[], RedType TR[], int i, int m, int n);
void MSort(RedType SR[], RedType TR1[], int s, int t);
void MergeSort(SqList &L);

void BubbleSort(SqList &L);
void print(SqList L);
void print_H(HeapType H);


#endif // HEADFILE_H_INCLUDED
