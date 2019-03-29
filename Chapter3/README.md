# Chapter3 C++对C语言的拓展
## 1.0 内联函数
* 内联函数声明inline必须和函数定义放在一起(只是仅在声明时使用是不够的)，否者编译器会直接胡月内联请求。
* C++编译器直接将函数体插在函数调用的地方，类似于宏展开，**没有普通函数调用时的额外开销(压栈，跳转，返回)**。
* 只有在函数体很小，而且被频繁调用时才起作用。以牺牲代码段空间为代价，提升程序的运行时间。
```C++
//inline是一个关键字，代表此函数是一个内联函数，放在函数返回值的前面
inline int my_func(int a, int b) {

	return (a < b ? a : b);
}
```

## 1.1 默认参数和占位参数
```C++
//默认参数为100
void func1(int x=100) {
	cout << "func1: x " << x << endl;
}

//占位参数，可以传入一个字面量，一般用不上
void func1(int x,int) {
	cout << "func1: x " << x << endl;
}
func1(x,10)
```
## 1.2 函数重载
* 函数名相同
* 参数个数不同,参数的类型不同,参数顺序不同,均可构成重载
* 1.严格进行参数列表匹配，2.如果隐式转化能匹配 3.匹配失败
```C++
#include<iostream>
using namespace std;

//决定一个函数的特征： 1.返回值 2.参数列表

//void (*fp)(int)
void func(int a) {
	cout << "func1 : " << endl;
	cout << a << endl;
}

//函数重载，就是对参数列表的 变换 不是函数返回值的 变化
//参数列表不同，并且函数名相同的函数都是 重载函数
//函数重载最好不要有默认参数

char func(int a, int b) {
	cout << "func2 : " << endl;
	cout << a <<","<< b << endl;
	return 'd';
}

int func(int a, int b,int c) {
	cout << "func3 : " << endl;
	cout << a << "," << b << ","<<c<<endl;
	return a;
}


int main()
{
	int c = 0;
	//定义一个指向 void func(int a)的函数指针
	void(*fp)(int) = func;//fp就是执行 void()(int)这种函数类型的指针
	fp(10);//调用函数 func
	func(20);
	func(10, 20);
	c=func(10, 20, 30);
	cout << c;

	system("pause");
}
```
## 1.3 函数指针和函数重载
函数指针是恒定指向一个函数的入口，**不支持** 重载！
```C++
#include<iostream>
using namespace std;

void func(int a, int b)
{
	cout << a <<","<< b << endl;
}

//1.定义了一个函数类型
typedef void(myfunctype)(int, int);
//定义了一个函数类型，返回值是void,参数列表是int,int

//2.定义了一个函数指针类型
typedef void(*myfunctype_pointer)(int, int);
//定义了一个函数指针类型,返回值是void,参数列表是int,int



int main()
{
	void(*fp)(int, int) = func;
	fp(10, 20);//10,20
	
	//定义一个函数指针
	myfunctype *fp1 = func;
	fp1(10, 20);

	myfunctype_pointer fp2 = func;
	fp2(10, 20);



	system("pause");
}
```

## 1.4 类和对象的基本语法
```C++
#include<iostream>
using namespace std;

//定义一个类的关键字
class Hero //定义一个类名
{
public:	//访问控制符 访问权限
	int sex;
	char name[64];

	//成员函数,不像python一样，需要使用self来调用
	void print() {
		cout << name << " , "<<sex << endl;
	}

private:

};


//定义一个动物类
class Animal
{
public: //访问权限的控制符
	char color[64];
	char kind[64];

	//拥有写字的方法
	void write() {
		cout << kind <<":"<< "开始写作" << endl;

	}

	//拥有跑步法方法
	void run() {
		cout << kind <<":"<< "跑步了" << endl;
	}


private:

};

void main()
{	
	Hero wufan;//通过 类创建一个对象
	wufan.sex=1;
	char ss[10] = "wufandas";
	strcpy_s(wufan.name, "wufanlalala");

	wufan.print();

	Animal dog;
	Animal sheep;
	strcpy_s(dog.kind, "狗");
	strcpy_s(dog.color, "黄色");

	dog.run();
	dog.write();


	system("pause");
}
```

## 1.5 类的封装和访问控制
三种类的封装：
* Public修饰成员变量和成员函数可以在类的内部和类的外部被访问
* Private修饰成员变量和成员函数只能在类的内部被访问
* protected在单类的时候，和Private一样
```C++
#include<iostream>
using namespace std;

//面对对象有三大特点：封装，继承，多态。

class MyDate
{
public://访问控制权限 
//在public下定义的成员变量和成员函数都可以在 类的外部访问和看见
	int year;
	int month;
	int day;

	void init() {
		cout << "year,month,day,minutes" << endl;
		cin >> year;
		cin >> month;
		cin >> day	;
		cin >> minutes;
	}

	void printDate() {
		cout << "日期是：" << year << "年" << month << "月" << day << "日" << endl;
	}

	bool isLeapYear() {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void get_pri_min() {
		cout << "min " << minutes;
	}

protected:
//如果是单个类，和private是一样的，在类的内部能够访问，在类的外部不能够访问
private:
//在private访问控制符下的定义的 成员变量和成员函数 只能在 类的内部访问。封装
	int minutes;
};

void t1() {
	MyDate data;//创建对象

	data.init();
	data.printDate();
	if (data.isLeapYear() == true) {
		cout << "这个是闰年" << endl;
	}
	else {
		cout << "这个不是闰年" << endl;
	}

	data.year = 10;//可以在外部直接修改 public的变量
	//data.minutes; 私有变量无法在外部修改

	data.get_pri_min();
}



void main() {
	t1();
	system("pause");
}
```

## 1.6 易犯错误
```C++
class Circle
{
public:
	//1.很容易在这里弄错。将函数入口变量设置为m_r.覆盖了 私有成员变量
	
/*	void setr(int m_r) {
		m_r = m_r;
	}*/
	void setr(int r) {
		m_r = r;
	}
	void getr() {
		cout << m_r << endl;
	}
	void getArea() {
		cout << m_r * m_r*3.14 << endl;
	}
private:
	int m_r;
};

int main() {
	Circle one;
	one.setr(10);
	one.getArea();
	one.getr();

	system("pause");
}
```
```C++
#include<iostream>
using namespace std;

class Circle
{
public:
	
	void setr(int r) {
		m_r = r;
	}
	void getr() {
		cout << m_r << endl;
	}
	void getArea() {
		cout << Area << endl;
	}
private:
	int m_r;
	//2.在通过setr()设置m_r,以后，Area不会再次计算,会输出随机数
	int Area = m_r * m_r*3.14;

};

int main() {
	Circle one;
	one.setr(10);
	one.getArea();
	one.getr();

	system("pause");
}
```

## 1.7 利用.h和.c分开定义类
```C++
Circle.h
#pragma once
/*
#pragma one 
和下面的语句一样的作用,保证头文件只被引用一次，
防止重复定义

#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#endif
*/
//.H文件作用是 声明
//原类
class Circle
{
public:
	void setR(double r);
	void getR();

	void getArea();
	 void getGirth();

private:
	double m_r;
};

------------------------------------------
Circle.c
#include "Circle.h"
#include<iostream>
using namespace std;
//在.cpp中定义函数的 内容


void Circle::setR(double r)
{	//这里面依然是 Circle类的内部
	m_r = r;
}

void Circle::getR()
{
	cout << m_r << endl;
}

void Circle::getArea() {
	cout << m_r * m_r*3.14 << endl;
}

void Circle::getGirth() {
	cout << 2 * 3.14*m_r << endl;
}

---------------------------------------------------
main.c
#include<iostream>
#include"Circle.h"//引用.h文件用双引号 " "


using namespace std;

int main(void) {
	Circle c1;
	c1.setR(10.0);

	c1.getArea();
	c1.getGirth();
	system("pause");
}
```
## 1.8 作业
```C++
#pragma once
#include<cmath>
class Point
{
public:
	double distance(Point &p2) {
		return sqrt((x-p2.x)* (x - p2.x) + (y - p2.y)*(y-p2.y));
	}
	void setx_y(double i,double j) {
		x = i;
		y = j;
	}
	
private:
	double x, y;

};

----------------------------------------------------
#include "Point.h"
#include<iostream>

using namespace std;

int main() {

	Point pa, pb;
	pa.setx_y(1, 1);
	pb.setx_y(2, 2);
	double dis;
	dis = pa.distance(pb);
	cout << dis << endl;
	system("pause");
}

```