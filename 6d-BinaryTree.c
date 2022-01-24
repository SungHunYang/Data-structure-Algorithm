#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "6d-BinaryTree.h"
#include "5d-ListQueue.h"

/* Binary Tree 의 동작*/

// 트리 노드 생성
BTreeNode* btree_make_node(){ // 아예 만들면서 리턴까지 받게
	BTreeNode* pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->Data = 0;

	return pNewNode;

}

// 노드 데이터 읽기
BTData btree_get_data(BTreeNode* bt) {

	return bt->Data;
}

// 노드 데이터 쓰기
void btree_set_data(BTreeNode* bt, BTData data) {
	bt->Data = data;
}

// 노드의 Left sub tree
BTreeNode* btree_get_left(BTreeNode* bt) {
	return bt->pLeft;
}

// 노드의 Right sub tree
BTreeNode* btree_get_right(BTreeNode* bt) {
	return bt->pRight;
}

// bt의 left에 sub tree 연결
void btree_make_left(BTreeNode* bt, BTreeNode* sub) {
	if (bt->pLeft != NULL) {  // 왼쪽 노드에 뭔가 있으면 지워버리고 새로운 sub를 넣음
		btree_delete(bt->pLeft);
	}
	bt->pLeft = sub;
}

// bt의 right에 sub tree 연결
void btree_make_right(BTreeNode* bt, BTreeNode* sub) {
	if (bt->pRight != NULL) {  // 오른쪽 노드에 뭔가 있으면 지워버리고 새로운 sub를 넣음
		btree_delete(bt->pRight);
	}
	bt->pRight = sub;
}

// 현재 노드 부터 삭제
void btree_delete(BTreeNode* bt) {
	if (bt == NULL) return;

	// 삭제는 post order 방식 ( L -> R -> C ) 순서로 지워야 한다.

	// 재귀 호출
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	//printf("노드 삭제 : %d \n", bt->Data);

	free(bt); // C
}

/*Traversing ------------------------------------------------------------------*/

void btree_preorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // 재귀종료

	// C -> L -> R

	action(bt->Data); // C
	btree_preorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_preorder_traverse(bt->pRight, action); // R : 재귀호출

}
void btree_inorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // 재귀종료

	// L -> C -> R

	btree_inorder_traverse(bt->pLeft, action); // L : 재귀호출
	action(bt->Data); // C
	btree_inorder_traverse(bt->pRight, action); // R : 재귀호출

}
void btree_postorder_traverse(BTreeNode* bt, fnVisitNode action) {
	if (bt == NULL) return; // 재귀종료

	// L -> R -> C

	btree_postorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_postorder_traverse(bt->pRight, action); // R : 재귀호출
	action(bt->Data); // C
}
// 이게  traverse 얘네 들은 C(가운데) 값이 오면 보여주는 식인거다.
// 그래서 L R 순서를 맞춰서 L가 먼저 오면 재귀 호출을 부르게 되고 
// 그 L가 재귀호출에서는 C가 되서 action함수 즉 print로 나오게 되는거다.


/*
// level-order traverse 작성하기
void btree_levelorder_traverse(BTreeNode* bt, fnVisitNode action) {
	Queue q;
	queue_init(&q);

	// 일단 root를 큐에 enq

	// while(큐가 empty 될 때 까지)
	{
		Queue q;
		queue_init(&q);

		// 일단 root를 큐에 enq
		queue_enq(&q, (Data)bt);

		// while(큐 가 empty 될때까지)
		while (!queue_is_empty(&q))
		{
			BTreeNode* btCurrent;

			// dequeue 하여 출력
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