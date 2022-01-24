#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"9d-QuickSort.h"


// 배열 두개 값 바꾸기
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


//배열 정렬 영역 쪼개기 (쪼갤 index 리턴 <-- pivot)
int Partition(int arr[], int left, int right) {
	
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽! (값)
	int low = left + 1; // low는 피벗 오른쪽부터 시작(인덱스)
	int high = right; // high는 right 부터 시작(인덱스)

	// TODO

	while(low <= high) // low, high가 교차되지 않을 때까지 반복하면서 low, high 이동
	{
		// low 우측으로 계속이동, pivot보다 큰 것을 만날 때 까지
		while(pivot >= arr[low] && low <= right){
			low++;
		}
		// high 좌측으로 계속이동, pivot보다 작은 것을 만날 때 까지
		while (pivot <= arr[high] && high >= (left+1)) {
			high--;
		}
		// low와 high가 멈추면
		// low, high가 교차되지 않은 상태라면 Swap 진행
		if(low <= high)
			Swap(arr, low, high);

	}
	// '피벗(left)' 과 'high'가 가리키는 대상 교환
	Swap(arr, left, high);
	// Swap이 끝나는 이 시점에서 
	// high의 우측은 pivot보다 큰값들이 모여있고,
	// high의 좌측은 pivot보다 작은값들이 모여있다.
	return high; // 정해진 피벗의 위치정보(인덱스) 리턴 --> Swap으로 high랑 pivot이 바뀌었으니까
}

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right)
{
	if (left <= right) {
		int pivot = Partition(arr, left, right); // pivot 정하고 둘로 쪼갬
		// pivot 왼쪽 영역을 퀵정렬
		printf("왼쪽 재귀 %d\n", arr[pivot]);
		QuickSort(arr, left, pivot - 1);
		// pivot 오른쪽 영역을 퀵정렬
		printf("오른쪽 재귀 %d\n", arr[pivot]);
		QuickSort(arr, pivot+1, right);
	}
}

// 성능테스트용
void QuickSortMain(int arr[], int n) {
	QuickSort(arr, 0, n - 1);
}