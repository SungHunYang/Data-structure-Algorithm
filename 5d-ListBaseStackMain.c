#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "5d-ListBaseStack.h"

void main() {

	Stack stack;
	Data data;

	stack_init(&stack); // Stack의 생성 및 초기화
	
	// 데이터 push
	stack_push(&stack,1); // 1 <-
	stack_push(&stack, 2); // 1 2 <-
	stack_push(&stack, 3); //  1 2 3 <-
	stack_push(&stack, 4); //  1 2 3 4 <-
	stack_push(&stack, 5); //  1 2 3 4 5<-

	// 데이터 pop
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

	// 도전] 100, 200, 300 .... 1000 : 10개의 데이터 push
	for (int i = 1; i <= 10; i++) {
		stack_push(&stack, 100*i);
	}

	// 도전] 모든 데이터 pop 하여 출력
	for (int i = 1; i <= 10; i++) {
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_destroy(&stack); // 스택 제거

}
