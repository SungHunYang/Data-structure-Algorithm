#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"6d-BinaryTree.h"
#include"10d-BinartSearchTree.h"

// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode** ppRoot)
{
	*ppRoot = NULL; // 포인터 값 초기화

}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode** ppRoot, BTData data)
{
	BTreeNode* parentNode = NULL; // parent node
	BTreeNode* curNode = *ppRoot; // 현재노드 시작점 : 일단 root부터 시작한다.
	BTreeNode* newNode = NULL;

	// 새로운 노드가 추가될 위치를 찾아 내려간다.
	while (curNode != NULL) { // 종단 노드까지 내려가면, 바로 그곳이 삽입될 위치
		if (data == btree_get_data(curNode))
			return FAIL; // BST 에선 key의 중복허용 X

		parentNode = curNode;
		if (btree_get_data(curNode) > data)// 삽입 하려는 data가 노드의 데이터보다 더 작다면 왼쪽
			curNode = btree_get_left(curNode);
		else   // 삽입 하려는 data가 노드의 데이터보다 더 작다면 오른쪽
			curNode = btree_get_right(curNode);
	}

	// 추가할 새 노드의 생성
	newNode = btree_make_node();
	btree_set_data(newNode, data);

	//parentNode의 서브 노드에 새 노드를 추가
	if (parentNode != NULL) {
		if (data < btree_get_data(parentNode)) // 부모의 데이터보다 작다면 left로 붙인다.
			btree_make_left(parentNode, newNode);
		else
			btree_make_right(parentNode, newNode);
	}
	else { // 첫번째 노드의 경우, 새 노드가 루트 위치이기에 parentNode는 NULL인 상태다
		
		*ppRoot = newNode; // 루트 세팅!

	}

	return SUCCESS;
}

// 이진 탐색 트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode* pRoot, BTData data) {

	BTreeNode* curNode = pRoot; // root부터 탐색 시작
	BTData curData; // current data

	while (curNode != NULL)  // 탐색을 해 내려가다가 종단노드까지 도달하면 탐색 실패
	{
		curData = btree_get_data(curNode); // 현재 노드의 데이터

		if (data == curData)
			return curNode; // 발견! 탐색성공, 노드의 포인터를 리턴
		
		if (data < curData) // data 값이 노드의 데이터 보다 작다면 left 로 이동
			curNode = btree_get_left(curNode);
		else // data 값이 노드의 데이터 보다 크다면 right 로 이동
			curNode = btree_get_right(curNode);

	}
	// 탐색결과 없음 . 실패

	return NULL;
}