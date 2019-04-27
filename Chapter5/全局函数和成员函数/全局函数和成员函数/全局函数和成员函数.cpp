#include "pch.h"
#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		this->a = 0;
		this->b = 0;
		cout << "调用了无参构造函数：" << "a=" << a << " b=" << b << endl;

	}
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "调用了有参构造函数：" << "a=" << a << " b=" << b << endl;

	}
	~Test()
	{
		cout << "调用了析构函数：" << "a=" << a << " b=" << b<<endl;
	}
	Test(Test const &t)
	{
		this->a = t.a;
		this->b = t.b;
		cout << "调用了拷贝构造函数：" << "a=" << a << " b=" << b << endl;

	}

	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}
	void prinT()
	{
		cout << "打印输出：" << "a=" << a << " b=" << b << endl;
	}

	//成员函数
	Test TestAdd01(Test &another)
	{
		Test temp(this->a + another.a, this->b + another.b);
		return temp;
	}

	//改变本身
	void TestAdd03(Test &another)
	{
		this->a += another.a;
		this->b += another.b;
	}

	//返回本身，实现连加,返回自己的别名
	Test   TestAdd04(Test &another)//如果返回的不是引用，那么在实现连加时，后续this都是一个临时变量，会被析构
	{
		this->a += another.a;
		this->b += another.b;

		//返回自己
		return *this;
	}//匿名的别名= *this ， 如果不是返回引用，那么在返回 *this会拷给给一个不同的地址，后续this不再代表 t1


private:
	int a;
	int b;
};

//提供一个方法来实现两个Test对象相加
//全局函数
Test Testadd(Test &t1, Test &t2)
{
	Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
	return temp;
}//在结束时，将temp先拷贝给一个匿名临时变量，析构temp



int main()
{
	Test t1(10, 20);
	Test t2(100, 200);
	////Test t3 = Testadd(t1, t2);//这个有对象接收，直接取匿名临时对象的别名，

	//Test t3;
	//t3= Testadd(t1, t2);//如果没有初始对象接收，那么将 匿名临时对象 析构，值拷贝到 t3中，不是 拷贝构造函数，因为一个函数只能使用 构造函数一次
	//t3.prinT();
	//-----------------------------------------------------------//

	//Test t4 = t1.TestAdd01(t2);

	//t1.TestAdd03(t2);
	//t1.prinT();

	t1.TestAdd04(t2).TestAdd04(t2).TestAdd04(t2);
	t1.prinT();
}


