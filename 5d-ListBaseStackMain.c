#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListBaseStack.h"

void main() {

	Stack stack;
	Data data;

	stack_init(&stack); // Stack�� ���� �� �ʱ�ȭ
	
	// ������ push
	stack_push(&stack,1); // 1 <-
	stack_push(&stack, 2); // 1 2 <-
	stack_push(&stack, 3); //  1 2 3 <-
	stack_push(&stack, 4); //  1 2 3 4 <-
	stack_push(&stack, 5); //  1 2 3 4 5<-

	// ������ pop
	stack_pop(&stack, &data);
	printf("pop--> %d \n", data); // 5
	stack_pop(&stack, &data);
	printf("pop--> %d \n", data); // 4
	while (!stack_is_empty(&stack)) { //
		stack_pop(&stack, &data);
		printf("pop--> %d \n", data);
	}
	printf("\n");
	printf("\n");
	printf("\n");

	// ����] 100, 200, 300 .... 1000 : 10���� ������ push
	for (int i = 1; i <= 10; i++) {
		stack_push(&stack, 100*i);
	}

	// ����] ��� ������ pop �Ͽ� ���
	for (int i = 1; i <= 10; i++) {
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_destroy(&stack); // ���� ����

}
