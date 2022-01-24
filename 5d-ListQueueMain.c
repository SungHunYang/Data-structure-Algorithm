#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListQueue.h"

void main() {

	//Queue 생성 및 초기화
	Queue q;
	Data data;

	queue_init(&q);

	// 데이터 넣기 enqueue
	queue_enq(&q, 1); // front <-- 1 <-- back
	queue_enq(&q, 2); // front <-- 1 2<-- back
	queue_enq(&q, 3); // front <-- 1 2 3<-- back
	queue_enq(&q, 4); // front <-- 1 2 3 4<-- back
	queue_enq(&q, 5); // front <-- 1 2 3 4 5<-- back

	// 데이터 꺼내기 dequeue
	while (!queue_is_empty(&q)) {
		queue_deq(&q, &data);
		printf("dequeue --> %d\n", data);

	}


	// 큐 제거
	queue_destroy(&q);

}