#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
#include"2d wallet.h"

void main() {
	wal mywallet; // ���� ����

	wal_init(&mywallet); // ���� �ʱ�ȭ

	wal_put_coin(&mywallet, 3); // ���� �ֱ�
	wal_put_bill(&mywallet, 3); // ���� �ֱ�
	printf("�ܾ� [ %d ] �� \n",wal_exchange(&mywallet));

	wal_put_coin(&mywallet, 2); // ���� �ֱ�
	wal_put_bill(&mywallet, 3); // ���� �ֱ�
	printf("�ܾ� [ %d ] ��\n", wal_exchange(&mywallet));

	wal_take_coin(&mywallet, 50); // ���� ����
	wal_take_bill(&mywallet, 50); // ���� ����

	wal_take_coin(&mywallet, 2); // ���� ����
	wal_take_bill(&mywallet, 1); // ���� ����
	printf("�ܾ� [ %d ] ��\n", wal_exchange(&mywallet));

}