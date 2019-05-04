// 单继承.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

#if 0



class Base
{
public:
	int pub;
private:
	int pri;
protected:
	int pro;
};

class PUB :public Base
{
public:
	void func()
	{
		Base::pro = 10;
		Base::pub = 100;
		//pri=1000;不能继承私有属性
	}
};


class PRO :protected Base
{
public:
	void func1()
	{
		Base::pro = 10;
		Base::pub = 100;

	}
};
#endif // 0

class A
{
private:
	int a;
protected:
	int b;

public:
	int c;
	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}
	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

};

class B :public A
{
public:
	void print()
	{
		//cout << "a = " << a;//这个不能访问
		cout << "b=" << b << endl;//这个在外部不能直接访问 b
		cout << "c=" << c << endl;
	}
};

class C :protected A
{
public:
	void print()
	{
		//cout << "a = " << a;//这个不能访问
		cout << "b=" << b << endl;//这个在外部不能直接访问 b
		cout << "c=" << c << endl;
	}
};

class D :private A
{
public:
	void print()
	{
		//cout << "a = " << a;//这个不能访问
		cout << "b=" << b << endl;//这个在外部不能直接访问 b
		cout << "c=" << c << endl;
	}
};

int main()
{

	B	bb;
	bb.print();
	bb.c;

	C  cc;
	//cc.c; c不可访问
	cc.print();

	D dd;
	//dd.c;c不可访问
	dd.print();



#if 0
	Base b;
	b.pub = 10;
	//b.pro =100;
	//b.pri =1000;

	PUB p;
	p.pub = 0;
    std::cout << "Hello World!\n"; 

	PRO pro;
#endif // 0


}


