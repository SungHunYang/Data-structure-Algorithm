#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"6d-BinaryTree.h"
#include"10d-BinartSearchTree.h"

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode** ppRoot)
{
	*ppRoot = NULL; // ������ �� �ʱ�ȭ

}

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
int bst_insert(BTreeNode** ppRoot, BTData data)
{
	BTreeNode* parentNode = NULL; // parent node
	BTreeNode* curNode = *ppRoot; // ������ ������ : �ϴ� root���� �����Ѵ�.
	BTreeNode* newNode = NULL;

	// ���ο� ��尡 �߰��� ��ġ�� ã�� ��������.
	while (curNode != NULL) { // ���� ������ ��������, �ٷ� �װ��� ���Ե� ��ġ
		if (data == btree_get_data(curNode))
			return FAIL; // BST ���� key�� �ߺ���� X

		parentNode = curNode;
		if (btree_get_data(curNode) > data)// ���� �Ϸ��� data�� ����� �����ͺ��� �� �۴ٸ� ����
			curNode = btree_get_left(curNode);
		else   // ���� �Ϸ��� data�� ����� �����ͺ��� �� �۴ٸ� ������
			curNode = btree_get_right(curNode);
	}

	// �߰��� �� ����� ����
	newNode = btree_make_node();
	btree_set_data(newNode, data);

	//parentNode�� ���� ��忡 �� ��带 �߰�
	if (parentNode != NULL) {
		if (data < btree_get_data(parentNode)) // �θ��� �����ͺ��� �۴ٸ� left�� ���δ�.
			btree_make_left(parentNode, newNode);
		else
			btree_make_right(parentNode, newNode);
	}
	else { // ù��° ����� ���, �� ��尡 ��Ʈ ��ġ�̱⿡ parentNode�� NULL�� ���´�
		
		*ppRoot = newNode; // ��Ʈ ����!

	}

	return SUCCESS;
}

// ���� Ž�� Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode* bst_search(BTreeNode* pRoot, BTData data) {

	BTreeNode* curNode = pRoot; // root���� Ž�� ����
	BTData curData; // current data

	while (curNode != NULL)  // Ž���� �� �������ٰ� ���ܳ����� �����ϸ� Ž�� ����
	{
		curData = btree_get_data(curNode); // ���� ����� ������

		if (data == curData)
			return curNode; // �߰�! Ž������, ����� �����͸� ����
		
		if (data < curData) // data ���� ����� ������ ���� �۴ٸ� left �� �̵�
			curNode = btree_get_left(curNode);
		else // data ���� ����� ������ ���� ũ�ٸ� right �� �̵�
			curNode = btree_get_right(curNode);

	}
	// Ž����� ���� . ����

	return NULL;
}