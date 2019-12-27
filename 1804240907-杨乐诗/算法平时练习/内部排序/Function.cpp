#include "Headfile.h"
void menu()
{
	cout << "请选择要使用的排序算法：\n1、折半插入排序\n";
	cout << "2、冒泡排序\n3、堆排序\n";
	cout << "4、2-路归并排序\n5、退出\n";
}
void BInsertSort(SqList &L)
{ //对顺序表L作折半插入排序。算法10.2
	int low, high, m, count = 0;
	for (int i = 2; i <= L.length; ++i){
		L.r[0] = L.r[i];
		low = 1;
		high = i - 1;
		while (low <= high){
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)
				high = m - 1;
			else
				low = m + 1;
		}//while
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
		count++;
		printf("第%d次排序\n",count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("\n");
		printf("\n");
	}//for
	printf("共排序%d次\n", count);
}//BInsertSort

void HeapAdjust(HeapType &H, int s, int m)   //算法10.10
{ //已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，本函数
	//调整H.r[s]的关键字,使H.r[s..m]成为一个大顶堆(对其中记录的关键字而言)
	RedType rc;
	int j;
	rc = H.r[s];
	for (j = 2 * s; j <= m; j *= 2)
	{                                     //沿key较大的孩子结点向下筛选
		if (j<m && H.r[j].key<H.r[j + 1].key)
			++j;                          //j为key较大的记录的下标
		if (H.r[0].key >= H.r[j].key)
			break;                        //rc应插入在位置s上
		H.r[s] = H.r[j];
		s = j;
	}
	H.r[s] = rc;                            //插入
}

void HeapSort(HeapType &H)
{ //对顺序表H进行堆排序。算法10.11
	int i,j=1,count=0;
	for (i = H.length / 2; i > 0; --i)
	{
		HeapAdjust(H, i, H.length);


	}
	for (i = H.length; i>1; --i){

		H.r[0] = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = H.r[0];
		HeapAdjust(H, 1, i - 1);
		count++;
		printf("第%d次排序\n", count);
		for (j = 1; j <= H.length; j++)
			printf(" (%d,%d) ", H.r[j].key, H.r[j].otherinfo);

		printf("\n");
	}//for
	printf("共排序%d次\n", count);
}//HeapSort

void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{ //将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] 算法10.12
	int j, k, l;
	for (j = m + 1, k = i; i <= m&&j <= n; ++k)          //将SR中记录由小到大地并入TR
		if (SR[i].key <= SR[j].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	if (i <= m)
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];           //将剩余的SR[i..m]复制到TR
	if (j <= n)
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];       //将剩余的SR[j..n]复制到TR


}
void MSort(RedType SR[], RedType TR1[], int s, int t)
{ //将SR[s..t]归并排序为TR1[s..t]。算法10.13
	RedType TR2[MAXSIZE];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		int m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}
void MergeSort(SqList &L)
{ //对顺序表L作归并排序。算法10.14
	int count = 0;
	for (int i = 2; i <= L.length/2; ++i)
	{
		MSort(L.r, L.r, 1, L.length);
		count++;
		printf("第%d次排序\n", count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("\n");
	}
	printf("共排序%d次\n", count);
}

void BubbleSort(SqList &L) {
	int count=0;
	for (int i = 1; i<L.length; i++) {
		for (int j = 2; j <= L.length; j++) {
			if (L.r[j - 1].key>L.r[j].key) {
				swap(L.r[j - 1].key, L.r[j].key);

			}

		}
		count++;
		printf("第%d次排序\n", count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("共排序%d次\n",count);
		printf("\n");
	}
}


void print(SqList L)
{
	int i;
	for (i = 1; i <= L.length; i++)
		printf(" (%d,%d) ", L.r[i].key, L.r[i].otherinfo);
	printf("\n");
}

void print_H(HeapType H)
{
	int i;
	for (i = 1; i <= H.length; i++)
		printf("(%d,%d)", H.r[i].key, H.r[i].otherinfo);
	printf("\n");
}
