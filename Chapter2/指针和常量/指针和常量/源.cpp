#include<iostream>
using namespace std;


void  test1() {
	const int value = 3;//����
	int v = 5;
	int s = 10;
	const int *p = &v;//ָ������ָ��
	//*p = 5;//�����޸� *p,���ǿ����޸� p
	p = &s;


	v = 6;//�����޸�v

	int * const op = &v;
	*op = 10;
	//op = &s;//op�������޸ģ����� *op�����޸�
}

struct Student
{
	int id;
	char name[64];
};

void change_stu(Student *s) {
	s->id = 10;//�����ָ����� ->,����� ���󣬾��� .
}

void change_stu2(const Student *s) {
	//s->id = 20;//��ʱs��ָ���������һ���������� *s �� s->id ���ܱ��޸�
	Student s2;
	s = &s2;

	Student *s3;
	s = s3;
}

void change_stu3(Student * const s) {
	s->id = 10;
	Student s2;
	//s = &s2;//��ʱs���ܱ��޸�

	Student *s3;
	//s = s3;//��ʱs���ܱ��޸�
}
void change_stu4(const Student *const s) {
	//s->id = 10;
	//��ʱs��ָ���������һ���������� *s �� s->id ���ܱ��޸�

	Student s2;
	//s = &s2;//��ʱs���ܱ��޸�
}

enum MyEnum
{
	SPR,
	SUM,
	AUT
};

void test2() {
	MyEnum s = SPR;//Ϊ������ö�����͵Ŀɶ��ԡ�������ֵ����ֵ��

}



int main() {

	//test1();

	system("pause");
}