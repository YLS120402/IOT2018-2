#include <iostream>
#include "Headfile.h"
int main(void)
{
	RedType d[15] = { { 19, 0 }, { 38, 0 }, { 12, 0 }, { 40, 0 }, { 41, 0 }, { 39, 0 }, { 54, 0 }, { 76, 0 }, { 35, 0 }, { 47, 0 }, { 80, 0 }, { 14, 0 }, { 9, 0 }, { 44, 0 }, { 19, 0 } };
	int i, choice;
	SqList L;
menu:
	menu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (i = 0; i<N; i++)
			L.r[i + 1] = d[i];
		L.length = N;
		printf("\nÕÛ°ë²åÈëÅÅÐòÇ°:\n");
		print(L);
		BInsertSort(L);
		printf("ÕÛ°ë²åÈëÅÅÐòºó:\n");
		print(L);
		goto menu;


	case 2:
		for (i = 0; i<N; i++)
			L.r[i + 1] = d[i];
		L.length = N;
		printf("\nÃ°ÅÝÅÅÐòÇ°:\n");
		print(L);
		BubbleSort(L);
		printf("Ã°ÅÝÅÅÐòºó:\n");
		print(L);
		goto menu;
		break;
	case 3:
		HeapType h;
		for (i = 0; i<N; i++)
			h.r[i + 1] = d[i];
		h.length = N;
		printf("\n¶ÑÅÅÐòÇ°:\n");
		print_H(h);
		HeapSort(h);
		printf("¶ÑÅÅÐòºó:\n");
		print_H(h);
		goto menu;
		break;
	case 4:
		for (i = 0; i<N; i++)
			L.r[i + 1] = d[i];
		L.length = N;
		printf("¹é²¢ÅÅÐòÇ°:\n");
		print(L);
		MergeSort(L);
		printf("¹é²¢ÅÅÐòºó:\n");
		print(L);
		goto menu;
		break;
	case 5:;
	}

}
