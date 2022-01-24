#ifndef __STACK_H_
#define __STACK_H_
#define SUCCESS 1
#define FAIL 0

/* ������ ������*/
typedef int Data;

typedef struct _node {
	Data data;
	struct _node* pNext;
}node;

typedef struct _listStack {
	node* pTop; // �̹� �������� numData�� ������

}ListStack;

typedef ListStack Stack;

/* ������ ���� */

// ���� �ʱ�ȭ
void stack_init(Stack *pStack);

// ���� ����
void stack_destroy(Stack* pStack);

// ������ ������� Ȯ��
int stack_is_empty(Stack* pStack);

// push : top�� ������ �߰�
int stack_push(Stack* pStack, Data data);

// pop : top�� ������ ������
int stack_pop(Stack* pStack, Data *pData); 
// ���⼭ ���� �� ���� �̸� ���� ��� ���� ����
// int stack_pop(Stack* , Data *); �̰� ���� ����

// peek : top�� ������ �̸�����
int stack_peek(Stack* pStack, Data* pData);


#endif