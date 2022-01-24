#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "4d-LinkedList.h"

// ����Ʈ �ʱ�ȭ
void list_init_(List* pList) {
	// head, dummy node ����
	pList->pHead = (node*)malloc(sizeof(node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead; //���ʿ��� tail�� head ����
	pList->numData = 0;

	//printf("����Ʈ �ʱ�ȭ\n");
}


// ������ �߰�
int list_add(List* pList, Data data) {
	node* pNewNode = (node*)malloc(sizeof(node));
	memset(pNewNode, 0, sizeof(node));
	pNewNode->data = data;

	// tail�� ����Ű�� node�� next�� ���ο� node�� ����
	pList->pTail->pNext = pNewNode;
	
	// tail �̵�
	pList->pTail = pNewNode;
	(pList->numData)++; // ������ ���� +1 ����

	return TRUE;
}

// n��° ������ ����
int list_set(List* pList, int n, Data data) {

	if (n >= pList->numData) return FALSE;
	// head ���� �����ؼ� n��° ��� ã��, iteration ���
	list_init_iter(pList);
	int i = 0; // ���� ���° ���?
	while (list_hasNext(pList)) {
		list_next(pList);
		if (i >= n)break; //n��° ��� ã��!
		i++;
	}
	// �� while ���� ������ pCurrent�� n��° ��带 ����Ű�� ����
	//printf("%d ��° ������ ���� %d --> %d\n", n, pList->pCurrent->data, data);
	pList->pCurrent->data = data; // ������ ����
	return TRUE;
}

// ������ ����
int list_length(List* pList) {
	return pList->numData;
}

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List* pList) {
	// pCurrent �� dummy node���� ���� ����
	pList->pCurrent = pList->pHead;
}

// ������ ��ȸ, iteration ���� ������ ����
Data list_next(List* pList) {
	pList->pCurrent = pList->pCurrent->pNext; // �켱 current�� �ѹ� ������ �̵�
	return pList->pCurrent->data;
}

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List* pList) {
	if (pList->pCurrent->pNext == NULL) // '�������' ���翩��üũ
		return FALSE;
	return TRUE;
}
// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data* pData) {
	if (n >= pList->numData)return FALSE;
	// head ���� �����ؼ� n��° ��� ã��, iteration ���
	list_init_iter(pList);
	int i = 0; // ���� ���° ���?
	while (list_hasNext(pList)) {
		list_next(pList);
		if (i >= n)break; //n��° ��� ã��!
		i++;
	}
	// n��° �����͸� �Ű������� �����
	*pData = pList->pCurrent->data;
	return TRUE;
}

// n��° ������ ����
int list_remove(List* pList, int n) {

	if (n >= pList->numData) return FALSE;
	// n��° ��� �����Ϸ���
	// n��° �� �ƴ϶� n-1 ��° ��� ������ �˾ƾ� �Ѵ�
	// ��. ���� ���(previous node) ���� �˾ƾ� �Ѵ�.

	list_init_iter(pList);
	int i = 0; // ���� ���° ���?
	node* pPrev = NULL; // ������带 ����ų ������
	while (list_hasNext(pList)) {
		// pCurrent �� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
		pPrev =pList->pCurrent;

		list_next(pList);
		if (i == n)break; //n��° ��� ã��!
		i++;
	}
	// �� while ���� ������ 
	// pCurrent �� n��° ��带, 
	// pPrev �� n-1��° ��带 ����Ű�� �ִ�

	// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.
	
	// ���� ����
	pPrev->pNext = pList->pCurrent->pNext;
	// �̰� pPrev -> pCurrent -> pFuter �̷��� �Ǿ��ִ� �����ε�
	// ���� �����Ϸ��� �ϴµ� pCurrent ���̾� �˰ھ�?
	// �׸��� pCurrent->pNext�� pFuter�� ����Ű�� �ִ�.
	// �׷��� pPrev->pNext �� pCurrent->pNext �� pFuter�� �ְ�
	// pCurrent�� ���� �Ǹ� pPrev -> pFuter �̷��� �Ǵ� ����

	// ���� tail�� ������ ��� ���ٸ� tail ���� �����ؾ� �Ѵ�.
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev; // tail�� ���� ���� �̵�
	//printf("%d ��° ������ %d ����\n", n, pList->pCurrent->data);
	free(pList->pCurrent);
	pList->numData--;

	return TRUE;
}

// n��° ��ġ�� ������ ����
// �ǵڿ� ����(�߰�) �ϴ� �͵� ���
int list_insert(List* pList, int n, Data data) {
	if (n > pList->numData) return FALSE; // >=�� �ƴ϶� > �̴�!
	
	// ���ο� ��� ����
	node* pNewNode = (node*)malloc(sizeof(node));
	memset(pNewNode, 0, sizeof(node));
	// �̰� memset ���� �򰥷��� �� �����ڸ� ���� ���� N���� �ȳ־� �����ϱ�
	// ���� ó�� ���� data�� 0���� �����Ǵ°Ŵ�. 
	// �ι�° pNext�� ����
	pNewNode->data = data;

	// 1. ù��° ������ �̰ų�
	// 2. �ǳ��� �߰��ϸ�

	if (pList->numData == 0 || n == pList->numData) {
		// add() �� ����
		pList->pTail->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else {
		// 3. n��° ��忡 �����Ϸ���
		// n-1��° ���, �������(previous node) ���� �˾ƾ� �Ѵ�.

		list_init_iter(pList);
		int i = 0; // ���� ���° ���?
		node* pPrev = NULL; // ������带 ����ų ������
		while (list_hasNext(pList)) {
			// pCurrent �� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
			pPrev = pList->pCurrent;

			list_next(pList);
			if (i == n)break; //n��° ��� ã��!
			i++;
		}
		// ���Ե��� ����
		// �������� ���ο� ��带 ����Ű��
		pPrev->pNext = pNewNode;
		// ���ο� ���� ������ n��° ��带 ����Ű�� �ȴ�.
		pNewNode->pNext = pList->pCurrent;
		
	}
	//printf("[%d] ��° ������ %d ����\n", n, data);
	(pList->numData)++; //������ ����
	return TRUE;
}

// ����Ʈ ����
void list_destroy(List* pList) {

	list_init_iter(pList);
	
	node* pPrev = NULL; // ������带 ����ų ������
	while (list_hasNext(pList)) {
		// pCurrent �� �̵��ϱ� ���� pCurrent ���� '���� ���'�� ����صξ�� �Ѵ�.
		pPrev = pList->pCurrent;
		list_next(pList);
		free(pPrev); //��� ����
	}

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	//printf("[ LIST DESTROY ]\n");

}


// Ž��
node* list_search(List* pList, Data data) {
	pList->pCurrent = pList->pHead; // head ���� �˻�
	while (pList->pCurrent->pNext != NULL) {
		pList->pCurrent = pList->pCurrent->pNext; //���� ��� ������ �ѹ� ������ ����
		if (pList->pCurrent->data == data) {
			return pList->pCurrent; // ã���� �ش� ��� ����
		}
	}
	return NULL; // ������ NULL ����

}