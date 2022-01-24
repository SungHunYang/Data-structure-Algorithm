#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h> 
void fnPlus(int a, int b) {
	printf("덧셈 : %d + %d = %d\n", a, b, a + b);
}
void fnMinus(int a, int b)
{
	printf("빼기: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("곱셈: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("나눗셈: %d / %d = %d\n", a, b, a / b);
}
void doAction(int a, int b, void(*fnOp)(int, int)) {
	fnOp(a, b); // 함수를 매개변수로 전해주는 법
}

typedef void fnAction(int, int); // 함수포인터 타입 정의
void doAction2(int a, int b, fnAction* fnOp) {
	fnOp(a, b); // 이게 더 일반적인 함수 매개변수 사용법
	// 구조체 함수를 만들어서 하는 일반적인 방법
}
void main() {

	/* 
		함수 포인터
		'함수이름' 이 곧 '포인터'로 된다.
	*/

	{
		fnPlus(10, 20);
		printf("fnplus -> %p\n", fnPlus); // --> 함수 이름이 포인터인지 보려고

		// 함수포인터는 '참조' 가 곧 '호출 동작'
		// 참조 연산자 * 사용하여 호출
		(*fnPlus)(30, 40);

		// 함수 포인터 타입 변수 선언 가능
		// int *p; <-- int 에 대한 포인터
		// void 리턴하고 (int,int) 매개변수 받는 함수에 대한 함수 포인터
		void(*fnOp)(int, int); //<- fnOp라는 '함수포인터 변수 선언'

		//포인터 변수 <- 대입가능!
		fnOp = fnPlus; // void 리턴하고 (int,int) 매개변수 받는 함수 라는 타입이 똑같아 대입가능
		// 즉, fnPlus = void(*fnOp)(int, int); 이렇게 생긴거

		// 이제 fnOp는 함수처럼 사용가능
		// 참조연산자
		(*fnOp)(70, 100); // 이거 이제 사용 가능
		fnOp(70, 100);
	}

	printf("\n");
	{
		// 함수포인터의 이점.
		// '동작'을 나중에 연결 가능 (late-binding)

		int op;
		printf("동작번호를 입력하세요(0:+ 1:- 2:* 3:/): ");
		scanf("%d", &op);

		int a = 30, b = 10;
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			if (op == 0)
				fnPlus(a, b); // <-- 이 라인의 실행코드는 fnPlus 를 호출
			else if (op == 1)
				fnMinus(a, b);
			else if (op == 2)
				fnMul(a, b);
			else if (op == 3)
				fnDiv(a, b);
		}
		// ↑ 이미 컴파일할때 코드상에 명시된 '특정'함수가
		// 실행되도록 바인딩 된다.  --> Early Binding 이라 함
		// 매 순환문마다 조건문을 통해 고정된 함수 호출을 호출해야 하니, 조건분기문 로드가 큼

		// 반면 함수포인터 선언하면
		void(*fnAction)(int, int);

		// 함수포인터의 배열 (함수들만 모아놓은 배열)
		void(*fnOpArr[4])(int, int) = {fnPlus,fnMinus,fnMul,fnDiv};
		// fnOpArr[0] => fnPlus
		// fnOpArr[1] => fnMinus ...


		printf("\n");
		fnAction = fnOpArr[op]; // -> 이런 식이면 아까 for문 처럼 
		// if문을 위에서 부터 하나씩 내려오면서 비교할 필요가 없어지고
		// 바로바로 나올수 있다.
		for (i = 0; i < 5; i++) {
			fnAction(a, b);
		// 걍 fnAction 을 수행.. 그런데 컴파일 시점에선 무엇을 실행한진 모른다 (즉 바인딩이 되어 있지 않다)
		// 실행 해야 나중에 동작이 결정된다.   late-binding
			// 바인딩이라는건 정해졌다라는 뜻! , 
			//즉 late-binding은 나중에 컴파일 하면 op에 뭐가 들어와서 fnAction이 정해진다는 거다.
	    // 장점: 조건문에 의한 로드가 적다.
	    // 성능향상!!

		// 함수 포인터도 포인터다!  
		// 매개변수로 넘겨줄수도, 리턴값으로 받을수도
		// 배열 원소가 될수도 있다!!
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