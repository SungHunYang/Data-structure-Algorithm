#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "4d-LinkedList.h"

// 리스트 초기화
void list_init_(List* pList) {
	// head, dummy node 생성
	pList->pHead = (node*)malloc(sizeof(node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead; //최초에는 tail과 head 동일
	pList->numData = 0;

	//printf("리스트 초기화\n");
}


// 데이터 추가
int list_add(List* pList, Data data) {
	node* pNewNode = (node*)malloc(sizeof(node));
	memset(pNewNode, 0, sizeof(node));
	pNewNode->data = data;

	// tail이 가르키던 node의 next를 새로운 node에 연결
	pList->pTail->pNext = pNewNode;
	
	// tail 이동
	pList->pTail = pNewNode;
	(pList->numData)++; // 데이터 개수 +1 증가

	return TRUE;
}

// n번째 데이터 수정
int list_set(List* pList, int n, Data data) {

	if (n >= pList->numData) return FALSE;
	// head 부터 시작해서 n번째 노드 찾기, iteration 사용
	list_init_iter(pList);
	int i = 0; // 현재 몇번째 노드?
	while (list_hasNext(pList)) {
		list_next(pList);
		if (i >= n)break; //n번째 노드 찾음!
		i++;
	}
	// 위 while 문이 끝나면 pCurrent는 n번째 노드를 가리키고 있음
	//printf("%d 번째 데이터 수정 %d --> %d\n", n, pList->pCurrent->data, data);
	pList->pCurrent->data = data; // 데이터 수정
	return TRUE;
}

// 데이터 개수
int list_length(List* pList) {
	return pList->numData;
}

// 데이터 조회, iteration 초기화
void list_init_iter(List* pList) {
	// pCurrent 도 dummy node에서 부터 시작
	pList->pCurrent = pList->pHead;
}

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List* pList) {
	pList->pCurrent = pList->pCurrent->pNext; // 우선 current를 한발 앞으로 이동
	return pList->pCurrent->data;
}

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List* pList) {
	if (pList->pCurrent->pNext == NULL) // '다음노드' 존재여부체크
		return FALSE;
	return TRUE;
}
// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data* pData) {
	if (n >= pList->numData)return FALSE;
	// head 부터 시작해서 n번째 노드 찾기, iteration 사용
	list_init_iter(pList);
	int i = 0; // 현재 몇번째 노드?
	while (list_hasNext(pList)) {
		list_next(pList);
		if (i >= n)break; //n번째 노드 찾음!
		i++;
	}
	// n번째 데이터를 매개변수에 담아줌
	*pData = pList->pCurrent->data;
	return TRUE;
}

// n번째 데이터 삭제
int list_remove(List* pList, int n) {

	if (n >= pList->numData) return FALSE;
	// n번째 노드 삭제하려면
	// n번째 뿐 아니라 n-1 번째 노드 정보도 알아야 한다
	// 즉. 이전 노드(previous node) 또한 알아야 한다.

	list_init_iter(pList);
	int i = 0; // 현재 몇번째 노드?
	node* pPrev = NULL; // 이전노드를 가르킬 포인터
	while (list_hasNext(pList)) {
		// pCurrent 를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
		pPrev =pList->pCurrent;

		list_next(pList);
		if (i == n)break; //n번째 노드 찾음!
		i++;
	}
	// 위 while 문이 끝나면 
	// pCurrent 는 n번째 노드를, 
	// pPrev 는 n-1번째 노드를 가리키고 있다

	// 순서 잘 생각해야 한다.  순서 바뀌면 엉망된다.
	
	// 삭제 진행
	pPrev->pNext = pList->pCurrent->pNext;
	// 이게 pPrev -> pCurrent -> pFuter 이렇게 되어있는 상태인데
	// 내가 삭제하려고 하는데 pCurrent 값이야 알겠어?
	// 그리고 pCurrent->pNext는 pFuter를 가르키고 있다.
	// 그래서 pPrev->pNext 에 pCurrent->pNext 즉 pFuter를 넣고
	// pCurrent가 삭제 되면 pPrev -> pFuter 이렇게 되는 거지

	// 만약 tail이 삭제할 노드 였다면 tail 값도 수정해야 한다.
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev; // tail을 이전 노드로 이동
	//printf("%d 번째 데이터 %d 삭제\n", n, pList->pCurrent->data);
	free(pList->pCurrent);
	pList->numData--;

	return TRUE;
}

// n번째 위치의 데이터 삽입
// 맨뒤에 삽입(추가) 하는 것도 허용
int list_insert(List* pList, int n, Data data) {
	if (n > pList->numData) return FALSE; // >=이 아니라 > 이다!
	
	// 새로운 노드 생성
	node* pNewNode = (node*)malloc(sizeof(node));
	memset(pNewNode, 0, sizeof(node));
	// 이거 memset 은근 헷갈려서 덧 붙이자면 여기 개수 N개를 안넣어 줬으니까
	// 제일 처음 값인 data만 0으로 설정되는거다. 
	// 두번째 pNext는 말고
	pNewNode->data = data;

	// 1. 첫번째 데이터 이거나
	// 2. 맨끝에 추가하면

	if (pList->numData == 0 || n == pList->numData) {
		// add() 와 동일
		pList->pTail->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else {
		// 3. n번째 노드에 삽입하려면
		// n-1번째 노드, 직전노드(previous node) 또한 알아야 한다.

		list_init_iter(pList);
		int i = 0; // 현재 몇번째 노드?
		node* pPrev = NULL; // 이전노드를 가르킬 포인터
		while (list_hasNext(pList)) {
			// pCurrent 를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
			pPrev = pList->pCurrent;

			list_next(pList);
			if (i == n)break; //n번째 노드 찾음!
			i++;
		}
		// 삽입동작 수행
		// 이전노드는 새로운 노드를 가리키고
		pPrev->pNext = pNewNode;
		// 새로운 노드는 기존의 n번째 노드를 가리키면 된다.
		pNewNode->pNext = pList->pCurrent;
		
	}
	//printf("[%d] 번째 데이터 %d 삽입\n", n, data);
	(pList->numData)++; //데이터 증가
	return TRUE;
}

// 리스트 제거
void list_destroy(List* pList) {

	list_init_iter(pList);
	
	node* pPrev = NULL; // 이전노드를 가르킬 포인터
	while (list_hasNext(pList)) {
		// pCurrent 를 이동하기 전에 pCurrent 값을 '이전 노드'로 기억해두어야 한다.
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev); //노드 삭제
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	//printf("[ LIST DESTROY ]\n");

}


// 탐색
node* list_search(List* pList, Data data) {
	pList->pCurrent = pList->pHead; // head 부터 검색
	while (pList->pCurrent->pNext != NULL) {
		pList->pCurrent = pList->pCurrent->pNext; //더미 노드 때문에 한발 나가서 시작
		if (pList->pCurrent->data == data) {
			return pList->pCurrent; // 찾으면 해당 노드 리턴
		}
	}
	return NULL; // 없으면 NULL 리턴

}