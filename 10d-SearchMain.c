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
	printf("\b\b]\n"); // \b 백스페이스 해서 마지막에 , 안나오게 하는거.
}

// sort의 성능 테스트를 위한 여러가지의 배열
void genIncSorted(int arr[], int n) // 오름차순 배열 생성
{
	for (int i = 0; i <= n; i++) {
		arr[i] = i + 1; // 1부터 n까지의 값을 넣는다.
	}
}
void genDecSorted(int arr[], int n) // 내림차순 배열 생성
{
	for (int i = 0; i < n; i++) {
		arr[i] = n - i; // n부터 1까지의 값을 넣는다.
	}
}
void shuffleArr(int arr[], int n) // 배열 섞기
{
	srand(time(NULL));
	if (n > 1) { // 배열길이 2개 이상인 경우만 shuffle
		for (int i = 0; i < n - 1; i++) {
			// i번째와 오른쪽의 임의의 j번쨰와 swap 
			// 원래 rand의 범위가 RAND_MAX 까지 인데 / (n - i) + 1 이걸 통해서
			// 범위를 n에서 i사이로 한정시킨거다.
			int j = i + rand() / (RAND_MAX / (n - i) + 1);

			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;

		}

	}
}
void genRandom(int arr[], int n) // 무작위 배열 1~n 범위
{
	genIncSorted(arr, n); // 그냥 오름차순 하나 가져와서
	shuffleArr(arr, n); // 섞으면 무작위 배열
}

// 배열로 부터 List 생성
void genList(List* pList, int arr[], int n) {
	for (int i = 0; i < n; i++) {
		list_add(pList, arr[i]);
	}
}
//-----------------------------------------------
typedef void* fnSearch(void*, int); // 검색 함수 타입
// 이제 이게 뭔지 알겠다. 이거 이렇게 생긴 타입의 함수를 사용할 수 있게 만든거다.
// 즉 input output만 위와 같으면 사용할 수 있음


// collection 에서 arr[]의 data들을 탐색하여
// 평균 검색 시간을 체크
// ex) List <= [5,1,2,4,3]
// List 에서 탐색 [1,2,3,4,5]


void chkTimeLapArray(fnSearch search, void *collection, int arr[], int n, char *title) {
	clock_t start, end;

	int cnt = 0; // search 성공한 개수

	
	//각 개별적인 search의 경과시간 누적합산한뒤 평균을 구한다.
	long duartion = 0; //누적 합산용
	for (int i = 0; i < n; i++) {
		start = clock();
		if(search(collection, arr[i]) != NULL) cnt++;
		end = clock();
		duartion += end - start;
	}

	printf("%s(%d/%d개 탐색) 수행결과 %.3f ms\n",title,cnt,n,(double)duartion / n);
}

// 배열로부터 BST 생성
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
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "리스트탐색");
	list_destroy(&list);
	

	//-------------------------------------------------------------------------

	BTreeNode* pRoot;
	bst_make_init(&pRoot);
	genBST(&pRoot, workArr, DATA_SIZE);

	chkTimeLapArray(bst_search, pRoot,srcArr,DATA_SIZE, "BST 탐색");

	btree_delete(pRoot);


}