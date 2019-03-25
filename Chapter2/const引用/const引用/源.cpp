#include<iostream>
using namespace std;

void t1() {
	const int a = 10;//const变量必须初始化
	//int &b = a;//这个不合法，如果可以，那么b将改变常量a的值。
	int const &b = a;//可以用const引用来 引用
}





int main() {

	const int x = 20;

	//int &p = 10;//引用无法对一个 字面量，字面量没有 内存地址。
	const int &p = 10;//会自动开辟一个临时变量 temp。temp =10，实际上 10已经消失了
	cout << "p: " << p << " ,&p " << &p << endl;



	system("pause");
}