#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "3d-ArrayList.h"


// 리스트 초기화
void list_init_(List* pList) {
	pList->numData = 0;
	pList->curPosition = -1; // itertation
	memset(pList->arr, 0, sizeof(pList->arr)); // 배열을 전부 0으로 초기화
	printf("LIST 초기화\n");
}

// 리스트 제거
void list_destroy(List* pList) {
	pList->numData = 0;
	printf("리스트 제거\n");
}

// 데이터 추가
int list_add(List* pList, Data data) {
	if (pList->numData >= LIST_LEN) {
		printf("DATA FULL [ %d ] \n",data);
		return FAIL;
	}
	pList->arr[pList->numData] = data; // 데이터 추가
	printf("(%d) 번째 데이터 [ %d ] 추가\n", pList->numData, data);
	pList->numData++; // 데이터 개수 증가
	return SUCCESS;
}

// n번째 데이터 수정
int list_set(List* pList, int n, Data data);

// 데이터 개수
int list_length(List* pList) {
	return pList->numData;
}

// 데이터 조회, iteration 초기화
void list_init_iter(List* pList) {
	pList->curPosition = -1;

}

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List* pList);

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List* pList) {
	if (pList->curPosition++ <= pList->numData) {
		return SUCCESS;
	}
	return FAIL;
}


// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data* pData) {
	if (n >= pList->numData) {
		return FAIL;
	}
	*pData = pList->arr[n]; // n번쨰 데이터값을 pData를 통해 전달! call by reference
	return SUCCESS;
}

// n번째 데이터 삭제
int list_remove(List* pList, int n) {
	if (n >= pList->numData) {
		printf("[%d] 번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	// 배열이니까, 중간의 데이터를 삭제하면 뒤의 것들을 당겨와야함.

	for (int i = n; i < pList->numData-1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->numData--;
	printf("%d번째 데이터 삭제\n", n);
	return SUCCESS;
}


// n번째 위치의 데이터 삽입
int list_insert(List* pList, int n, Data data) {
	if (pList->numData >= LIST_LEN) {
		printf("FULL\n");
		return FAIL;
	}
	for (int i = pList->numData ; i > n; i--) {
		pList->arr[i] = pList->arr[i-1];
	}
	if (pList->numData < n) {
		pList->numData = n;
	}
	else {
		pList->numData++;
	}
	pList->arr[n] = data;
	return SUCCESS;
}