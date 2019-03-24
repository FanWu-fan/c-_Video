#include<iostream>
using namespace std;

//这个局部变量的a的地址和实参不同，不能改变实参
void pA(int a) {
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
}


// 用引用传入的参数，指向同一个内存块地址，可以节省内存，同时改变实参的数值
void pB(int &b2) {
	cout << "b2: " << b2 << endl;
	cout << "&b2: " << &b2 << endl;
	b2 = 50;
}


void t1() {
	int a = 10;
	int a2 = 20;

	int &b = a;
	//int &c;//引用必须初始化,但是作为参数的时候可以不用初始化

	int &bb = b;//多次引用的别名
}

struct Teacher
{
	int id;
	char name[64];
	int num = 10;
};

//局部变量会发生值拷贝,不会改变原来的值
void pT(Teacher t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;//这里不能修改 t1的值。
}

//这里利用 引用 可以修改传进来的值
void pT2(Teacher &t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;
}
//这里利用指针改变 传进来的值
void pT3(Teacher *t) {

	cout << "id = " << t->id << endl;
	cout << "name = " << t->name << endl;
	cout << "num = " << t->num << endl;
	t->id = 400;//这里利用 引用 可以修改传进来的值
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