#ifndef __BST_H__
#define __BST_H__
#include"6d-BinaryTree.h"

#define SUCCESS 1
#define FAIL 0


// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode** ppRoot); 
// ���� ������ --> ������ �߰��� �� �ƹ��� ��尡 ���°��
// ��� ��尡 �Ǿ�� �ϱ� ������ -> ������ ��ü�� �ٲ�� �ϱ� ������

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode** ppRoot, BTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode* bst_search(BTreeNode* pRoot, BTData data);



#endif
