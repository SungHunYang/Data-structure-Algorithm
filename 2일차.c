#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>

/*
	C, C++ 에서 시작 측정하기
	방법1:  time() 사용
	방법2:  clock() 사용

	C 에서 프로그램 실행 지연 시키기
		_sleep() 사용
*/

void main() {
	
	//time() 함수
	{
		time_t start, end; // 이거 구조체임  time.h 에 있다. 
		// 여기서 start와 end는 변수 이름 이다. 
		// 시간을 담는 용도로 사용한다. sec(초) 단위
		printf("time() 측정 시작 \n");
		start = time(NULL); // 현재시간 리턴 , 시작 시간 기록
		// time_t 구조체 안에 있는 time이라는 함수 사용한거다 무슨 느낌 인지 알지?
		for (int i = 0; i < 5; i++) {
			printf("i = %d\n", i);
			_sleep(1000); // 이거 1초
		}
		end = time(NULL); // for문이 끝난 시간 리턴 , 종료시간 기록
		
		double result = (double)(end - start); // 경과시간
		printf("(time)for문 경과 시간 %f sec", result); // 초단위로 결과값 나옴.
		// time_t 는 초 단위이기 때문에 소수점 부분이 없다.(0으로 나옴)
	}

	// clock() 사용
	{
		clock_t start, end;
		printf("\nclock() 측정 시작 \n");
		start = clock(); // 현재시간 리턴 , 시작 시간 기록
		// clock_t 구조체 안에 있는 clock이라는 함수 사용한거다 무슨 느낌 인지 알지?
		for (int i = 0; i < 5; i++) {
			printf("i = %d\n", i);
			_sleep(1100); 
		}
		end = clock(); // for문이 끝난 시간 리턴 , 종료시간 기록

		long result = (long)(end - start); // 경과시간
		printf("(clock)for문 경과 시간 %ld ms", end - start); // ms단위로 결과값 나옴.
	}


}