#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListBaseStack.h"
#include "6d-BinaryTree.h"
// ���� �ʱ�ȭ
void stack_init(Stack* pStack) {
	pStack->pTop = NULL;
}

// ���� ����
void stack_destroy(Stack* pStack) {
	// stack�� �� ����������� ���� pop ��Ű�� �ȴ�.

	while (!stack_is_empty(pStack)) {
		stack_pop(pStack, NULL);
	}
}

// ������ ������� Ȯ��
int stack_is_empty(Stack* pStack) {
	if (pStack->pTop == NULL) return SUCCESS; // ��� ������ '��'

	return FAIL;
}

// push : top�� ������ �߰�
int stack_push(Stack* pStack, Data data) {
	// ���ο� ��� ����
	node* pNewNode = (node*)malloc(sizeof(node));
	pNewNode->data = data;
	
	// ��带 ���ÿ� �߰�
	pNewNode->pNext = pStack->pTop;
	// top�� ������ push�� ��带 ����Ų��.
	pStack->pTop = pNewNode;

	return SUCCESS;
}

// pop : top�� ������ ������
int stack_pop(Stack* pStack, Data* pData) {

	if (stack_is_empty(pStack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	// ������ ��� ���
	node* deleteNode = pStack->pTop;

	if (pData != NULL) {
		*pData = pStack->pTop->data; // ������ �б�(������)
	}

	pStack->pTop = pStack->pTop->pNext; // top �̵�

	free(deleteNode); // pop�� ��� ����

	return SUCCESS;
}

// peek : top�� ������ �̸�����
int stack_peek(Stack* pStack, Data* pData) {
	if (stack_is_empty(pStack)) {
		printf("Empty Stack!\n");
		return FAIL;
	}

	if (pData != NULL) {
		*pData = pStack->pTop->data; // ������ �б�(������)
	}
	return SUCCESS;

}

