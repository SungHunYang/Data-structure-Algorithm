#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListQueue.h"

// ť �ʱ�ȭ
void queue_init(Queue* pq) {
	pq->pFront = NULL;
	pq->pBack = NULL;
}

// ť ����
void queue_destroy(Queue* pq) {

	// ť�� �� ����������� dequeue
	while (!queue_is_empty(pq)) {
		queue_deq(pq, NULL);
	}

}

// ť�� ����ִ���?
int queue_is_empty(Queue* pq) {
	if (pq->pFront == NULL) return SUCCESS;

	return FAIL;
}

// enqueue ������ �߰�(back�� �߰�)
int queue_enq(Queue* pq, Data data) {
	node* pNewNode = (node*)malloc(sizeof(node));
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	
	// ť�� ����������� �׷��� ���� �� ����
	if (queue_is_empty(pq)) {
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
	}
	else {
		pq->pBack->pNext = pNewNode;
		pq->pBack = pNewNode;
	}
	return SUCCESS;
	// �� LinkedList.c �� list_add() �Լ��� ���غ���
	//    dummy node �� ����Ѱ�(LinkedList)��
	//    �׷��� ������(ListBaseQueue)�� ��
	//   dummy node  �� ����ϸ� �ڵ尡 ���� ����������. (�бⰡ ��������)

}

// dequeue ������ ������ (front ���� ����)
int queue_deq(Queue* pq, Data* pData) {
	if (queue_is_empty(pq)) {
		printf("[ QUEUE EMPTY ]\n");
		return FAIL;
	}
	if (pData != NULL) *pData = pq->pFront->data; // front ������ ����
	
	node* deleteNode = pq->pFront; //������ ��� ���
	pq->pFront = pq->pFront->pNext; // front�� ���� ���� �̵�
	free(deleteNode);
	return SUCCESS;
}

// peek ������ ���� (front ���� ��)
int queue_peek(Queue* pq, Data* pData) {
	if (queue_is_empty(pq)) {
		printf("[ QUEUE EMPTY ]\n");
		return FAIL;
	}
	if (pData != NULL) *pData = pq->pFront->data; // front ������ ����

	return SUCCESS;
}
