#ifndef __QUEUE_H_
#define __QUEUE_H_
#define SUCCESS 1
#define FAIL 0

/* 큐의 데이터*/
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
/* 큐의 동작 */

// 큐 초기화
void queue_init(Queue *pq);

// 큐 제거
void queue_destroy(Queue* pq);

// 큐가 비어있는지?
int queue_is_empty(Queue* pq);

// enqueue 데이터 추가(back에 추가)
int queue_enq(Queue* pq,Data data);

// dequeue 데이터 꺼내기 (front 에서 추출)
int queue_deq(Queue* pq, Data* pData);

// peek 데이터 보기 (front 에서 봄)
int queue_peek(Queue* pq, Data* pData);


#endif
