#ifndef __SORT_H_
#define __SORT_H_

void printArr(int arr[], int n);
void genRandom(int arr[], int n); // ������ �迭 1~n ����
void genIncSorted(int arr[], int n); // �������� �迭 ����
void genDecSorted(int arr[], int n); // �������� �迭 ����
void shuffleArr(int arr[], int n); // �迭 ����

//----------------------------------------------------------
typedef void fnSort(int[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char* szTitle);


//----------------------------------------------------------
void BubbleSort(int arr[], int n); // ��������
void Selectionsort(int arr[], int n); // ��������
void Insertionsort(int arr[], int n); // ��������

#endif
