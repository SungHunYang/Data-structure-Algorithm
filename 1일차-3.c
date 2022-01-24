#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h> 
void fnPlus(int a, int b) {
	printf("���� : %d + %d = %d\n", a, b, a + b);
}
void fnMinus(int a, int b)
{
	printf("����: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("����: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("������: %d / %d = %d\n", a, b, a / b);
}
void doAction(int a, int b, void(*fnOp)(int, int)) {
	fnOp(a, b); // �Լ��� �Ű������� �����ִ� ��
}

typedef void fnAction(int, int); // �Լ������� Ÿ�� ����
void doAction2(int a, int b, fnAction* fnOp) {
	fnOp(a, b); // �̰� �� �Ϲ����� �Լ� �Ű����� ����
	// ����ü �Լ��� ���� �ϴ� �Ϲ����� ���
}
void main() {

	/* 
		�Լ� ������
		'�Լ��̸�' �� �� '������'�� �ȴ�.
	*/

	{
		fnPlus(10, 20);
		printf("fnplus -> %p\n", fnPlus); // --> �Լ� �̸��� ���������� ������

		// �Լ������ʹ� '����' �� �� 'ȣ�� ����'
		// ���� ������ * ����Ͽ� ȣ��
		(*fnPlus)(30, 40);

		// �Լ� ������ Ÿ�� ���� ���� ����
		// int *p; <-- int �� ���� ������
		// void �����ϰ� (int,int) �Ű����� �޴� �Լ��� ���� �Լ� ������
		void(*fnOp)(int, int); //<- fnOp��� '�Լ������� ���� ����'

		//������ ���� <- ���԰���!
		fnOp = fnPlus; // void �����ϰ� (int,int) �Ű����� �޴� �Լ� ��� Ÿ���� �Ȱ��� ���԰���
		// ��, fnPlus = void(*fnOp)(int, int); �̷��� �����

		// ���� fnOp�� �Լ�ó�� ��밡��
		// ����������
		(*fnOp)(70, 100); // �̰� ���� ��� ����
		fnOp(70, 100);
	}

	printf("\n");
	{
		// �Լ��������� ����.
		// '����'�� ���߿� ���� ���� (late-binding)

		int op;
		printf("���۹�ȣ�� �Է��ϼ���(0:+ 1:- 2:* 3:/): ");
		scanf("%d", &op);

		int a = 30, b = 10;
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			if (op == 0)
				fnPlus(a, b); // <-- �� ������ �����ڵ�� fnPlus �� ȣ��
			else if (op == 1)
				fnMinus(a, b);
			else if (op == 2)
				fnMul(a, b);
			else if (op == 3)
				fnDiv(a, b);
		}
		// �� �̹� �������Ҷ� �ڵ�� ��õ� 'Ư��'�Լ���
		// ����ǵ��� ���ε� �ȴ�.  --> Early Binding �̶� ��
		// �� ��ȯ������ ���ǹ��� ���� ������ �Լ� ȣ���� ȣ���ؾ� �ϴ�, ���Ǻб⹮ �ε尡 ŭ

		// �ݸ� �Լ������� �����ϸ�
		void(*fnAction)(int, int);

		// �Լ��������� �迭 (�Լ��鸸 ��Ƴ��� �迭)
		void(*fnOpArr[4])(int, int) = {fnPlus,fnMinus,fnMul,fnDiv};
		// fnOpArr[0] => fnPlus
		// fnOpArr[1] => fnMinus ...


		printf("\n");
		fnAction = fnOpArr[op]; // -> �̷� ���̸� �Ʊ� for�� ó�� 
		// if���� ������ ���� �ϳ��� �������鼭 ���� �ʿ䰡 ��������
		// �ٷιٷ� ���ü� �ִ�.
		for (i = 0; i < 5; i++) {
			fnAction(a, b);
		// �� fnAction �� ����.. �׷��� ������ �������� ������ �������� �𸥴� (�� ���ε��� �Ǿ� ���� �ʴ�)
		// ���� �ؾ� ���߿� ������ �����ȴ�.   late-binding
			// ���ε��̶�°� �������ٶ�� ��! , 
			//�� late-binding�� ���߿� ������ �ϸ� op�� ���� ���ͼ� fnAction�� �������ٴ� �Ŵ�.
	    // ����: ���ǹ��� ���� �ε尡 ����.
	    // �������!!

		// �Լ� �����͵� �����ʹ�!  
		// �Ű������� �Ѱ��ټ���, ���ϰ����� ��������
		// �迭 ���Ұ� �ɼ��� �ִ�!!
		}

		printf('\n');
		{
			doAction(333, 444, fnPlus);
			doAction(333, 444, fnMinus);
			doAction(333, 444, fnMul);
			doAction(333, 444, fnDiv);
		}
		printf('\n');
		{
			doAction2(333, 444, fnPlus);
			doAction2(333, 444, fnMinus);
			doAction2(333, 444, fnMul);
			doAction2(333, 444, fnDiv);
		}

	}
}