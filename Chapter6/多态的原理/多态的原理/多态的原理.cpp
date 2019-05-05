#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	virtual void func(int a, int b)
	{
		cout << "Parent:func(int a, int b)..." << endl;
	}

	void func(int a, int b, int c)
	{
		cout << "Parent:func(int a, int b, int c)..." << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	void func(int a, int b)
	{
		cout << "Child:func(int a, int b)..." << endl;
	}
	void func(int a, int b, int c)
	{
		cout << "Child:func(int a, int b, int c)..." << endl;
	}
private:
	int b;
};




int main()
{
	Parent *p = new Child;//父类指针指向了 子类对象
	p->func(10, 20);//"Child:func(int a, int b)...",此时发生了多态，调用了Child，动态联编
	p->func(10, 20, 30);//Parent:func(int a, int b, int c)...,此时只有重载，没有多态，静态联编
	
	Parent p1;
	Child c1;
	cout << "szieof Parent " << sizeof(p1) << endl;//此表中由 vptr指针，占用了4个字节，一共8字节
	cout << "szieof Child " << sizeof(c1) << endl;//12字节

} 

