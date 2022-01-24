#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h> 
#include<time.h>
typedef struct Student {
	int age;
	char gender;
	char name[30];

}stu;
// typedef 로 정의된 타입명 으로 간단히 사용

char* fmt1 = "이름 : %s , 성별: %c, 나이 : %d\n";

// 구조체를 매개변수 받는 함수 작성시 가급적 포인터로 받자.
void printStudent(stu* p) {
	printf(fmt1, p->name, p->gender, (*p).age);
}

void main() {
	{
		// 구조체 (struct)
		// 여러 데이터 들을 모아 정의한 사용자 정의 데이터형

		// 멤버연산자 '.' 을 사용하여 각 멤버변수 접근
		stu stu1;
		stu1.age = 24;
		stu1.gender = 'M';
		strcpy(stu1.name, "양성훈");

		printf(fmt1, stu1.name, stu1.gender, stu1.age);
	}

	{
		stu stu2 = { 100,'N',"둘리" };
		printf(fmt1, stu2.name, stu2.gender, stu2.age);

		stu* p = &stu2;
		printf(fmt1, p->name, p->gender, (*p).age); // 이거 두개 똑같은거 알지?
		// 구조체포인터 멤버연산자 접근
		// 그리고 *p할때 괄호 까먹으면 안됨(*p) 왜냐면 멤버연산자가 먼저 인식되기 때문.

		printStudent(p);
	}

}