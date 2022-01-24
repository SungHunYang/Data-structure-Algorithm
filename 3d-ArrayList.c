#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "3d-ArrayList.h"


// ����Ʈ �ʱ�ȭ
void list_init_(List* pList) {
	pList->numData = 0;
	pList->curPosition = -1; // itertation
	memset(pList->arr, 0, sizeof(pList->arr)); // �迭�� ���� 0���� �ʱ�ȭ
	printf("LIST �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List* pList) {
	pList->numData = 0;
	printf("����Ʈ ����\n");
}

// ������ �߰�
int list_add(List* pList, Data data) {
	if (pList->numData >= LIST_LEN) {
		printf("DATA FULL [ %d ] \n",data);
		return FAIL;
	}
	pList->arr[pList->numData] = data; // ������ �߰�
	printf("(%d) ��° ������ [ %d ] �߰�\n", pList->numData, data);
	pList->numData++; // ������ ���� ����
	return SUCCESS;
}

// n��° ������ ����
int list_set(List* pList, int n, Data data);

// ������ ����
int list_length(List* pList) {
	return pList->numData;
}

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List* pList) {
	pList->curPosition = -1;

}

// ������ ��ȸ, iteration ���� ������ ����
Data list_next(List* pList);

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List* pList) {
	if (pList->curPosition++ <= pList->numData) {
		return SUCCESS;
	}
	return FAIL;
}


// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data* pData) {
	if (n >= pList->numData) {
		return FAIL;
	}
	*pData = pList->arr[n]; // n���� �����Ͱ��� pData�� ���� ����! call by reference
	return SUCCESS;
}

// n��° ������ ����
int list_remove(List* pList, int n) {
	if (n >= pList->numData) {
		printf("[%d] ��° ������ ���� ����\n", n);
		return FAIL;
	}

	// �迭�̴ϱ�, �߰��� �����͸� �����ϸ� ���� �͵��� ��ܿ;���.

	for (int i = n; i < pList->numData-1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->numData--;
	printf("%d��° ������ ����\n", n);
	return SUCCESS;
}


// n��° ��ġ�� ������ ����
int list_insert(List* pList, int n, Data data) {
	if (pList->numData >= LIST_LEN) {
		printf("FULL\n");
		return FAIL;
	}
	for (int i = pList->numData ; i > n; i--) {
		pList->arr[i] = pList->arr[i-1];
	}
	if (pList->numData < n) {
		pList->numData = n;
	}
	else {
		pList->numData++;
	}
	pList->arr[n] = data;
	return SUCCESS;
}