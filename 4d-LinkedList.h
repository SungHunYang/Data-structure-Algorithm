#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_
#define TRUE 1
#define FALSE 0

/*
*	LinkedList �� ADT
*
*	����: ����, ���� ����
*	����: ��ȸ�� �Ҹ�
*
*	����: ArrayList�� ���� �뷮 UP
*/


/*LIST�� ������*/
typedef int Data;

// ���Ÿ�� ����
typedef struct _Node{
	// ��� ������
	Data data;

	// ���� ����� ������
	struct _Node* pNext;

}node;
// Linked List Ÿ�� ����
typedef struct _linkedList {
	// ���� ���
	node* pHead;
	// �� ���
	node* pTail;
	// iteration
	node* pCurrent;
	// ����� ����
	int numData;
}LinkedList;

typedef LinkedList List;

/*LIST�� ����*/


// ����Ʈ �ʱ�ȭ
void list_init_(List* pList);

// ����Ʈ ����
void list_destroy(List* pList);

// ������ �߰�
int list_add(List* pList, Data data);

// n��° ������ ����
int list_set(List* pList, int n, Data data);

// ������ ����
int list_length(List* pList);

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List* pList);

// ������ ��ȸ, iteration ���� ������ ����
Data list_next(List* pList);

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List* pList);
// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data* pData);

// n��° ������ ����
int list_remove(List* pList, int n);

// n��° ��ġ�� ������ ����
int list_insert(List* pList, int n, Data data);

// �־��� pList ���� data�� ��� Node�� ã�Ƽ� return, ������ NULL����
node* list_search(List* pList, Data data);


#endif
