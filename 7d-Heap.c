#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include "7d-Heap.h"


//----------------------------------------

// 함수 --> 매크로로 바꾼건 return으로 나누기 곱하기 하면 오래 걸려서 매크로로 바꿈
// 그리고 나누기 곱하기가 시간이 오래 걸리므로 shift로 옮겨서 한다.

// 부모노드 인덱스
#define GET_PARENT_IDX(idx) ((idx >>1 )) // idx /2
/*
{ 
// 원래는 이렇게 함수였음
// ctrl+ (r+r) 하면 쓰인곳 전체 이름 다 바꿀수 있음
	return idx / 2;
}
*/
// left 자식노드 인덱스
#define GET_LEFT_IDX(idx) ((idx << 1 )) // idx *2
// right 자식노드 인덱스
#define GET_RIGHT_IDX(idx) ((idx << 1 )+1) // idx *2 +1


// 비교함수 대신 매크로 (성능 UP)
#define COMP_ASC(d1,d2) ((d2)-(d1)) // 오름차순
#define COMP_DESC(d1,d2) ((d1)-(d2)) // 내림차순

// ctrl+h 로 원하는 부위 선택해서 원하는걸로 아예 바꿀수도 있다.

// idx의 자식들 중 우선 순위가 높은 자식의 index값 리턴 --> delete에 사용
int getHighPriority(Heap* ph, int idx) {
	// 자식 노드가 없다면 0 리턴
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;
	// 자식이 하나 밖에 없다면 --> 왼쪽자식노드가 (유일한)마지막 노드이다.
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);
	// 자식이 둘 있는 경우 우선 순위 비교함수 사용!
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0) {
		return GET_RIGHT_IDX(idx);
	}
	else {
		return GET_LEFT_IDX(idx);
	}
}

/* Heap 의 동작 */

// 힙 초기화
/*
void heap_init(Heap* ph, fnPriorityComp pc) {
	ph->numData = 0; // 데이터(노드) 개수
	COMP_ASC = pc; // 비교함수

}
*/

// 동적 메모리 초기화
void heap_init(Heap* ph, int len) {
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); 
	// +1개 만큼 메모리 필요 1인덱스(1-base) 부터 시작하기 때문에
	g_hp = ph;
}

// 동적 메모리 해제
void heap_destroy(Heap* ph) {
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// 힙이 비어있나?
int heap_is_empty(Heap* ph) {
	if (ph->numData == 0) return SUCCESS;

	return FAIL;
}

// 힙에 데이터 추가 (INSERT)
void heap_insert(Heap* ph, HData data) {
	// 새로 INSERT 되는 데이터는 맨 끝에서 시작

	int idx = ph->numData + 1; 
	// 배열 인덱스는 '1' 부터 시작한다.
	// 전체 node의 개수는 numData이고 numData는 곧 맨마지막 노드의 인덱스이다.

	// 아래 while 문이 수행되면서 새로 insert된 data가 위치할 idx를 결정
	// 이게 여기서 위에 부모들중 제낄거 다 제낀 idx를 찾는거야.
	while (idx != 1) { // root(최상위) 에 도달할때까지

		// 부모보다 우선 순위가 높다면
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) {
			// 부모를 끌어 내리고 --> idx
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			// idx -> 부모 index로 이동
			idx = GET_PARENT_IDX(idx);
		}

		else {
			// 부모보다 우선순위가 같거나 작다면.. 여기서 멈춤
			break;
		}
	}

	ph->heapArr[idx] = data; // idx가 멈춘 그곳에 새로 insert된 data 쓰기
	ph->numData++; // 데이터 개수 +1 증가

}

// 힙에서 삭제 (ROOT 삭제) 하여 리턴 (DELETE)
HData heap_delete(Heap* ph) {
	// 인덱스 1번이 root노드 이거를 제거
	HData rootData = ph->heapArr[1];

	// 마지막 노드가 자리잡을 위치 idx를 결정해야 한다.
	// idx가 결정 될 때까지 마지막 노드의 data를 보관해 놓는다.
	HData lastElem = ph->heapArr[ph->numData];

	int idx = 1; //마지막 노드가 일단 root의 자리에 오른다.
	int childIdx;
	// 일단 자식 노드중 우선순위 높은거 선택
	// 만약 자식이 하나도 없다면 0이 리턴되어 while문 종료
	// 아래 while 문은 결국 idx 값을 결정하기 위함.
	while(childIdx = getHighPriority(ph,idx)) { // -> 이게 어떻게 계속 돌까?
		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교.
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) {
			break;
		}
		// 자식의 우선순위가 더 크다면, 그 자식이 부모의 자리로 교체
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// 다음 비교를 위해 마지막 노드 idx를 좀전의 자식위치로 내리기
		idx = childIdx;
	}
	// while이 다 끝난 그 자리(idx)가, 마지막 노드(lastElem)이 위치 할 곳이다.
	ph->heapArr[idx] = lastElem;
	ph->numData--;

	return rootData; // 최초에 저장해 놓았던 rootdata 리턴
}

// 힙 정렬
void HeapSort(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		heap_insert(g_hp, arr[i]);
	}
	for (i = 0; i < n; i++) {
		arr[i] = heap_delete(g_hp);
	}
}