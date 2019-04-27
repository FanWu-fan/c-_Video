# Chapter5 继承和派生

## 1.0 this指针
```C++
#include "pch.h"
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int i)
	{
		this->mI = i;
	}
	int Change() const//在成员函数后面加const修饰的是隐藏的this指针，让this成为（const Test * const this）
	{
		//this++;this是常指针不能修改本身，(Test *const this)
		//this->mI = 0;

	}
private:
	int mI;
};
int main()
{
    
}

```

## 1.1 全局函数和成员函数
```C++
	//返回本身，实现连加,返回自己的别名
	Test   TestAdd04(Test &another)//如果返回的不是引用，那么在实现连加时，后续this都是一个临时变量，会被析构
	{
		this->a += another.a;
		this->b += another.b;

		//返回自己
		return *this;
	}//匿名的别名= *this ， 如果不是返回引用，那么在返回 *this会拷给给一个不同的地址，后续this不再代表 t1
```

## 1.2 数组类的封装
```C++
#include "pch.h"
#include <iostream>
using namespace std;


class Myarray
{
public:
	Myarray()
	{
		this->space = NULL;
		this->length = 0;
	}

	Myarray(int len)//开辟长度为 len的空间
	{
		if (len <= 0)
		{
			this->length = 0;
			return;
		}
		else
		{
			this->length = len;
			this->space = new int[this->length];//在堆上开辟了 长度为length的连续int 空间
			cout << "数组的构造函数被调用了" << endl;
		}
	}

	Myarray(const Myarray &another)
	{
		if (another.length >= 0)
		{
			this->length = another.length;
			this->space = new int[this->length];
			for (int i = 0; i < this->length; i++)
			{
				this->space[i] = another.space[i];
			}
		}
	}

	~Myarray()
	{
		cout << "执行析构函数" << endl;
		if (this->space)
		{
			delete[] this->space;
			this->length = 0;
			this->space = NULL;
		}

	}
	int Myarraygetlen()
	{
		return this->length;
	}

	void setData(int index, int value)
	{
		if (this->space)
		this->space[index] = value;
	}

	void printf()
	{
		for (int i = 0; i < this->length; i++)
			cout << this->space[i] << " ," << endl;
	}

private:
	int *space; //space在堆上开辟数组空间的首元素地址
	int length;

};

int main()
{
	Myarray array(10);//调用有参构造函数

	for (int i = 0; i < array.Myarraygetlen(); i++)
	{
		array.setData(i, i + 10);
	}

	array.printf(); 

	cout << "---一下是拷贝构造函数的测试----" << endl;
	Myarray array2 = array;
	array2.printf();
}
```

## 1.3 友元函数

>friend double PointDistance2(Point &p1, Point &p2);//友元函数，可以访问 私有变量
友元类：friend class B;

```C++
#include "pch.h"
#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void printP()
	{
		cout << "x= " << x << " y= " << y << endl;
	}
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}

	//1. 声明一个全局函数友元函数，可以访问 私有变量
	friend double PointDistance2(Point &p1, Point &p2);
	

private:
	//friend double PointDistance2(Point &p1, Point &p2);//友元函数，可以访问 私有变量写 public和 private都可以

	int x;
	int y;
};

//1.通过全局方式写一个 两点之间的距离
double PointDistance(Point &p1, Point &p2)
{
	int ddx = p1.getx() - p2.getx();
	int ddy = p1.gety() - p2.gety();
	return sqrt(ddx*ddx + ddy * ddy);
}

//2.通过友元来写，友元以后，可以访问私有变量
double PointDistance2(Point &p1, Point &p2)
{
	int ddx = p1.x- p2.x;
	int ddy = p1.y - p2.y;
	return sqrt(ddx*ddx + ddy * ddy);
}


int main()
{
	Point p1(10, 20);
	Point p2(20,10);
	cout << "Distance: " << PointDistance(p1, p2) << endl;
	cout << "Distance2: " << PointDistance2(p1, p2) << endl;



}
```
## 1.4 操作符重载
操着符重载支持两种，分别是 **成员函数重载** 和 **全局调用的方式**。
* 不允许用户自定义新的运算符，只允许重载已有的运算操作符
```c++
// 操作符重载.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void printf()
	{
		cout << "(" << a << "+" << b << "i" << ")" << endl;
	}
	friend Complex addComplex(Complex &c1, Complex &c2);
	friend Complex operator+(Complex &c1, Complex &c2);

	Complex operator-(Complex &another)
	{
		Complex newC = Complex(this->a - another.a, this->b - another.b);
		return newC;
	}


private:
	int a;//实数部分
	int b;//虚数部分
};

Complex addComplex(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b + c2.b);
	return c3;
}

//操作符重载
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c3(c1.a + c2.a, c1.b + c2.b);
	return c3;
}



int main()
{
	Complex c1(10, 20);
	Complex c2(1, 2);

	c1.printf();
	c2.printf();

	Complex c3 = addComplex(c1, c2);
	c3.printf();

	//Complex c4 = operator+(c1, c2);
	Complex c4 = c1 + c2;//显示的调用了 “+” 号的 重载,支持全局调用的方式
	c4.printf();

	//Complex c5 = c1.operator-(c2);////显示的调用了 “-” 号的 重载 ,支持 成员函数的调用方式
	Complex c5 = c2 - c1;
	c5.printf();
}
```
## 1.5 输入输出双目运算符 重载
```C++
//friend void operator<<(ostream &os, Complex &C);
	friend ostream & operator<<(ostream &os, Complex &C);
	friend istream & operator>>(istream & is, Complex &C);

//operator<<(cout,c)
//void operator<<(ostream &os, Complex &C)
//{
//	os<< "(" << C.a << "+" << C.b << "i" << ")" << endl;
//}

ostream & operator<<(ostream &os, Complex &C)//这个不能写在 成员函数里面
{
	os << "(" << C.a << "+" << C.b << "i" << ")" << endl;
	return os;
}

istream & operator>>(istream & is, Complex &C)
{
	cout << "a: ";
	is >> C.a;
	cout << "b: " ;
	is >> C.b;
	return is;
}
	cout << "---------------" << endl;
	//operator<<(cout, c5);
	cout << c5;
	cout << c5 << c3 << "haha" << endl;

	Complex c6;
	//operator>>(cin, c6);
	cin >> c6;
	cout << c6;
```

## 1.6 双目运算符重载
* 在C++中可以使用 ++++a;不能使用 a++++;即 a++ 返回的是常量，不可再次修改
```C++
	Complex & operator +=(Complex &another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

	Complex & operator++()//成员函数传入参数为空,前加加重载
	{
		++this->a ;
		++this->b ;
		return *this;
	}

	const Complex operator++(int)//后加加，即放入一个 占位操作符，亚元,先返回后加加
	{
		Complex temp(this->a, this->b);
		a++;
		b++;
		return temp;
	}


	c1 += c2;
	c1 += c2;
	c1.operator+=(c2);
	cout << c1;

	++c1;
	cout << c1;

	c1++;
	cout << c1;
```

## 1.7 等号操作符
