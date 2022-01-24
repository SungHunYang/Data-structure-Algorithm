#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "6d-BinaryTree.h"
#include "5d-ListQueue.h"

/* Binary Tree �� ����*/

// Ʈ�� ��� ����
BTreeNode* btree_make_node(){ // �ƿ� ����鼭 ���ϱ��� �ް�
	BTreeNode* pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->Data = 0;

	return pNewNode;

}

// ��� ������ �б�
BTData btree_get_data(BTreeNode* bt) {

	return bt->Data;
}

// ��� ������ ����
void btree_set_data(BTreeNode* bt, BTData data) {
	bt->Data = data;
}

// ����� Left sub tree
BTreeNode* btree_get_left(BTreeNode* bt) {
	return bt->pLeft;
}

// ����� Right sub tree
BTreeNode* btree_get_right(BTreeNode* bt) {
	return bt->pRight;
}

// bt�� left�� sub tree ����
void btree_make_left(BTreeNode* bt, BTreeNode* sub) {
	if (bt->pLeft != NULL) {  // ���� ��忡 ���� ������ ���������� ���ο� sub�� ����
		btree_delete(bt->pLeft);
	}
	bt->pLeft = sub;
}

// bt�� right�� sub tree ����
void btree_make_right(BTreeNode* bt, BTreeNode* sub) {
	if (bt->pRight != NULL) {  // ������ ��忡 ���� ������ ���������� ���ο� sub�� ����
		btree_delete(bt->pRight);
	}
	bt->pRight = sub;
}

// ���� ��� ���� ����
void btree_delete(BTreeNode* bt) {
	if (bt == NULL) return;

	// ������ post order ��� ( L -> R -> C ) ������ ������ �Ѵ�.

	// ��� ȣ��
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	//printf("��� ���� : %d \n", bt->Data);

	free(bt); // C
}

/*Traversing ------------------------------------------------------------------*/

void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // �������

	// C -> L -> R

	action(bt->Data); // C
	btree_preorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_preorder_traverse(bt->pRight, action); // R : ���ȣ��

}
void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // �������

	// L -> C -> R

	btree_inorder_traverse(bt->pLeft, action); // L : ���ȣ��
	action(bt->Data); // C
	btree_inorder_traverse(bt->pRight, action); // R : ���ȣ��

}
void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // �������

	// L -> R -> C

	btree_postorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_postorder_traverse(bt->pRight, action); // R : ���ȣ��
	action(bt->Data); // C
}
// �̰�  traverse ��� ���� C(���) ���� ���� �����ִ� ���ΰŴ�.
// �׷��� L R ������ ���缭 L�� ���� ���� ��� ȣ���� �θ��� �ǰ� 
// �� L�� ���ȣ�⿡���� C�� �Ǽ� action�Լ� �� print�� ������ �Ǵ°Ŵ�.


/*
// level-order traverse �ۼ��ϱ�
void btree_levelorder_traverse(BTreeNode* bt, fnVisitNode action) {
	Queue q;
	queue_init(&q);

	// �ϴ� root�� ť�� enq

	// while(ť�� empty �� �� ����)
	{
		Queue q;
		queue_init(&q);

		// �ϴ� root�� ť�� enq
		queue_enq(&q, (Data)bt);

		// while(ť �� empty �ɶ�����)
		while (!queue_is_empty(&q))
		{
			BTreeNode* btCurrent;

			// dequeue �Ͽ� ���
			queue_deq(&q, &btCurrent);
			action(btCurrent->Data);

			// left -> enqueue
			if (btCurrent->pLeft != NULL)
				queue_enq(&q, btCurrent->pLeft);

			// right-> euqueue
			if (btCurrent->pRight != NULL)
				queue_enq(&q, btCurrent->pRight);

		}
	}

	queue_destroy(&q);

}
*/