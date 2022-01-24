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
	
	printf("BubbleSort 동작\n");
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
	printf("SelectionSort 동작\n");
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
	printf("InsertionSort 동작\n");
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
	// 도우미 함수 동작 확인
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
		// memcpy(배열 , 원본 ,넣을 개수)
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블랜덤");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// memcpy(배열 , 원본 ,넣을 개수)
		chkTimeLap(Selectionsort, workArr, DATA_SIZE, "선택랜덤");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		// memcpy(배열 , 원본 ,넣을 개수)
		chkTimeLap(Insertionsort, workArr, DATA_SIZE, "삽입랜덤");
	}
	*/
	//--------------------------------------------------------------
	/*
	printf("\nWORST vs BEST\n");
	{
		//랜덤 배열
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE); // #1 랜덤
		genIncSorted(srcArr, DATA_SIZE); // #2 이미 오름차순정렬  //버블 삽입 빨라짐 선택 변함없음
		genDecSorted(srcArr, DATA_SIZE); // #3 역정렬 // 버블 삽입 느려짐 선택 변함없음
		int workArr[DATA_SIZE];

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블역정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(Selectionsort, workArr, DATA_SIZE, "선택역정렬");

		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
		chkTimeLap(Insertionsort, workArr, DATA_SIZE, "삽입역정렬");

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

		//printArr(workArr, DATA_SIZE); // 정렬전
		chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙정렬");
		//printArr(workArr, DATA_SIZE); // 정렬후

		heap_destroy(&hp);
	}
	*/

	
	//----------------------------------------------
	printf("\n QuickSort 동작 확인 \n");
	{
		//int arr[] = { 40,50,-30,-11,-333,349,23 };
		int arr[] = { 5,1,3,7,9,2,4,6,8 };
		//int arr[] = { 40,20,-30,-11,-333,39,23 };
		int len = sizeof(arr) / sizeof(int);

		printArr(arr, len); // 퀵 정렬 전
		QuickSort(arr, 0, len - 1); // 초기 left right
		printArr(arr, len); // 퀵 정렬 후 -> -333 -30 -11 23 40 50 349
	}
	

	/*
	// 퀵 정렬
	printf("\n QuickSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int)* DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // 정렬전
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 랜덤");
		//printArr(workArr, DATA_SIZE); // 정렬후

		genIncSorted(workArr, DATA_SIZE); //이미 오름차순 정렬 배열
		chkTimeLap(QuickSortMain, workArr, DATA_SIZE, "퀵정렬 오름차순");
		// 오름차순은 퀵소트 에서 최악이기 때문에 DATA_SIZE가 커지면
		// 재귀호출을 계속계속 부르다가 컴퓨터의 스택이 가득 차서 결국 값이 안나오고
		// 찾다가 멈춰버린다.

	}
	*/
}
