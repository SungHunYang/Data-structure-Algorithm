#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "4d-LinkedList.h"

void printList(List* pList) {

	list_init_iter(pList);
	printf("[");
	while (list_hasNext(pList)) {
		printf("%d, ", list_next(pList));
	}
	printf("]\n");
}
void main() {

	List myList;
	list_init_(&myList); //리스트 초기화

	list_add(&myList, 100); // 데이터 추가
	list_add(&myList, 50);
	printList(&myList);
	list_add(&myList, 80);
	list_add(&myList, 20);
	printList(&myList);
	list_add(&myList, 45);
	list_add(&myList, 70);
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 3, 60);
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));


	// n번째 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) {
		printf("0번째 : %d\n", data);
	}
	if (list_get(&myList, 6, &data)) {
		printf("6번째 : %d\n", data); // 실패되야 정상
	}
	if (list_get(&myList, 2, &data)) {
		printf("2번째 : %d\n", data);
	}

	// 데이터 삭제
	printf("삭제전\n");
	printList(&myList);
	list_remove(&myList, 2); // 2번 삭제
	printList(&myList);
	list_remove(&myList, 2);
	printList(&myList);
	printf("데이터 개수는 %d\n", list_length(&myList)); //4
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	printf("데이터 개수는 %d\n", list_length(&myList)); //2


	list_insert(&myList, 1, 44);
	printList(&myList);
	list_insert(&myList, 0, 18);
	printList(&myList);
	list_insert(&myList, 3, 22);
	printList(&myList);
	printf("데이터 개수는 %d\n", list_length(&myList));


	list_destroy(&myList);

	{
		// 프로파일링 테스트
		printf("-----------------------------------\n");
		list_init_(&myList);
		unsigned int test_size = 8;
		clock_t start, end;
		Data data;
		printf("프로파일링 시작 : 아무키나 누르세요\n");
		_getch();

		printf("%d개 insert ... \n", test_size);

		//프로파일링
		start = clock();
		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i); // 0번째에 insert
		}
		end = clock();
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("insert 결과 : %1d ms 경과 \n", end - start);


		// -------------------------------------
		printf("아무키나 누르시면 다음 테스트 진행합니다.\n");
		_getch();
		printf("%d개 get ... \n", test_size);

		// 프로파일링
		start = clock();
		for (unsigned int i = 0; i < test_size; i++) {
			list_get(&myList, i, &data);
		}
		end = clock();
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("get 결과 : %1d ms 경과 \n", end - start);

		//---------------------------------
		printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷\n");
		_getch();
		printf("%d 개 remove...\n", test_size);
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("remove 결과 : %ld ms 경과\n", end - start);

		printf("아무키나 누르면 종료됩니다 : 잠시후 스냅샷\n");
		_getch();

		list_destroy(&myList);

	}







}