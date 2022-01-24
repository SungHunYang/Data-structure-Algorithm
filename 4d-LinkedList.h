#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_
#define TRUE 1
#define FALSE 0

/*
*	LinkedList 의 ADT
*
*	장점: 삽입, 삭제 유리
*	단점: 조회에 불리
*
*	단점: ArrayList에 비해 용량 UP
*/


/*LIST의 데이터*/
typedef int Data;

// 노드타입 정의
typedef struct _Node{
	// 노드 데이터
	Data data;

	// 다음 노드의 포인터
	struct _Node* pNext;

}node;
// Linked List 타입 정의
typedef struct _linkedList {
	// 시작 노드
	node* pHead;
	// 끝 노드
	node* pTail;
	// iteration
	node* pCurrent;
	// 노드의 개수
	int numData;
}LinkedList;

typedef LinkedList List;

/*LIST의 동작*/


// 리스트 초기화
void list_init_(List* pList);

// 리스트 제거
void list_destroy(List* pList);

// 데이터 추가
int list_add(List* pList, Data data);

// n번째 데이터 수정
int list_set(List* pList, int n, Data data);

// 데이터 개수
int list_length(List* pList);

// 데이터 조회, iteration 초기화
void list_init_iter(List* pList);

// 데이터 조회, iteration 다음 데이터 추출
Data list_next(List* pList);

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List* pList);
// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data* pData);

// n번째 데이터 삭제
int list_remove(List* pList, int n);

// n번째 위치의 데이터 삽입
int list_insert(List* pList, int n, Data data);

// 주어진 pList 에서 data가 담긴 Node를 찾아서 return, 없으면 NULL리턴
node* list_search(List* pList, Data data);


#endif
