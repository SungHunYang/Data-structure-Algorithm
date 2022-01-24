#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"8d-sort.h"
#include"7d-Heap.h"

void printArr(int arr[], int n) {

	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b]\n"); // \b 백스페이스 해서 마지막에 , 안나오게 하는거.
}

// sort의 성능 테스트를 위한 여러가지의 배열

void genRandom(int arr[], int n) // 무작위 배열 1~n 범위
{
	genIncSorted(arr, n); // 그냥 오름차순 하나 가져와서
	shuffleArr(arr, n); // 섞으면 무작위 배열
}
void genIncSorted(int arr[], int n) // 오름차순 배열 생성
{
	for (int i = 0; i <= n; i++) {
		arr[i] = i + 1; // 1부터 n까지의 값을 넣는다.
	}
}
void genDecSorted(int arr[], int n) // 내림차순 배열 생성
{
	for (int i = 0; i < n; i++) {
		arr[i] = n-i; // n부터 1까지의 값을 넣는다.
	}
}
void shuffleArr(int arr[], int n) // 배열 섞기
{
	srand(time(NULL));
	if (n > 1) { // 배열길이 2개 이상인 경우만 shuffle
		for (int i = 0; i < n-1; i++) {
			// i번째와 오른쪽의 임의의 j번쨰와 swap 
			// 원래 rand의 범위가 RAND_MAX 까지 인데 / (n - i) + 1 이걸 통해서
			// 범위를 n에서 i사이로 한정시킨거다.
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;

		}

	}
}

//----------------------------------------------------------

// 성능 체크
void chkTimeLap(fnSort sort, int arr[], int n, char* szTitle)
{
	clock_t start, end;
	start = clock();

	sort(arr, n);

	end = clock();
	printf("%s (size: %d) 수행결과 : %ld ms\n", szTitle, n, end - start);

}

//-------------------------------------------

void BubbleSort(int arr[], int n)// 버블정렬
{
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < (n-i)-1; j++) { // 첫 cycle에는 n-1비교 그 다음부터 n-2.. n-3.. 이런식
			//for문 안에 for문 O(n^2)이다.
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];	//<<이동>> 한사이클당 최대 (n-i)-1번 발생
				arr[j + 1] = arr[j]; //<<이동>>
				arr[j] = temp;		//<<이동>>
			}
		}
	}
}
void Selectionsort(int arr[], int n) // 선택정렬
{
	int temp;
	int min_idx;

	for (int i = 0; i < n - 1; i++) {
		min_idx = i;
		for (int j = i+1; j < n; j++) {
			//for문 안에 for문 O(n^2)이다.
			if (arr[min_idx] > arr[j]) { //기존의 min_idx번째 보다 작은 값이면 <<비교>>
				min_idx = j;  // min_idx를 바꿔준다.
			}
		}
		if(i!=min_idx){				// <<이동>> <-- 1 cycle당 많아야 1번 발생
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
		// 중간단계출력
		//printArr(arr, n);
	}
}
void Insertionsort(int arr[], int n) // 삽입정렬
{
	int i, j;
	int insData;
	for (i = 1; i < n; i++)   // i = 1부터 시작!
	{
		insData = arr[i];   // i번째 데이터는 insData에 임시 저장
		for (j = i - 1; j >= 0; j--)  // i 왼쪽부터 왼쪽으로 검색
		{
			if (arr[j] > insData)   // insData 보다  j번째 데이터가 크면 <<비교>>
				arr[j + 1] = arr[j];    // j번째 데이터를 우측으로 이동 <<이동>>
				// 왼쪽이 이미 정렬되어있으니까
				// temp없이 이게 가능하다. 바꿀값은 insData에 있으므로
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}
		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입! <<이동>>
	}
}


