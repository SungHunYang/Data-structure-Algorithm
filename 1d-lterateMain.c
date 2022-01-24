#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

#define MAX_LENGTH 4
#define TRUE 1
#define FALSE 0

typedef struct _IterArray {
	int arr[MAX_LENGTH];
	int curPosition; // iterator 구현을 위한 값
}IterArr;

// iterator 초기화
void iter_init(IterArr* p) {
	p->curPosition = -1; // 이게 배열 제일 처음 가르키는 건대,
	// 다시 줄세우는 것. 왜 0이 아니고 -1인지는 
	// 밑에 함수에서 추출할 다음 데이터 확인하려면
	// +1 증가 시켜야 하는데 만일 0 이면 제일 처음 데이터는 확인이 불가능 해서 -1 부터 한다.
}

// 다음에 추출할 데이터 있나?
int iter_hasNext(IterArr* p) {
	if (p->curPosition + 1 < MAX_LENGTH) {
		return TRUE;
	}
	else {
		printf("더 이상 추출할 데이터가 없습니다.\n");
		return FALSE;
	}
}

// 다음 데이터 추출
int iter_next(IterArr* p) {
	p->curPosition++; // 우선! curPosition이 next 로 +1 증가.
	// 왜냐면 위에서는 체크만 한거지 앞으로 안 땡겼으니까.
	return p->arr[p->curPosition]; // curPosition이 가르키는 값 추출

		// 여기가 curPosition 이 -1인 이유다
		// ++ 부터 값을 내기 때문에 0번을 뽑으려면 -1이여야 한다.
		// 0 부터 시작하면 바로 ++ 하면 첫번째 0번째 배열은 뽑을수가 없어서
}

void main() {

	IterArr data = { {10,20,30,40}, -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) // 더 추출할 데이터가 있나?
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	// 다시 iterator 돌리려 하면.. (안돌아간다.)
	// 왜냐면 curPosition이 끝에 가 있어서 hasNext가 FALSE를 내기 때문에
	while (iter_hasNext(&data)) // 더 추출할 데이터가 있나?
	{
		printf("%d ", iter_next(&data));
	}
	// 새로 데이터를 추출하려면 iterator를 새로 동작 시켜야 한다.
	// 그래서 iterator는 일회용 // 다시 쓰려면 iter_init(&data) 을 다시 적어줘야 한다.
}

/* 거의 대부분의 현대 언어들에선 Iteration(반복자) 지원함.
*
*	Python 의 iterable객체
*		ex) for a in b:  <-- b 는 'iterable' 해야 한다.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection 의 Iterator 객체
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/
