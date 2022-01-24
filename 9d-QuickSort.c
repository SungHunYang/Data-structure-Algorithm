#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"9d-QuickSort.h"


// �迭 �ΰ� �� �ٲٱ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


//�迭 ���� ���� �ɰ��� (�ɰ� index ���� <-- pivot)
int Partition(int arr[], int left, int right) {
	
	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1; // low�� �ǹ� �����ʺ��� ����(�ε���)
	int high = right; // high�� right ���� ����(�ε���)

	// TODO

	while(low <= high) // low, high�� �������� ���� ������ �ݺ��ϸ鼭 low, high �̵�
	{
		// low �������� ����̵�, pivot���� ū ���� ���� �� ����
		while(pivot >= arr[low] && low <= right){
			low++;
		}
		// high �������� ����̵�, pivot���� ���� ���� ���� �� ����
		while (pivot <= arr[high] && high >= (left+1)) {
			high--;
		}
		// low�� high�� ���߸�
		// low, high�� �������� ���� ���¶�� Swap ����
		if(low <= high)
			Swap(arr, low, high);

	}
	// '�ǹ�(left)' �� 'high'�� ����Ű�� ��� ��ȯ
	Swap(arr, left, high);
	// Swap�� ������ �� �������� 
	// high�� ������ pivot���� ū������ ���ְ�,
	// high�� ������ pivot���� ���������� ���ִ�.
	return high; // ������ �ǹ��� ��ġ����(�ε���) ���� --> Swap���� high�� pivot�� �ٲ�����ϱ�
}

// ��������� ������ ����
void QuickSort(int arr[], int left, int right)
{
	if (left <= right) {
		int pivot = Partition(arr, left, right); // pivot ���ϰ� �ѷ� �ɰ�
		// pivot ���� ������ ������
		printf("���� ��� %d\n", arr[pivot]);
		QuickSort(arr, left, pivot - 1);
		// pivot ������ ������ ������
		printf("������ ��� %d\n", arr[pivot]);
		QuickSort(arr, pivot+1, right);
	}
}

// �����׽�Ʈ��
void QuickSortMain(int arr[], int n) {
	QuickSort(arr, 0, n - 1);
}