#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()  " << endl;
	}
	int a;
private:
};

class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{

	}
	virtual void print()
	{
		cout << "Child::print()  " << a << endl;
	}
private:
	int b;//这里添加以后，子类的内存比父类大，12>8，指针++会出错
};


int main()
{
	Parent p1(10);
	Child c1(10);
	cout << "sizeof Child" << sizeof(c1) << endl;//8个字节，VPTR这里未初始化，不存在
	cout << "sizeof Parent" << sizeof(p1) << endl;//8个字节，a占了4个，VPTR指针占了4个

	Child array[] = { Child(0),Child(1),Child(2) };
	//这个不是匿名对象，   array[0],array[1],array[2]

	Child *cp = &array[0];
	Parent *pp = &array[0];

	cout << "------------" << endl;
	cp->print();//Child
	pp->print();//Child 发生多态

	cout << "------------" << endl;
	cp++;//+12个
	pp++;//+8个
	cp->print();//Child
	pp->print();//Child 发生多态


	cout << "------------" << endl;

	int i = 0;
	for (i = 0, pp = &array[0]; i < 3; i++,pp++)
	{
		pp->print();
	}
}
