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
// typedef �� ���ǵ� Ÿ�Ը� ���� ������ ���

char* fmt1 = "�̸� : %s , ����: %c, ���� : %d\n";

// ����ü�� �Ű����� �޴� �Լ� �ۼ��� ������ �����ͷ� ����.
void printStudent(stu* p) {
	printf(fmt1, p->name, p->gender, (*p).age);
}

void main() {
	{
		// ����ü (struct)
		// ���� ������ ���� ��� ������ ����� ���� ��������

		// ��������� '.' �� ����Ͽ� �� ������� ����
		stu stu1;
		stu1.age = 24;
		stu1.gender = 'M';
		strcpy(stu1.name, "�缺��");

		printf(fmt1, stu1.name, stu1.gender, stu1.age);
	}

	{
		stu stu2 = { 100,'N',"�Ѹ�" };
		printf(fmt1, stu2.name, stu2.gender, stu2.age);

		stu* p = &stu2;
		printf(fmt1, p->name, p->gender, (*p).age); // �̰� �ΰ� �Ȱ����� ����?
		// ����ü������ ��������� ����
		// �׸��� *p�Ҷ� ��ȣ ������� �ȵ�(*p) �ֳĸ� ��������ڰ� ���� �νĵǱ� ����.

		printStudent(p);
	}

}