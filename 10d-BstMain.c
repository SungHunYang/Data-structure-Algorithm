#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"6d-BinaryTree.h"
#include"10d-BinartSearchTree.h"

void main() {
	
	BTreeNode* pRoot; // BST�� ��Ʈ
	BTreeNode* pSearchNode; // Ž�� ���

	bst_make_init(&pRoot);  // -> ���� ������ ���� & ���ΰ� ����?
	
	bst_insert(&pRoot, 12);
	bst_insert(&pRoot, 8);
	bst_insert(&pRoot, 9);
	bst_insert(&pRoot, 17);
	bst_insert(&pRoot, 10);
	bst_insert(&pRoot, 4);
	bst_insert(&pRoot, 21);
	bst_insert(&pRoot, 2);
	bst_insert(&pRoot, 13);
	bst_insert(&pRoot, 7);
	/*
*             12
*          ��     ��
*         8        17
*       �� ��     ��  ��
*      4    9    13   21
*   ��  ��   ��
*   2   7    10
*/

	BTreeNode* p = bst_search(pRoot, 9);
	if (p) printf("%d\n", p->Data);
	else printf("����\n");


}