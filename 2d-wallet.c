#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

#include"2d wallet.h"

// 지갑 초기화
void wal_init(wal* p) {
	printf("지갑을 초기화 합니다.\n");
	p->bill1000 = 0;
	p->coin500 = 0;

	// memset(p, 0, sizeof(wal)*2);
	// 만일 구조체에 초기화 할게 너무 많으면 하나하나 못하니까.
	// 이렇게 memset으로 전부 1로 초기화 시키는 방법이다.
}
// 동전(지폐) 넣기
void wal_put_coin(wal* p, int num) {
	p->coin500 += num;
	printf("500원 동전 [ %d ]개 넣어 [ %d ]가 되었습니다.\n", num, p->coin500);
}
void wal_put_bill(wal* p, int num) {
	p->bill1000 += num;
	printf("1000원 지폐 [ %d ]개 넣어 [ %d ]가 되었습니다.\n", num, p->bill1000);
}
// 동전(지폐) 빼기
int wal_take_coin(wal* p, int num) {
	if (p->coin500 < num) {
		printf("500원 동전이 [ %d ]개 부족하여 뺄 수 없습니다.\n",num - p->coin500);
		return FAIL;
	}
	p->coin500 -= num;
	printf("500원 동전 [ %d ]개 빼서 [ %d ]가 되었습니다.\n", num, p->coin500);
	return SUCCESS;
}
int wal_take_bill(wal* p, int num) {
	if (p->bill1000 < num) {
		printf("1000원 지폐가 [ %d ]개 부족하여 뺄 수 없습니다.\n",num-p->bill1000);
		return FAIL;
	}
	p->bill1000 -= num;
	printf("1000원 지폐 [ %d ]개 빼서 [ %d ]가 되었습니다.\n", num, p->bill1000);
	return SUCCESS;
}
// 지갑 잔액 확인
int wal_exchange(wal* p) {
	int result = 0;
	result = p->bill1000 * 1000 + p->coin500 * 500;
	return result;
}