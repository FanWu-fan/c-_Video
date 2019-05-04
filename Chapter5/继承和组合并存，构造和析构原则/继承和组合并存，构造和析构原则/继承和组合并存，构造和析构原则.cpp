// 继承和组合并存，构造和析构原则.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Object
{
public:
	Object(const char*s)
	{
		cout << "Object(const char*s)" << " " << s << endl;
	}
	~Object()
	{
		cout << "~Object()" << endl;
	}
	int as;
};

class Parent :public Object
{
public:
	Parent(const char *s):Object(s)
	{
		cout << "Parent(const char *s)" << endl;
	}
	~Parent()
	{
		cout << "~Parent()" << endl;
	}
};

class Child :public Parent
{
public:
	Child() :o2("o2"), o1("o1"), Parent("Parameter from Child")
	{
		cout << "Child()" << endl;
	}
	~Child()
	{
		cout << "~Child()" << endl;

	}
private:
	Object o1;//这里是组合
	Object o2;
};

void run()
{
	Child child;
}

int main()
{
	run();
    std::cout << "Hello World!\n"; 
}


