// 单继承.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Base
{
public:
	int pub;
private:
	int pri;
protected:
	int pro;
};

class Drive :public Base
{
public:
	void func()
	{
		Base::pro = 10;
		Base::pub = 100;
		//pri=1000;不能继承私有属性
	}
};



int main()
{
	Base b;
	b.pub = 10;
	//b.pro =100;
	//b.pri =1000;
    std::cout << "Hello World!\n"; 
}


