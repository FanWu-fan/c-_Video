#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

//模板就是对数据类型参数化
//此时编译器不知道T是什么类型，告诉编译器T是一个泛化的类型
//template <typename T>

template <class T>//和 template <typename T>是等价的
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>//和 template <typename T>是等价的
void print(T &a, T &b)
{
	cout << a << "," << b << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	//在调用模板函数的时候，告诉编译器T泛化的类型具体到底是什么类型
	print<int>(a, b);
	mySwap<int>(a, b);
	print<int>(a, b);

	char x = 'x';
	char y = 'y';

	print<char>(x, y);
	mySwap<char>(x, y);
	print<char>(x, y);

	string f = "hahaha";
	string g = "lalallal";

	print<string>(f, g);
	mySwap<string>(f, g);
	print<string>(f, g);
}
