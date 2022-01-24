#ifndef __HEAP_H_
#define __HEAP_H_
#define SUCCESS 1
#define FAIL 0

//#define HEAP_LEN 100

/* Heap 의 데이터 */

typedef int HData;

// d1의 우선순위가 높다면 0보다 큰 값 리턴
// d2의 우선순위가 높다면 0보다 작은 값 리턴
// d1과 d2의 우선순위가 같다면 0을 리턴
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap {
	// HData heapArr[HEAP_LEN]; // 배열로 구현 1-base
	HData* heapArr; // 동적 메모리로 구현 ★ 
	int numData; //담고 있는 데이터 개수

	fnPriorityComp* comp; // 우선순위 비교 함수 // 얘는 함수이다 (함수 포인터)
} Heap;


/* Heap 의 동작 */

// 힙 초기화
//void heap_init(Heap *ph, fnPriorityComp pc); // 원래 힙
void heap_init(Heap* ph, int len); // 동적 메모리 초기화
void heap_destroy(Heap* ph); // 동적 메모리 해제

// 힙이 비어있나?
int heap_is_empty(Heap *ph);

// 힙에 데이터 추가 (INSERT)
void heap_insert(Heap *ph, HData data);

// 힙에서 삭제 (ROOT 삭제) 하여 리턴 (DELETE)
HData heap_delete(Heap *ph);

// 힙 정렬
Heap* g_hp;
void HeapSort(int[], int n);



#endif