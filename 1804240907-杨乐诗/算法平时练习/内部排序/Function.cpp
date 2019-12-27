#include "Headfile.h"
void menu()
{
	cout << "��ѡ��Ҫʹ�õ������㷨��\n1���۰��������\n";
	cout << "2��ð������\n3��������\n";
	cout << "4��2-·�鲢����\n5���˳�\n";
}
void BInsertSort(SqList &L)
{ //��˳���L���۰���������㷨10.2
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
		printf("��%d������\n",count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("\n");
		printf("\n");
	}//for
	printf("������%d��\n", count);
}//BInsertSort

void HeapAdjust(HeapType &H, int s, int m)   //�㷨10.10
{ //��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������ѵĶ��壬������
	//����H.r[s]�Ĺؼ���,ʹH.r[s..m]��Ϊһ���󶥶�(�����м�¼�Ĺؼ��ֶ���)
	RedType rc;
	int j;
	rc = H.r[s];
	for (j = 2 * s; j <= m; j *= 2)
	{                                     //��key�ϴ�ĺ��ӽ������ɸѡ
		if (j<m && H.r[j].key<H.r[j + 1].key)
			++j;                          //jΪkey�ϴ�ļ�¼���±�
		if (H.r[0].key >= H.r[j].key)
			break;                        //rcӦ������λ��s��
		H.r[s] = H.r[j];
		s = j;
	}
	H.r[s] = rc;                            //����
}

void HeapSort(HeapType &H)
{ //��˳���H���ж������㷨10.11
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
		printf("��%d������\n", count);
		for (j = 1; j <= H.length; j++)
			printf(" (%d,%d) ", H.r[j].key, H.r[j].otherinfo);

		printf("\n");
	}//for
	printf("������%d��\n", count);
}//HeapSort

void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{ //�������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] �㷨10.12
	int j, k, l;
	for (j = m + 1, k = i; i <= m&&j <= n; ++k)          //��SR�м�¼��С����ز���TR
		if (SR[i].key <= SR[j].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	if (i <= m)
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];           //��ʣ���SR[i..m]���Ƶ�TR
	if (j <= n)
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];       //��ʣ���SR[j..n]���Ƶ�TR


}
void MSort(RedType SR[], RedType TR1[], int s, int t)
{ //��SR[s..t]�鲢����ΪTR1[s..t]���㷨10.13
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
{ //��˳���L���鲢�����㷨10.14
	int count = 0;
	for (int i = 2; i <= L.length/2; ++i)
	{
		MSort(L.r, L.r, 1, L.length);
		count++;
		printf("��%d������\n", count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("\n");
	}
	printf("������%d��\n", count);
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
		printf("��%d������\n", count);
		for (int j = 1; j <= L.length; j++)
			printf(" (%d,%d) ", L.r[j].key, L.r[j].otherinfo);
		printf("������%d��\n",count);
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
