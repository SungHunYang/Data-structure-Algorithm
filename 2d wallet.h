#ifndef __WALLET_H_
#define __WALLET_H_
#define SUCCESS 1
#define FAIL 0
// wallet 의 추상자료형(ADT)


// 지갑의 데이터
typedef struct _wallet {
	int coin500;//500원짜리 동전 개수
	int bill1000;// 1000원 짜리 지폐 개수
}wal;


// 지갑의 동작

// 지갑 초기화
void wal_init(wal* p);
// 동전(지폐) 넣기
void wal_put_coin(wal* p, int num);
void wal_put_bill(wal* p, int num);
// 동전(지폐) 빼기
int wal_take_coin(wal* p, int num);
int wal_take_bill(wal* p, int num);
// 지갑 잔액 확인
int wal_exchange(wal* p);
#endif
