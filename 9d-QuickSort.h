#ifndef __QUICKSORT_H_
#define __QUICKSORT_H_

// �迭 �ΰ� �� �ٲٱ�
void Swap(int arr[], int idx1, int idx2);


//�迭 ���� ���� �ɰ��� (�ɰ� index ���� <-- pivot)
int Partition(int arr[], int left, int right);

// ��������� ������ ����
void QuickSort(int arr[], int left, int right);

void QuickSortMain(int arr[], int n); // �����׽�Ʈ��
#endif