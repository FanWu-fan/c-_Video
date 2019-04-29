#include "pch.h"
#include <iostream>
using namespace std;

class A
{
public:
	void funcA()
	{

	}
};

//B has A
class B
{
public:
	void funcB()
	{
		a.funcA();
	}
	A a;
};

//C中的某一个成员函数， 将A类当一个形参传递竟来
//C use A
class C
{
public:
	void funcc(A  *a)
	{
		a->funcA();
	}
};

//D继承A D is A
class D:public A
{
public:
	void funcD()
	{
		A::funcA();//直接使用A类的方法
		funcA();
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

