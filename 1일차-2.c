#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include<time.h> 
/*
*	malloc(), free()
*   calloc(), realloc()
*
*   memcpy(), memset()
*/

void main() {

	{
		// ���� �޸� �Ҵ� : dynamic memory allocation
		int len = 100;
		int* a= (int*)malloc(sizeof(int) * len); // malloc(byte_size) �޸� �� �Ҵ�. �޸� ���� �ּ�(ù��° ����Ʈ)�� ����
		printf("a[0] : %d\n", a[0]);
		
		// �޸𸮸� �Ҵ� ������ �ʱ�ȭ �����ִ� �͵� ����.
		// �̰� a��� �迭�� 0���� �ϴ� ���� �ִ°Ŵ�.
		memset(a, 0, sizeof(int) * len);  //--> a ���� ���� sizeof(int) * len ��ŭ�� 0���� �ʱ�ȭ
		printf("a[0] : %d\n", a[0]);

		// ���� �޸𸮴� ��� �Ŀ� �ݵ�� free �Ҵ� ���� �ؾ���
		free(a);
		printf("a[0] : %d\n", a[0]);
	}
	// ������ �������� �޸� �Ҵ� ���� ���� ������
	// �޸� ����(memory leak) �߻�

	//realloc()
	printf("\n");
	{
		//re-allocation()
		// ������ �޸� �Ҵ�� �͵��� ������ �����Ҵ� �޾Ƽ� ���뺹��
		// ���� �޸𸮿� ���� �迭 Ȯ�� ����.

		int* arr = (int*)malloc(sizeof(int) * 3);
		arr[0] = 10; arr[1] = 20; arr[2] = 30;
		printf("%d%d%d\n", arr[0], arr[1], arr[2]);

		// �����޸� ���Ҵ�(Ȯ��, ���)
		// ������ arr�� �Ҵ�� ������ ���� (���� free() ��Ű�� �ʾƵ�)
		arr = (int*)realloc(arr, sizeof(int) * 5);
		arr[3] = 40;
		printf("%d%d%d\n", arr[0], arr[1], arr[2]);


	}
	printf("\n �޸� �������ϸ� ���� - �ƹ�Ű�� ������ ����\n");
	_getch();
	{
		int len = 200;
		int* arr;
		for (int i = 0; i < 10; i++) {
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(5000);
			free(arr);
			_sleep(5000);
		}  //--> ����� -> ���� �������Ϸ� -> �޸𸮻�뷮 üũ�� �� ������
		free(arr);

	}

}