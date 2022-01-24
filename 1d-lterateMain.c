#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

#define MAX_LENGTH 4
#define TRUE 1
#define FALSE 0

typedef struct _IterArray {
	int arr[MAX_LENGTH];
	int curPosition; // iterator ������ ���� ��
}IterArr;

// iterator �ʱ�ȭ
void iter_init(IterArr* p) {
	p->curPosition = -1; // �̰� �迭 ���� ó�� ����Ű�� �Ǵ�,
	// �ٽ� �ټ���� ��. �� 0�� �ƴϰ� -1������ 
	// �ؿ� �Լ����� ������ ���� ������ Ȯ���Ϸ���
	// +1 ���� ���Ѿ� �ϴµ� ���� 0 �̸� ���� ó�� �����ʹ� Ȯ���� �Ұ��� �ؼ� -1 ���� �Ѵ�.
}

// ������ ������ ������ �ֳ�?
int iter_hasNext(IterArr* p) {
	if (p->curPosition + 1 < MAX_LENGTH) {
		return TRUE;
	}
	else {
		printf("�� �̻� ������ �����Ͱ� �����ϴ�.\n");
		return FALSE;
	}
}

// ���� ������ ����
int iter_next(IterArr* p) {
	p->curPosition++; // �켱! curPosition�� next �� +1 ����.
	// �ֳĸ� �������� üũ�� �Ѱ��� ������ �� �������ϱ�.
	return p->arr[p->curPosition]; // curPosition�� ����Ű�� �� ����

		// ���Ⱑ curPosition �� -1�� ������
		// ++ ���� ���� ���� ������ 0���� �������� -1�̿��� �Ѵ�.
		// 0 ���� �����ϸ� �ٷ� ++ �ϸ� ù��° 0��° �迭�� �������� ���
}

void main() {

	IterArr data = { {10,20,30,40}, -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) // �� ������ �����Ͱ� �ֳ�?
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// �ٽ� iterator ������ �ϸ�.. (�ȵ��ư���.)
	// �ֳĸ� curPosition�� ���� �� �־ hasNext�� FALSE�� ���� ������
	while (iter_hasNext(&data)) // �� ������ �����Ͱ� �ֳ�?
	{
		printf("%d ", iter_next(&data));
	}
	// ���� �����͸� �����Ϸ��� iterator�� ���� ���� ���Ѿ� �Ѵ�.
	// �׷��� iterator�� ��ȸ�� // �ٽ� ������ iter_init(&data) �� �ٽ� ������� �Ѵ�.
}

/* ���� ��κ��� ���� ���鿡�� Iteration(�ݺ���) ������.
*
*	Python �� iterable��ü
*		ex) for a in b:  <-- b �� 'iterable' �ؾ� �Ѵ�.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection �� Iterator ��ü
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/
