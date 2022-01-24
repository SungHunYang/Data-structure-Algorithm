#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListBaseStack.h"
#include "6d-BinaryTree.h"
// 스택 초기화
void stack_init(Stack* pStack) {
	pStack->pTop = NULL;
}

// 스택 제거
void stack_destroy(Stack* pStack) {
	// stack이 다 비어질때까지 전부 pop 시키면 된다.

	while (!stack_is_empty(pStack)) {
		stack_pop(pStack, NULL);
	}
}

// 스택이 비었는지 확인
int stack_is_empty(Stack* pStack) {
	if (pStack->pTop == NULL) return SUCCESS; // 비어 있으면 '참'

	return FAIL;
}

// push : top에 데이터 추가
int stack_push(Stack* pStack, Data data) {
	// 새로운 노드 생성
	node* pNewNode = (node*)malloc(sizeof(node));
	pNewNode->data = data;
	
	// 노드를 스택에 추가
	pNewNode->pNext = pStack->pTop;
	// top은 새로이 push된 노드를 가리킨다.
	pStack->pTop = pNewNode;

	return SUCCESS;
}

// pop : top의 데이터 꺼내기
int stack_pop(Stack* pStack, Data* pData) {

	if (stack_is_empty(pStack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	// 삭제할 노드 기억
	node* deleteNode = pStack->pTop;

	if (pData != NULL) {
		*pData = pStack->pTop->data; // 데이터 읽기(꺼내기)
	}

	pStack->pTop = pStack->pTop->pNext; // top 이동

	free(deleteNode); // pop된 노드 제거

	return SUCCESS;
}

// peek : top의 데이터 미리보기
int stack_peek(Stack* pStack, Data* pData) {
	if (stack_is_empty(pStack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	if (pData != NULL) {
		*pData = pStack->pTop->data; // 데이터 읽기(꺼내기)
	}
	return SUCCESS;

}

