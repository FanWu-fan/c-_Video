#include "pch.h"
#include <iostream>
using namespace std;

template <class T>
class A
{
public:
	A(T a)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a = " << a << endl;
	}

private:
	T a;
};

//继承模板类,此时B类是一个 模板类
template <class T>
class B :public A<T>
{
public:
	B(T b, T a):A<T>(a)
	{
		this->b = b;
	}
	
private:
	T b;
};

//这个继承的是一个 普通的类
//已经指定了类型
class C :public A<int>
{
public:
	C(int a, int c) :A<int>(a)
	{
		this->c = c;
	}
private:
	int c;
};



template <class T>
void func(A<T> &a)
{
	a.printA();
}

int main()
{
	A<int> a(10);
	A<double> b(1.3213);

	a.printA();
	b.printA();

	func<int>(a);

	C c(10, 20);
	B<double> d(1.32, 4.32);
	d.printA();

}
