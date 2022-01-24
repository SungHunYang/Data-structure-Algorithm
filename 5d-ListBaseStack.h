#ifndef __STACK_H_
#define __STACK_H_
#define SUCCESS 1
#define FAIL 0

/* 스택의 데이터*/
typedef int Data;

typedef struct _node {
	Data data;
	struct _node* pNext;
}node;

typedef struct _listStack {
	node* pTop; // 이번 예제에선 numData는 사용안함

}ListStack;

typedef ListStack Stack;

/* 스택의 동작 */

// 스택 초기화
void stack_init(Stack *pStack);

// 스택 제거
void stack_destroy(Stack* pStack);

// 스택이 비었는지 확인
int stack_is_empty(Stack* pStack);

// push : top에 데이터 추가
int stack_push(Stack* pStack, Data data);

// pop : top의 데이터 꺼내기
int stack_pop(Stack* pStack, Data *pData); 
// 여기서 선언 할 때는 이름 굳이 없어도 선언 가능
// int stack_pop(Stack* , Data *); 이거 문제 없음

// peek : top의 데이터 미리보기
int stack_peek(Stack* pStack, Data* pData);


#endif