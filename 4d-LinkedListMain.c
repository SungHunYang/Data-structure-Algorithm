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
	list_init_(&myList); //����Ʈ �ʱ�ȭ

	list_add(&myList, 100); // ������ �߰�
	list_add(&myList, 50);
	printList(&myList);
	list_add(&myList, 80);
	list_add(&myList, 20);
	printList(&myList);
	list_add(&myList, 45);
	list_add(&myList, 70);
	printList(&myList);

	// ������ ����
	list_set(&myList, 0, 40);
	list_set(&myList, 1, 30);
	list_set(&myList, 3, 60);
	printList(&myList);

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));


	// n��° ������ ��ȸ
	Data data;
	if (list_get(&myList, 0, &data)) {
		printf("0��° : %d\n", data);
	}
	if (list_get(&myList, 6, &data)) {
		printf("6��° : %d\n", data); // ���еǾ� ����
	}
	if (list_get(&myList, 2, &data)) {
		printf("2��° : %d\n", data);
	}

	// ������ ����
	printf("������\n");
	printList(&myList);
	list_remove(&myList, 2); // 2�� ����
	printList(&myList);
	list_remove(&myList, 2);
	printList(&myList);
	printf("������ ������ %d\n", list_length(&myList)); //4
	list_remove(&myList, 0);
	printList(&myList);
	list_remove(&myList, 0);
	printList(&myList);
	printf("������ ������ %d\n", list_length(&myList)); //2


	list_insert(&myList, 1, 44);
	printList(&myList);
	list_insert(&myList, 0, 18);
	printList(&myList);
	list_insert(&myList, 3, 22);
	printList(&myList);
	printf("������ ������ %d\n", list_length(&myList));


	list_destroy(&myList);

	{
		// �������ϸ� �׽�Ʈ
		printf("-----------------------------------\n");
		list_init_(&myList);
		unsigned int test_size = 8;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ���� : �ƹ�Ű�� ��������\n");
		_getch();

		printf("%d�� insert ... \n", test_size);

		//�������ϸ�
		start = clock();
		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i); // 0��°�� insert
		}
		end = clock();
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ��� : %1d ms ��� \n", end - start);


		// -------------------------------------
		printf("�ƹ�Ű�� �����ø� ���� �׽�Ʈ �����մϴ�.\n");
		_getch();
		printf("%d�� get ... \n", test_size);

		// �������ϸ�
		start = clock();
		for (unsigned int i = 0; i < test_size; i++) {
			list_get(&myList, i, &data);
		}
		end = clock();
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("get ��� : %1d ms ��� \n", end - start);

		//---------------------------------
		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������\n");
		_getch();
		printf("%d �� remove...\n", test_size);
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("remove ��� : %ld ms ���\n", end - start);

		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������\n");
		_getch();

		list_destroy(&myList);

	}







}