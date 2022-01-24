#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"8d-sort.h"
#include"7d-Heap.h"
#include"9d-QuickSort.h"

#define DATA_SIZE 20000

void main() {

	/*
	int length;
	
	printf("BubbleSort ����\n");
	{
		int data[] = { 3,2,7,5,1 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);
		printArr(data, length); // 1,2,3,5,7
	}
	{
		int data[] = { 11,3,28,43,9,4 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);
		printArr(data, length);
	}
	printf("\n");
	printf("SelectionSort ����\n");
	{
		int data[] = { 29,10,14,37,13 };
		length = sizeof(data) / sizeof(int);
		Selectionsort(data, length);
		printArr(data, length); // 10,13,14,29,37
	}
	{
		int data[] = { 11,3,28,43,9,4 };
		length = sizeof(data) / sizeof(int);
		Selectionsort(data, length);
		printArr(data, length);
	}
	printf("\n");
	printf("InsertionSort ����\n");
	{
		int data[] = { 29,10,14,37,13 };
		length = sizeof(data) / sizeof(int);
		Insertionsort(data, length);
		printArr(data, length); // 10,13,14,29,37
	}
	{
		int data[] = { 11,3,28,43,9,4 };
		length = sizeof(data) / sizeof(int);
		Insertionsort(data, length);
		printArr(data, length);
	}
	*/

	//---------------------------------------------------------------
	/*
	// ����� �Լ� ���� Ȯ��
	{
		int srcArr[10];
		genIncSorted(srcArr, 10);
		printArr(srcArr, 10);
		genDecSorted(srcArr, 10);
		printArr(srcArr, 10);
		genRandom(srcArr, 10);
		printArr(srcArr, 10);

	}
	*/

	/*
	printf("\nTime Complexity\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// memcpy(�迭 , ���� ,���� ����)
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// memcpy(�迭 , ���� ,���� ����)
		chkTimeLap(Selectionsort, workArr, DATA_SIZE, "���÷���");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// memcpy(�迭 , ���� ,���� ����)
		chkTimeLap(Insertionsort, workArr, DATA_SIZE, "���Է���");
	}
	*/
	//--------------------------------------------------------------
	/*
	printf("\nWORST vs BEST\n");
	{
		//���� �迭
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE); // #1 ����
		genIncSorted(srcArr, DATA_SIZE); // #2 �̹� ������������  //���� ���� ������ ���� ���Ծ���
		genDecSorted(srcArr, DATA_SIZE); // #3 ������ // ���� ���� ������ ���� ���Ծ���
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(Selectionsort, workArr, DATA_SIZE, "���ÿ�����");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(Insertionsort, workArr, DATA_SIZE, "���Կ�����");

	}
	*/

	//--------------------------------------------------------------
	/*
	printf("\nHeapSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);
		
		Heap hp;
		heap_init(&hp, DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // ������
		chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");
		//printArr(workArr, DATA_SIZE); // ������

		heap_destroy(&hp);
	}
	*/

	
	//----------------------------------------------
	printf("\n QuickSort ���� Ȯ�� \n");
	{
		//int arr[] = { 40,50,-30,-11,-333,349,23 };
		int arr[] = { 5,1,3,7,9,2,4,6,8 };
		//int arr[] = { 40,20,-30,-11,-333,39,23 };
		int len = sizeof(arr) / sizeof(int);

		printArr(arr, len); // �� ���� ��
		QuickSort(arr, 0, len - 1); // �ʱ� left right
		printArr(arr, len); // �� ���� �� -> -333 -30 -11 23 40 50 349
	}
	

	/*
	// �� ����
	printf("\n QuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // ������
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ����");
		//printArr(workArr, DATA_SIZE); // ������

		genIncSorted(workArr, DATA_SIZE); //�̹� �������� ���� �迭
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "������ ��������");
		// ���������� ����Ʈ ���� �־��̱� ������ DATA_SIZE�� Ŀ����
		// ���ȣ���� ��Ӱ�� �θ��ٰ� ��ǻ���� ������ ���� ���� �ᱹ ���� �ȳ�����
		// ã�ٰ� ���������.

	}
	*/
}
