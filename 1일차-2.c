#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> // _getch, putch .. MS 기반 C비표준 함수
#include<time.h> 
/*
*	malloc(), free()
*   calloc(), realloc()
*
*   memcpy(), memset()
*/

void main() {

	{
		// 동적 메모리 할당 : dynamic memory allocation
		int len = 100;
		int* a= (int*)malloc(sizeof(int) * len); // malloc(byte_size) 메모리 블럭 할당. 메모리 블럭의 주소(첫번째 바이트)를 리턴
		printf("a[0] : %d\n", a[0]);
		
		// 메모리를 할당 했으면 초기화 시켜주는 것도 좋다.
		// 이게 a라는 배열에 0값을 싹다 집어 넣는거다.
		memset(a, 0, sizeof(int) * len);  //--> a 번지 부터 sizeof(int) * len 만큼을 0으로 초기화
		printf("a[0] : %d\n", a[0]);

		// 동적 메모리는 사용 후에 반드시 free 할당 해제 해야함
		free(a);
		printf("a[0] : %d\n", a[0]);
	}
	// 적절한 시점에서 메모리 할당 해제 하지 않으면
	// 메모리 누수(memory leak) 발생

	//realloc()
	printf("\n");
	{
		//re-allocation()
		// 기존에 메모리 할당된 것들을 새로이 공간할당 받아서 내용복사
		// 동적 메모리에 사용된 배열 확장등에 좋다.

		int* arr = (int*)malloc(sizeof(int) * 3);
		arr[0] = 10; arr[1] = 20; arr[2] = 30;
		printf("%d%d%d\n", arr[0], arr[1], arr[2]);

		// 동적메모리 재할당(확장, 축소)
		// 기존의 arr에 할당된 공간을 해제 (따로 free() 시키지 않아도)
		arr = (int*)realloc(arr, sizeof(int) * 5);
		arr[3] = 40;
		printf("%d%d%d\n", arr[0], arr[1], arr[2]);


	}
	printf("\n 메모리 프로파일링 시작 - 아무키나 누르면 시작\n");
	_getch();
	{
		int len = 200;
		int* arr;
		for (int i = 0; i < 10; i++) {
			arr = (int*)malloc(sizeof(int) * len);
			_sleep(5000);
			free(arr);
			_sleep(5000);
		}  //--> 디버그 -> 성능 프로파일러 -> 메모리사용량 체크로 볼 수있음
		free(arr);

	}

}