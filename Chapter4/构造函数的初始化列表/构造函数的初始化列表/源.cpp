#include<iostream>
using namespace std;

class A
{
public:
	A(int a);//现实提供一个带参数的构造函数
	~A();
	void printA();

private:
	int m_a;
};

A::A(int a)
{
	this->m_a = a;
}

A::~A()
{
	cout << "a= " << m_a << "被析构了" << endl;
}

void A::printA()
{
	cout << "a= " << this->m_a << endl;
}

class B
{
public:
	B(int b):a1(10),a2(100)//在初始化B的时候，通过初始化列表给内部对象a1，a2进行了初始化
	{//类内部的对象初始化的顺序和对象定义的顺序一样，跟初始化列表中的顺序无关
	//析构的顺序和对象定义的顺序相反
		m_b = b;
	}

	B(int aa1, int aa2, int b) : a1(aa1), a2(aa2), m_b(b)//通过初始化列表不仅能够初始化成员对象，还可以初始化成员变量
	{

	}

	void printB()
	{
		cout << "b= " << m_b << endl;
		a1.printA();
		a2.printA();
	}

	~B()
	{
		cout << "B= " <<m_b<<"调用了析构函数"<< endl;
	}

private:
	int m_b;
	A a1;
	A a2;
}; 

class ABC
{
public:
	ABC(int a, int b, int c, int d ) : m_a(a), m_b(b), m_c(c), m_m(d)//常量成员只能通过初始化列表进行初始化，不能重新赋值
	{
		//this->m_m = d;
	}
private:
	int m_a;
	int m_b;
	int m_c;
	const int m_m;//常量
};

class ABCD
{
public:
	ABCD(int a, int b, int c, int d) :a4(a, b, c), m_a(d) {}

private:
	ABC a4;
	int m_a;
};


class ABCD
{
public:
private:

};


void test1()
{
	A a(10);
}

void test2()
{
	B b(1);
	b.printB();

	B b2(10);
	b2.printB();
}

int main()
{	
	//test1();
	test2();
	system("pause");
}