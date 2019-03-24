#include<iostream>
using namespace std;


void  test1() {
	const int value = 3;//常量
	int v = 5;
	int s = 10;
	const int *p = &v;//指向常量的指针
	//*p = 5;//不能修改 *p,但是可以修改 p
	p = &s;


	v = 6;//可以修改v

	int * const op = &v;
	*op = 10;
	//op = &s;//op本身不能修改，但是 *op可以修改
}

struct Student
{
	int id;
	char name[64];
};

void change_stu(Student *s) {
	s->id = 10;//如果是指针就用 ->,如果是 对象，就用 .
}

void change_stu2(const Student *s) {
	//s->id = 20;//此时s所指向的区域是一个常量，即 *s 或 s->id 不能被修改
	Student s2;
	s = &s2;

	Student *s3;
	s = s3;
}

void change_stu3(Student * const s) {
	s->id = 10;
	Student s2;
	//s = &s2;//此时s不能被修改

	Student *s3;
	//s = s3;//此时s不能被修改
}
void change_stu4(const Student *const s) {
	//s->id = 10;
	//此时s所指向的区域是一个常量，即 *s 或 s->id 不能被修改

	Student s2;
	//s = &s2;//此时s不能被修改
}

enum MyEnum
{
	SPR,
	SUM,
	AUT
};

void test2() {
	MyEnum s = SPR;//为了增加枚举类型的可读性。不能用值来赋值。

}



int main() {

	//test1();

	system("pause");
}