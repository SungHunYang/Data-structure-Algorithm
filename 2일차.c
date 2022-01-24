#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

/*
	C, C++ ���� ���� �����ϱ�
	���1:  time() ���
	���2:  clock() ���

	C ���� ���α׷� ���� ���� ��Ű��
		_sleep() ���
*/

void main() {
	
	//time() �Լ�
	{
		time_t start, end; // �̰� ����ü��  time.h �� �ִ�. 
		// ���⼭ start�� end�� ���� �̸� �̴�. 
		// �ð��� ��� �뵵�� ����Ѵ�. sec(��) ����
		printf("time() ���� ���� \n");
		start = time(NULL); // ����ð� ���� , ���� �ð� ���
		// time_t ����ü �ȿ� �ִ� time�̶�� �Լ� ����ѰŴ� ���� ���� ���� ����?
		for (int i = 0; i < 5; i++) {
			printf("i = %d\n", i);
			_sleep(1000); // �̰� 1��
		}
		end = time(NULL); // for���� ���� �ð� ���� , ����ð� ���
		
		double result = (double)(end - start); // ����ð�
		printf("(time)for�� ��� �ð� %f sec", result); // �ʴ����� ����� ����.
		// time_t �� �� �����̱� ������ �Ҽ��� �κ��� ����.(0���� ����)
	}

	// clock() ���
	{
		clock_t start, end;
		printf("\nclock() ���� ���� \n");
		start = clock(); // ����ð� ���� , ���� �ð� ���
		// clock_t ����ü �ȿ� �ִ� clock�̶�� �Լ� ����ѰŴ� ���� ���� ���� ����?
		for (int i = 0; i < 5; i++) {
			printf("i = %d\n", i);
			_sleep(1100); 
		}
		end = clock(); // for���� ���� �ð� ���� , ����ð� ���

		long result = (long)(end - start); // ����ð�
		printf("(clock)for�� ��� �ð� %ld ms", end - start); // ms������ ����� ����.
	}


}