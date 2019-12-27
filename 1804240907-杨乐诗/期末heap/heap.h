#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define MAXDATA 1000 /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */

typedef int ElementType;
typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode
{
    ElementType *Data; /* �洢Ԫ�ص����� */
    int Size;          /* ���е�ǰԪ�ظ��� */
    int Capacity;      /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */

MaxHeap CreateHeap( int MaxSize );  //������һ���յ����ѡ�
bool IsFull( MaxHeap H );    //���ж�����H�Ƿ�������
bool Insert( MaxHeap H, ElementType item );  //����Ԫ��item��������H��
bool IsEmpty( MaxHeap H );   //���ж�����H�Ƿ�Ϊ�ա�
ElementType DeleteMax( MaxHeap H ); //������H�����Ԫ��(�����ȼ�)��



#endif // HEAP_H_INCLUDED
