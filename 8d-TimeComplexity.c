#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

typedef void fnAction(int); // 측정할 함수 타입

void chkTime(char* szTitle, fnAction action, int dataSize) {
	clock_t start, end;
	long result;

	printf("%s : size[%d] 츨정시작 \n", szTitle, dataSize);
	start = clock();

	action(dataSize);

	end = clock();
	result = end - start;
	printf("%s : size[%d] 경과시간 %ld ms\n", szTitle, dataSize, result);
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

		// 입력데이터가 n배 증가할때, 수행시간도 n배 증가
	}
	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size*2);
		chkTime("O(n^2)", func2, size*4);

		// 입력데이터가 n배 증가할때, 수행시간도 n^2배 증가
	}
	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2);
		chkTime("O(n^3)", func3, size * 4);

		// 입력데이터가 n배 증가할때, 수행시간도 n^3배 증가

	}

}