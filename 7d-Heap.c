#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "7d-Heap.h"


//----------------------------------------

// �Լ� --> ��ũ�η� �ٲ۰� return���� ������ ���ϱ� �ϸ� ���� �ɷ��� ��ũ�η� �ٲ�
// �׸��� ������ ���ϱⰡ �ð��� ���� �ɸ��Ƿ� shift�� �Űܼ� �Ѵ�.

// �θ��� �ε���
#define GET_PARENT_IDX(idx) ((idx >>1 )) // idx /2
/*
{ 
// ������ �̷��� �Լ�����
// ctrl+ (r+r) �ϸ� ���ΰ� ��ü �̸� �� �ٲܼ� ����
	return idx / 2;
}
*/
// left �ڽĳ�� �ε���
#define GET_LEFT_IDX(idx) ((idx << 1 )) // idx *2
// right �ڽĳ�� �ε���
#define GET_RIGHT_IDX(idx) ((idx << 1 )+1) // idx *2 +1


// ���Լ� ��� ��ũ�� (���� UP)
#define COMP_ASC(d1,d2) ((d2)-(d1)) // ��������
#define COMP_DESC(d1,d2) ((d1)-(d2)) // ��������

// ctrl+h �� ���ϴ� ���� �����ؼ� ���ϴ°ɷ� �ƿ� �ٲܼ��� �ִ�.

// idx�� �ڽĵ� �� �켱 ������ ���� �ڽ��� index�� ���� --> delete�� ���
int getHighPriority(Heap* ph, int idx) {
	// �ڽ� ��尡 ���ٸ� 0 ����
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;
	// �ڽ��� �ϳ� �ۿ� ���ٸ� --> �����ڽĳ�尡 (������)������ ����̴�.
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);
	// �ڽ��� �� �ִ� ��� �켱 ���� ���Լ� ���!
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0) {
		return GET_RIGHT_IDX(idx);
	}
	else {
		return GET_LEFT_IDX(idx);
	}
}

/* Heap �� ���� */

// �� �ʱ�ȭ
/*
void heap_init(Heap* ph, fnPriorityComp pc) {
	ph->numData = 0; // ������(���) ����
	COMP_ASC = pc; // ���Լ�

}
*/

// ���� �޸� �ʱ�ȭ
void heap_init(Heap* ph, int len) {
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); 
	// +1�� ��ŭ �޸� �ʿ� 1�ε���(1-base) ���� �����ϱ� ������
	g_hp = ph;
}

// ���� �޸� ����
void heap_destroy(Heap* ph) {
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// ���� ����ֳ�?
int heap_is_empty(Heap* ph) {
	if (ph->numData == 0) return SUCCESS;

	return FAIL;
}

// ���� ������ �߰� (INSERT)
void heap_insert(Heap* ph, HData data) {
	// ���� INSERT �Ǵ� �����ʹ� �� ������ ����

	int idx = ph->numData + 1; 
	// �迭 �ε����� '1' ���� �����Ѵ�.
	// ��ü node�� ������ numData�̰� numData�� �� �Ǹ����� ����� �ε����̴�.

	// �Ʒ� while ���� ����Ǹ鼭 ���� insert�� data�� ��ġ�� idx�� ����
	// �̰� ���⼭ ���� �θ���� ������ �� ���� idx�� ã�°ž�.
	while (idx != 1) { // root(�ֻ���) �� �����Ҷ�����

		// �θ𺸴� �켱 ������ ���ٸ�
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) {
			// �θ� ���� ������ --> idx
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			// idx -> �θ� index�� �̵�
			idx = GET_PARENT_IDX(idx);
		}

		else {
			// �θ𺸴� �켱������ ���ų� �۴ٸ�.. ���⼭ ����
			break;
		}
	}

	ph->heapArr[idx] = data; // idx�� ���� �װ��� ���� insert�� data ����
	ph->numData++; // ������ ���� +1 ����

}

// ������ ���� (ROOT ����) �Ͽ� ���� (DELETE)
HData heap_delete(Heap* ph) {
	// �ε��� 1���� root��� �̰Ÿ� ����
	HData rootData = ph->heapArr[1];

	// ������ ��尡 �ڸ����� ��ġ idx�� �����ؾ� �Ѵ�.
	// idx�� ���� �� ������ ������ ����� data�� ������ ���´�.
	HData lastElem = ph->heapArr[ph->numData];

	int idx = 1; //������ ��尡 �ϴ� root�� �ڸ��� ������.
	int childIdx;
	// �ϴ� �ڽ� ����� �켱���� ������ ����
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while�� ����
	// �Ʒ� while ���� �ᱹ idx ���� �����ϱ� ����.
	while(childIdx = getHighPriority(ph,idx)) { // -> �̰� ��� ��� ����?
		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) {
			break;
		}
		// �ڽ��� �켱������ �� ũ�ٸ�, �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// ���� �񱳸� ���� ������ ��� idx�� ������ �ڽ���ġ�� ������
		idx = childIdx;
	}
	// while�� �� ���� �� �ڸ�(idx)��, ������ ���(lastElem)�� ��ġ �� ���̴�.
	ph->heapArr[idx] = lastElem;
	ph->numData--;

	return rootData; // ���ʿ� ������ ���Ҵ� rootdata ����
}

// �� ����
void HeapSort(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		heap_insert(g_hp, arr[i]);
	}
	for (i = 0; i < n; i++) {
		arr[i] = heap_delete(g_hp);
	}
}