#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

typedef void fnAction(int); // ������ �Լ� Ÿ��

void chkTime(char* szTitle, fnAction action, int dataSize) {
	clock_t start, end;
	long result;

	printf("%s : size[%d] �������� \n", szTitle, dataSize);
	start = clock();

	action(dataSize);

	end = clock();
	result = end - start;
	printf("%s : size[%d] ����ð� %ld ms\n", szTitle, dataSize, result);
}	

void func1(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) { sum++; }
}

void func2(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) { 
		for (int j = 0; j < size; j++) {
			sum++;
		}
	}
}
void func3(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				sum++;
			}
		}
	}
}

void main() {
	int size;
	{
		size = 100000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size*2);
		chkTime("O(n)", func1, size*4);

		// �Էµ����Ͱ� n�� �����Ҷ�, ����ð��� n�� ����
	}
	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size*2);
		chkTime("O(n^2)", func2, size*4);

		// �Էµ����Ͱ� n�� �����Ҷ�, ����ð��� n^2�� ����
	}
	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2);
		chkTime("O(n^3)", func3, size * 4);

		// �Էµ����Ͱ� n�� �����Ҷ�, ����ð��� n^3�� ����

	}

}