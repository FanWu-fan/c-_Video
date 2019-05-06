# Chapter7 模板

```C++
#include "pch.h"
#include <iostream>
using namespace std;

void myswap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(int &a, int &b)
{
	cout << "a = " << a << "  b = " << b << endl;
}

//对char类型交换
void myswap(char &x, char &y)
{
	char temp = x;
	x = y;
	y = temp;
}
void print(char &x, char &y)
{
	cout << "x = " << x << "  y = " <<y << endl;
}

int main()
{
	int a = 10, b = 20;
	myswap(a, b);
	print(a, b);

	char x = 's',y = 'd';
	myswap(x, y);
	print(x, y);
}
```

```C++
#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

//模板就是对数据类型参数化
//此时编译器不知道T是什么类型，告诉编译器T是一个泛化的类型
//template <typename T>

template <class T>//和 template <typename T>是等价的
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>//和 template <typename T>是等价的
void print(T &a, T &b)
{
	cout << a << "," << b << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	//在调用模板函数的时候，告诉编译器T泛化的类型具体到底是什么类型
	print<int>(a, b);
	mySwap<int>(a, b);
	print<int>(a, b);

	char x = 'x';
	char y = 'y';

	print<char>(x, y);
	mySwap<char>(x, y);
	print<char>(x, y);

	string f = "hahaha";
	string g = "lalallal";

	print<string>(f, g);
	mySwap<string>(f, g);
	print<string>(f, g);
}

10,20
20,10
x,y
y,x
hahaha,lalallal
lalallal,hahaha
```

## 7.1 模板函数和普通函数的匹配规则
* 如果模板函数和普通函数都符合调用时，优先调用 **普通函数**
* 如果想显示调用模板函数，使用\<class T>
* 如果只有模板匹配，直接使用函数模板
* 编译器并不是把函数模板处理成能够处理任意类的函数
* 编译器从函数模板通过 **具体类型** 产生 **不同** 的函数
* 编译器会对函数模板进行 **二次编译**，在 **声明** 的地方对模板代码本身进行编译。在 **调用** 的地方对参数替换后的代码进行编译。

## 7.2 类模板的基本语法
```c++
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
}
```
