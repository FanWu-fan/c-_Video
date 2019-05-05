#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)....." << endl;
		this->a = a;

		print();//这个print是在 Child的 vptr指针尚未建立时的输出，采用的是 Parent的。
	}
	virtual void print()
	{
		cout << "Parent::print() " << a << endl;
	}

private:
	int a;
};

//1. 不要在构造函数中调用虚函数
class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		print();//在执行完父类的构造函数以后，vptr指针就建立了，此时执行的是 子类的print
		cout << "Child(int a, int b)....." << endl;
		this->b = b;
	}
	//重写父类的虚函数
	virtual void print()
	{
		cout << "Child::print() " << b << endl;
	}
private:
	int b;
};



int main()
{
	Parent *p = new Child(10, 20);
	p->print();
	delete p；
}


