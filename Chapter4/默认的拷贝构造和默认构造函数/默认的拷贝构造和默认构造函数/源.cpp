#include<iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int);
	~A();

private:
	int m_a;
};

A::A(int a)//如果普通的构造函数，提供了一个显示的构造,默认的无参构造函数将会 被隐藏
			//但是，默认的构造函数只会被 显示的构造函数 给 掩盖
{
	m_a = a;
}

A::~A()//只有提供一个显示的构造函数，才会将默认的 析构函数 覆盖
{
}



void main()
{
	//A  obj;//当你不提供任何构造函数的时候，系统会有一个默认的构造函数
	A obj2 = obj; // 调用了obj2的 默认的拷贝构造
	//A obj2(obj);

	system("pause");
}