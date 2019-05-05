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
	virtual void print() //这个virtual是保证给一个成员函数定义为 虚函数，当子类去重写虚函数时，父类指针指向这个函数时，
		//会调用子类的函数。
	{
		cout << "Parent::print():a= " << a << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()//重定义父类函数,这里加virtual是为了可读性，将 重定义变为 重写 父类的 虚函数
	{
		cout << "Child::print():b= " << b << endl;
	}
private:
	int b;
};

class Child2 :public Parent
{
public:
	Child2(int a):Parent(a)
	{

	}
	virtual void print()
	{
		cout << "This is a Child 2" << endl;
	}
private:

};


void myPrint(Parent *p)//让父类指针指向子类的对象的时候，就会调用 子类的 重写函数
{
	p->print();//在此时 print函数 发生了 多态现象
}

int main()
{
	Child c(10,20);
	c.print();//20

	Parent p(100);
	p.print();//100

	myPrint(&p);//调用的父类print 100
	myPrint(&c);//10 ，调用的是父类的，编译器会不管传递进来的是 父类还是子类
	//Parent * p =&c,

	Child2 c2(200);
	myPrint(&c2);

} 

