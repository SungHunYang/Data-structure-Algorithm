#ifndef __BST_H__
#define __BST_H__
#include"6d-BinaryTree.h"

#define SUCCESS 1
#define FAIL 0


// 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode** ppRoot); 
// 이중 포인터 --> 데이터 추가할 때 아무런 노드가 없는경우
// 헤드 노드가 되어야 하기 때문에 -> 포인터 자체를 바꿔야 하기 때문에

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
int bst_insert(BTreeNode** ppRoot, BTData data);

// 이진 탐색 트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode* pRoot, BTData data);



#endif
