#ifndef __WALLET_H_
#define __WALLET_H_
#define SUCCESS 1
#define FAIL 0
// wallet �� �߻��ڷ���(ADT)


// ������ ������
typedef struct _wallet {
	int coin500;//500��¥�� ���� ����
	int bill1000;// 1000�� ¥�� ���� ����
}wal;


// ������ ����

// ���� �ʱ�ȭ
void wal_init(wal* p);
// ����(����) �ֱ�
void wal_put_coin(wal* p, int num);
void wal_put_bill(wal* p, int num);
// ����(����) ����
int wal_take_coin(wal* p, int num);
int wal_take_bill(wal* p, int num);
// ���� �ܾ� Ȯ��
int wal_exchange(wal* p);
#endif
