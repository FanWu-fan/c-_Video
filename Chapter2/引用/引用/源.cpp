#include<iostream>
using namespace std;

//����ֲ�������a�ĵ�ַ��ʵ�β�ͬ�����ܸı�ʵ��
void pA(int a) {
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
}


// �����ô���Ĳ�����ָ��ͬһ���ڴ���ַ�����Խ�ʡ�ڴ棬ͬʱ�ı�ʵ�ε���ֵ
void pB(int &b2) {
	cout << "b2: " << b2 << endl;
	cout << "&b2: " << &b2 << endl;
	b2 = 50;
}


void t1() {
	int a = 10;
	int a2 = 20;

	int &b = a;
	//int &c;//���ñ����ʼ��,������Ϊ������ʱ����Բ��ó�ʼ��

	int &bb = b;//������õı���
}

struct Teacher
{
	int id;
	char name[64];
	int num = 10;
};

//�ֲ������ᷢ��ֵ����,����ı�ԭ����ֵ
void pT(Teacher t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;//���ﲻ���޸� t1��ֵ��
}

//�������� ���� �����޸Ĵ�������ֵ
void pT2(Teacher &t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;
}
//��������ָ��ı� ��������ֵ
void pT3(Teacher *t) {

	cout << "id = " << t->id << endl;
	cout << "name = " << t->name << endl;
	cout << "num = " << t->num << endl;
	t->id = 400;//�������� ���� �����޸Ĵ�������ֵ
}

void t2() {
	Teacher t1 = { 3,"wufan",20 };
	pT(t1);
	cout << "id = " << t1.id << endl;//3

	pT2(t1);
	cout << "id = " << t1.id << endl;//200

	pT3(&t1);
	cout << "id = " << t1.id << endl;//400
}




int main() {
	//t1();
	t2();
	system("pause");
}