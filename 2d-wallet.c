#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

#include"2d wallet.h"

// ���� �ʱ�ȭ
void wal_init(wal* p) {
	printf("������ �ʱ�ȭ �մϴ�.\n");
	p->bill1000 = 0;
	p->coin500 = 0;

	// memset(p, 0, sizeof(wal)*2);
	// ���� ����ü�� �ʱ�ȭ �Ұ� �ʹ� ������ �ϳ��ϳ� ���ϴϱ�.
	// �̷��� memset���� ���� 1�� �ʱ�ȭ ��Ű�� ����̴�.
}
// ����(����) �ֱ�
void wal_put_coin(wal* p, int num) {
	p->coin500 += num;
	printf("500�� ���� [ %d ]�� �־� [ %d ]�� �Ǿ����ϴ�.\n", num, p->coin500);
}
void wal_put_bill(wal* p, int num) {
	p->bill1000 += num;
	printf("1000�� ���� [ %d ]�� �־� [ %d ]�� �Ǿ����ϴ�.\n", num, p->bill1000);
}
// ����(����) ����
int wal_take_coin(wal* p, int num) {
	if (p->coin500 < num) {
		printf("500�� ������ [ %d ]�� �����Ͽ� �� �� �����ϴ�.\n",num - p->coin500);
		return FAIL;
	}
	p->coin500 -= num;
	printf("500�� ���� [ %d ]�� ���� [ %d ]�� �Ǿ����ϴ�.\n", num, p->coin500);
	return SUCCESS;
}
int wal_take_bill(wal* p, int num) {
	if (p->bill1000 < num) {
		printf("1000�� ���� [ %d ]�� �����Ͽ� �� �� �����ϴ�.\n",num-p->bill1000);
		return FAIL;
	}
	p->bill1000 -= num;
	printf("1000�� ���� [ %d ]�� ���� [ %d ]�� �Ǿ����ϴ�.\n", num, p->bill1000);
	return SUCCESS;
}
// ���� �ܾ� Ȯ��
int wal_exchange(wal* p) {
	int result = 0;
	result = p->bill1000 * 1000 + p->coin500 * 500;
	return result;
}