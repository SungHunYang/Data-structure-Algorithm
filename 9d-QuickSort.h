#ifndef __QUICKSORT_H_
#define __QUICKSORT_H_

// 배열 두개 값 바꾸기
void Swap(int arr[], int idx1, int idx2);


//배열 정렬 영역 쪼개기 (쪼갤 index 리턴 <-- pivot)
int Partition(int arr[], int left, int right);

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right);

void QuickSortMain(int arr[], int n); // 성능테스트용
#endif