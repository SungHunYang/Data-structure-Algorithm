#ifndef __QUEUE_H_
#define __QUEUE_H_
#define SUCCESS 1
#define FAIL 0

/* ť�� ������*/
typedef int Data;
typedef struct _node {
	Data data;
	struct _node* pNext;
}node;

typedef struct _lQueue {
	node* pFront;
	node* pBack;
}LQueue;

typedef LQueue Queue;
/* ť�� ���� */

// ť �ʱ�ȭ
void queue_init(Queue *pq);

// ť ����
void queue_destroy(Queue* pq);

// ť�� ����ִ���?
int queue_is_empty(Queue* pq);

// enqueue ������ �߰�(back�� �߰�)
int queue_enq(Queue* pq,Data data);

// dequeue ������ ������ (front ���� ����)
int queue_deq(Queue* pq, Data* pData);

// peek ������ ���� (front ���� ��)
int queue_peek(Queue* pq, Data* pData);


#endif
