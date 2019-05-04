#include "pch.h"
#include <iostream>
using namespace std;
/*
子类对象可以当作父类对象使用
子类对象可以直接赋值给父类对象
子类对象可以直接初始化父类对象
父类指针可以直接指向子类对象
父类引用可以直接引用子类对象
*/

class Parent
{
public:
	void printP()
	{
		cout << "Parent::printP" << endl;
	}
	Parent(int a)
	{
		this->a = a;
		cout << "Parent::Parent(int a)" << endl;

	}
	~Parent()
	{
		cout << "~Parent()" << endl;
	}

private:
	int a;
};

class Child :public Parent
{
public:
	//子类继承于父类，父类中的成员变量应该用 父类的构造函数来初始化，使用初始化构造列表
	Child(int a,int b):Parent(a)
	{
		this->b = b;
		cout << "Child(int a,int b):Parent(a)" << endl;

	}
	~Child()
	{
		cout << "~Child()" << endl;
	}

	void printC()
	{
		Parent::printP();
		cout << "Child::printc()" << endl;
	}
private:
	int b;
};

void test1()
{
	Child C(10, 20);
	C.printC();
}



int main()
{
	//Child c;
	//c.printP();//子类对象可以当作父类对象使用

	//Parent p = c;//由于子类拥有全部父类的内存空间，子类能够保证父类初始化完整
	////Child c2 = p;//父类不能完整的初始化 子类，子类的内存空间包含了 父类

	////父类指针可以直接指向子类对象。
	//Parent *pp = &c;
	//pp->printP();
	////Child *cc = &p;子类对象不能直接指向父类

    std::cout << "Hello World!\n"; 
	test1();

}


