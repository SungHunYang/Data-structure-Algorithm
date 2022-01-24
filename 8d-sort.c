#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"8d-sort.h"
#include"7d-Heap.h"

void printArr(int arr[], int n) {

	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b]\n"); // \b �齺���̽� �ؼ� �������� , �ȳ����� �ϴ°�.
}

// sort�� ���� �׽�Ʈ�� ���� ���������� �迭

void genRandom(int arr[], int n) // ������ �迭 1~n ����
{
	genIncSorted(arr, n); // �׳� �������� �ϳ� �����ͼ�
	shuffleArr(arr, n); // ������ ������ �迭
}
void genIncSorted(int arr[], int n) // �������� �迭 ����
{
	for (int i = 0; i <= n; i++) {
		arr[i] = i + 1; // 1���� n������ ���� �ִ´�.
	}
}
void genDecSorted(int arr[], int n) // �������� �迭 ����
{
	for (int i = 0; i < n; i++) {
		arr[i] = n-i; // n���� 1������ ���� �ִ´�.
	}
}
void shuffleArr(int arr[], int n) // �迭 ����
{
	srand(time(NULL));
	if (n > 1) { // �迭���� 2�� �̻��� ��츸 shuffle
		for (int i = 0; i < n-1; i++) {
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

//----------------------------------------------------------

// ���� üũ
void chkTimeLap(fnSort sort, int arr[], int n, char* szTitle)
{
	clock_t start, end;
	start = clock();

	sort(arr, n);

	end = clock();
	printf("%s (size: %d) ������ : %ld ms\n", szTitle, n, end - start);

}

//-------------------------------------------

void BubbleSort(int arr[], int n)// ��������
{
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < (n-i)-1; j++) { // ù cycle���� n-1�� �� �������� n-2.. n-3.. �̷���
			//for�� �ȿ� for�� O(n^2)�̴�.
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];	//<<�̵�>> �ѻ���Ŭ�� �ִ� (n-i)-1�� �߻�
				arr[j + 1] = arr[j]; //<<�̵�>>
				arr[j] = temp;		//<<�̵�>>
			}
		}
	}
}
void Selectionsort(int arr[], int n) // ��������
{
	int temp;
	int min_idx;

	for (int i = 0; i < n - 1; i++) {
		min_idx = i;
		for (int j = i+1; j < n; j++) {
			//for�� �ȿ� for�� O(n^2)�̴�.
			if (arr[min_idx] > arr[j]) { //������ min_idx��° ���� ���� ���̸� <<��>>
				min_idx = j;  // min_idx�� �ٲ��ش�.
			}
		}
		if(i!=min_idx){				// <<�̵�>> <-- 1 cycle�� ���ƾ� 1�� �߻�
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
		// �߰��ܰ����
		//printArr(arr, n);
	}
}
void Insertionsort(int arr[], int n) // ��������
{
	int i, j;
	int insData;
	for (i = 1; i < n; i++)   // i = 1���� ����!
	{
		insData = arr[i];   // i��° �����ʹ� insData�� �ӽ� ����
		for (j = i - 1; j >= 0; j--)  // i ���ʺ��� �������� �˻�
		{
			if (arr[j] > insData)   // insData ����  j��° �����Ͱ� ũ�� <<��>>
				arr[j + 1] = arr[j];    // j��° �����͸� �������� �̵� <<�̵�>>
				// ������ �̹� ���ĵǾ������ϱ�
				// temp���� �̰� �����ϴ�. �ٲܰ��� insData�� �����Ƿ�
			else
				break;   // ���� ��ġ ã������ Ż��!
		}
		arr[j + 1] = insData;  // ã�� ��ġ�� ���� ��� ����! <<�̵�>>
	}
}


