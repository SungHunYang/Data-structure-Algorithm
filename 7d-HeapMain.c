#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "7d-Heap.h"

// ch1�� �켱������ ���ٸ� 0���� ū �� ����
// ch2�� �켱������ ���ٸ� 0���� ���� �� ����
// ch1�� ch2�� �켱������ ���ٸ� 0�� ����
int DataPriorityComp(HData ch1, HData ch2) {
	
	return ch1 - ch2;
	// ch1�� �� ũ�� ��� , ch2�� �� ũ�� ���� , 0�̸� ����
	// max-Heap  
	// ch1 ch2 ��ġ �ٲٸ� min-Heap
}

void main() {

	Heap heap;
	heap_init(&heap, DataPriorityComp);
	
	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);

	// MAX - HEAP
	//		(30)
	//	  ��  	��
	//	(9)		(20)

	// MIN - HEAP
	//		(9)
	//	  ��  	��
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
	heap_insert(&heap, 3);  // �߰�
	heap_insert(&heap, 2);  // ��� �ǳ�?
	heap_insert(&heap, 10); // ��� �ǳ�?
	heap_insert(&heap, 1);  // ��� �ǳ�?

	while (!heap_is_empty(&heap)) {
		printf("%d ", heap_delete(&heap)); // 30 9 20
	}

}