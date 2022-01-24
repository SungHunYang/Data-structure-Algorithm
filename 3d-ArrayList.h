#ifndef __ARRAY_LIST_H_
#define __ARRAY_LIST_H_
#define SUCCESS 1
#define FAIL 0
/*
*	ArrayList 의 ADT
*
*	ArrayList 의
*	장점 : n번째 조회 빠르다
*	단점 : 삭제, 삽입 느리다.
*
*	장점 : 용량
*/

/* ArrayList의 데이터*/
#define LIST_LEN 8

typedef int Data; // 데이터는 int
// int Data로 안한 이유가 Data의 타입이 바뀌었을때 어디에서든 적용 가능 하게 하려고
// 만일 int Data로 하면 int가 char로 바뀌면 하나하나 쓰인곳 다 바꿔야 하기 때문이다.
//그런데 typedef int Data 하면 여기만 바뀌면 나머지 쓰인곳 자동으로 바뀐다.

typedef struct _ArrayList {
	Data arr[LIST_LEN];// 데이터(들)
	int numData;// 리스트안의 데이터 개수
	int curPosition;// iteration
}ArrayList;

typedef ArrayList List;


/* ArrayList의 동작*/

// 리스트 초기화
void list_init_(List* pList);

// 리스트 제거
void list_destroy(List* pList);

// 데이터 추가
int list_add(List* pList, Data data);

// n번째 데이터 수정
int list_set(List* pList,int n,Data data);

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

#endif

