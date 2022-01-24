#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"4d-LinkedList.h"
#include"6d-BinaryTree.h"
#include"10d-BinartSearchTree.h"

#define DATA_SIZE 10000

void printArr(int arr[], int n) {

	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b]\n"); // \b �齺���̽� �ؼ� �������� , �ȳ����� �ϴ°�.
}

// sort�� ���� �׽�Ʈ�� ���� ���������� �迭
void genIncSorted(int arr[], int n) // �������� �迭 ����
{
	for (int i = 0; i <= n; i++) {
		arr[i] = i + 1; // 1���� n������ ���� �ִ´�.
	}
}
void genDecSorted(int arr[], int n) // �������� �迭 ����
{
	for (int i = 0; i < n; i++) {
		arr[i] = n - i; // n���� 1������ ���� �ִ´�.
	}
}
void shuffleArr(int arr[], int n) // �迭 ����
{
	srand(time(NULL));
	if (n > 1) { // �迭���� 2�� �̻��� ��츸 shuffle
		for (int i = 0; i < n - 1; i++) {
			// i��°�� �������� ������ j������ swap 
			// ���� rand�� ������ RAND_MAX ���� �ε� / (n - i) + 1 �̰� ���ؼ�
			// ������ n���� i���̷� ������Ų�Ŵ�.
			int j = i + rand() / (RAND_MAX / (n - i) + 1);

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;

		}

	}
}
void genRandom(int arr[], int n) // ������ �迭 1~n ����
{
	genIncSorted(arr, n); // �׳� �������� �ϳ� �����ͼ�
	shuffleArr(arr, n); // ������ ������ �迭
}

// �迭�� ���� List ����
void genList(List* pList, int arr[], int n) {
	for (int i = 0; i < n; i++) {
		list_add(pList, arr[i]);
	}
}
//-----------------------------------------------
typedef void* fnSearch(void*, int); // �˻� �Լ� Ÿ��
// ���� �̰� ���� �˰ڴ�. �̰� �̷��� ���� Ÿ���� �Լ��� ����� �� �ְ� ����Ŵ�.
// �� input output�� ���� ������ ����� �� ����


// collection ���� arr[]�� data���� Ž���Ͽ�
// ��� �˻� �ð��� üũ
// ex) List <= [5,1,2,4,3]
// List ���� Ž�� [1,2,3,4,5]


void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title) {
	clock_t start, end;

	int cnt = 0; // search ������ ����

	
	//�� �������� search�� ����ð� �����ջ��ѵ� ����� ���Ѵ�.
	long duartion = 0; //���� �ջ��
	for (int i = 0; i < n; i++) {
		start = clock();
		if(search(collection, arr[i]) != NULL) cnt++;
		end = clock();
		duartion += end - start;
	}

	printf("%s(%d/%d�� Ž��) ������ %.3f ms\n",title,cnt,n,(double)duartion / n);
}

// �迭�κ��� BST ����
void genBST(BTreeNode *ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		bst_insert(ppRoot, arr[i]);

}

void main() {

	
	int srcArr[DATA_SIZE];
	int workArr[DATA_SIZE];
	
	genIncSorted(srcArr, DATA_SIZE); // ex [1,2,3,4,5]

	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE); // ex [5,1,2,4,3]
	
	List list;
	list_init_(&list);
	genList(&list, workArr, DATA_SIZE); // list <- workArr
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "����ƮŽ��");
	list_destroy(&list);
	

	//-------------------------------------------------------------------------

	BTreeNode* pRoot;
	bst_make_init(&pRoot);
	genBST(&pRoot, workArr, DATA_SIZE);

	chkTimeLapArray(bst_search, pRoot,srcArr,DATA_SIZE, "BST Ž��");

	btree_delete(pRoot);


}