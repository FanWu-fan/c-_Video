// 虚析构函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()....." << endl;
		this->p = new char[64];
		strcpy_s(p,20,"A string");
	}
	virtual ~A()
	{
		cout << "~A()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()
	{
		cout << "A :" << p << endl;
	}
private:
	char *p;
};

class B :public A
{
public:
	B()
	{
		cout << "B()...." << endl;
		this->p = new char[64];
		strcpy_s(p, 20, "B string");
	}

	virtual ~B()
	{
		cout << "~B()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()
	{
		cout << "B :" << p << endl;
	}
private:
	char *p;
};

class C :public B
{
public:
	C()
	{
		cout << "C()...." << endl;
		this->p = new char[64];
		strcpy_s(p, 20, "C string");
	}
	virtual ~C()
	{
		cout << "~C()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()//多态重写
	{
		cout << "C :" << p << endl;
	}
private:
	char *p;
};

void func(A *p)
{
	p->print();
	delete p;//这里会将p只看作父类指针来释放，而不是释放3次。
	//如果不加虚析构，只会析构父函数一次，加了之后，会优先调用 C的析构函数，来依次析构。
}



int main()
{

	C *cp = new C;
	cp->print();
	delete cp;


	cout << "------------------" << endl;

	C *cp1 = new C;
	func(cp1);//使用多态
 
}
