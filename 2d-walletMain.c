#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"2d wallet.h"

void main() {
	wal mywallet; // 지갑 생성

	wal_init(&mywallet); // 지갑 초기화

	wal_put_coin(&mywallet, 3); // 동전 넣기
	wal_put_bill(&mywallet, 3); // 지폐 넣기
	printf("잔액 [ %d ] 원 \n",wal_exchange(&mywallet));

	wal_put_coin(&mywallet, 2); // 동전 넣기
	wal_put_bill(&mywallet, 3); // 지폐 넣기
	printf("잔액 [ %d ] 원\n", wal_exchange(&mywallet));

	wal_take_coin(&mywallet, 50); // 동전 빼기
	wal_take_bill(&mywallet, 50); // 지폐 빼기

	wal_take_coin(&mywallet, 2); // 동전 빼기
	wal_take_bill(&mywallet, 1); // 지폐 빼기
	printf("잔액 [ %d ] 원\n", wal_exchange(&mywallet));

}