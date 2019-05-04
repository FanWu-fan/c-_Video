// 派生类中的static关键字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class A
{
public:
	static int s;
private:
};

int A::s = 0;//静态成员变量要在类的外部初始化

class B :public A
{
public:
private:

};

class C :protected B
{
public:

};

int main()
{
	B b;
	cout << b.s << endl;//可以在B中访问s
	B::s = 100;
	cout << b.s << endl;
	cout << A::s << endl;
	//C::s = 300;不可访问

    std::cout << "Hello World!\n"; 
}

