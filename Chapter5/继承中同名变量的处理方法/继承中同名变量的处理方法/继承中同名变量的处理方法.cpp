#include "pch.h"
#include <iostream>

class base
{
public:
	int a, b;
};

class derived :public base
{
public:
	int b, c;

};

void f()
{
	derived d;
	d.a = 1;
	d.base::b = 2;
	d.b = 3;
	d.c = 4;
}


int main()
{
	std::cout << "Hello World!\n";
	f();
}