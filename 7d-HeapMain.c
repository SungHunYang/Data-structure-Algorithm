#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "7d-Heap.h"

// ch1의 우선순위가 높다면 0보다 큰 값 리턴
// ch2의 우선순위가 높다면 0보다 작은 값 리턴
// ch1과 ch2의 우선순위가 같다면 0을 리턴
int DataPriorityComp(HData ch1, HData ch2) {
	
	return ch1 - ch2;
	// ch1이 더 크면 양수 , ch2가 더 크면 음수 , 0이면 리턴
	// max-Heap  
	// ch1 ch2 위치 바꾸면 min-Heap
}

void main() {

	Heap heap;
	heap_init(&heap, DataPriorityComp);
	
	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);

	// MAX - HEAP
	//		(30)
	//	  ↙  	↘
	//	(9)		(20)

	// MIN - HEAP
	//		(9)
	//	  ↙  	↘
	//	(20)	(30)
	

	while (!heap_is_empty(&heap)) {
		printf("%d ", heap_delete(&heap)); // 30 9 20
	}

	printf("\n");
	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);
	heap_insert(&heap, 3);  // 추가
	heap_insert(&heap, 2);  // 어떻게 되나?
	heap_insert(&heap, 10); // 어떻게 되나?
	heap_insert(&heap, 1);  // 어떻게 되나?

	while (!heap_is_empty(&heap)) {
		printf("%d ", heap_delete(&heap)); // 30 9 20
	}

}