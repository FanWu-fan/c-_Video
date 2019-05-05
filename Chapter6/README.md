# Chapter6 多态
## 1.0 为何要有多态
* 重定义函数：发生在子类和父类之间
* 当子类重写父类的成员函数，如果父类中这个函数不是虚函数，是函数的 **重定义**
* 如果子类重写父类的成员函数，如果父类中的这个函数是 **虚函数**。这是函数 的 **重写**。
* 多态发生必须要有继承，要有子类重写父类的虚函数，以及父类指针(或者引用)指向子类对象。

```C++
#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void print() //这个virtual是保证给一个成员函数定义为 虚函数，当子类去重写虚函数时，父类指针指向这个函数时，
		//会调用子类的函数。
	{
		cout << "Parent::print():a= " << a << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()//重定义父类函数,这里加virtual是为了可读性，将 重定义变为 重写 父类的 虚函数
	{
		cout << "Child::print():b= " << b << endl;
	}
private:
	int b;
};

class Child2 :public Parent
{
public:
	Child2(int a):Parent(a)
	{

	}
	virtual void print()
	{
		cout << "This is a Child 2" << endl;
	}
private:

};


void myPrint(Parent *p)//让父类指针指向子类的对象的时候，就会调用 子类的 重写函数
{
	p->print();//在此时 print函数 发生了 多态现象
}

int main()
{
	Child c(10,20);
	c.print();//20

	Parent p(100);
	p.print();//100

	myPrint(&p);//调用的父类print 100
	myPrint(&c);//10 ，调用的是父类的，编译器会不管传递进来的是 父类还是子类
	//Parent * p =&c,

	Child2 c2(200);
	myPrint(&c2);
}
}
```
## 1.1 动态联编和静态联编

1. 联编是指一个程序模块、代码之间相互关联的过程。
2. 静态联编(static bingding)，是程序的匹配、连接在编译阶段实现，也称为早期匹配。**重载函数** 使用 **静态联编**。
3. 动态联编是指程序联编推迟到运行时进行，所以又称为 晚期联编。 **swtich** 和 **if** 是动态联编的例子。

## 1.2 虚析构函数
* 构造函数 **不能** 是 **虚函数**。建立一个派生类对象时，必须从类层次的根开始，沿着继承路径逐个调用基类的构造函数。
* 析构函数可以是虚的。虚析构函数用于指引 **delete**运算符正确析构动态对象。

```C++
// 虚析构函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()....." << endl;
		this->p = new char[64];
		strcpy_s(p,20,"A string");
	}
	virtual ~A()
	{
		cout << "~A()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()
	{
		cout << "A :" << p << endl;
	}
private:
	char *p;
};

class B :public A
{
public:
	B()
	{
		cout << "B()...." << endl;
		this->p = new char[64];
		strcpy_s(p, 20, "B string");
	}

	virtual ~B()
	{
		cout << "~B()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()
	{
		cout << "B :" << p << endl;
	}
private:
	char *p;
};

class C :public B
{
public:
	C()
	{
		cout << "C()...." << endl;
		this->p = new char[64];
		strcpy_s(p, 20, "C string");
	}
	virtual ~C()
	{
		cout << "~C()....." << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}
	virtual void print()//多态重写
	{
		cout << "C :" << p << endl;
	}
private:
	char *p;
};

void func(A *p)
{
	p->print();
	delete p;//这里会将p只看作父类指针来释放，而不是释放3次。
	//如果不加虚析构，只会析构父函数一次，加了之后，会优先调用 C的析构函数，来依次析构。
}



int main()
{

	C *cp = new C;
	cp->print();
	delete cp;


	cout << "------------------" << endl;

	C *cp1 = new C;
	func(cp1);//使用多态
 
}
```

## 1.3 重载，重写和重定义
>重载：
>* 在同一个类中
>* 函数名字相同
>* 参数不同
>* virtual关键字可有可无

>重写(覆盖)是指派生类函数覆盖基类函数，特征是：
>* 不同的范围，分别位于基类和派生类中
>* 函数名字相同
>* 参数 **相同**
>* virtual关键字 **必须有**

>重定义(隐藏) 是指派生类函数 **屏蔽了** 基类函数，特征是：
>* 如果派生类的函数和基类的函数同名，但是参数不同，此时，不管有无virtual，基类的函数被 **隐藏**
>* 如果派生类的函数和基类的函数同名，并且参数 **相同**，但是基类函数 **没有** virtual,此时，基类函数被 **隐藏**

## 1.4 多态的原理
* 当类中声明 **虚函数** 时，编译器会在类中生成一个 **虚函数表**
* 虚函数表时一个存储 **类成员函数指针** 的数据结构
* 虚函数表时由编译器自动生成与维护的
* **virtual成员函数** 会被编译器放入 **虚函数表** 中
* 存在虚函数时，每个对象都有一个指向虚函数的指针( **vptr指针** )

```c++
#include "pch.h"
#include <iostream>
using namespace std;
class Parent
{
public:
	virtual void func(int a, int b)
	{
		cout << "Parent:func(int a, int b)..." << endl;
	}

	void func(int a, int b, int c)
	{
		cout << "Parent:func(int a, int b, int c)..." << endl;
	}
private:
	int a;
};
class Child :public Parent
{
public:
	void func(int a, int b)
	{
		cout << "Child:func(int a, int b)..." << endl;
	}
	void func(int a, int b, int c)
	{
		cout << "Child:func(int a, int b, int c)..." << endl;
	}
private:
	int b;
};
int main()
{
	Parent *p = new Child;//父类指针指向了 子类对象
	p->func(10, 20);//"Child:func(int a, int b)...",此时发生了多态，调用了Child，动态联编
	p->func(10, 20, 30);//Parent:func(int a, int b, int c)...,此时只有重载，没有多态，静态联编
	
	Parent p1;
	Child c1;
	cout << "szieof Parent " << sizeof(p1) << endl;//此表中由 vptr指针，占用了4个字节，一共8字节
	cout << "szieof Child " << sizeof(c1) << endl;//12字节
}
```

## 1.5 vptr指针在构造父类的时候是分步初始化
* 对象在创建时，由编译器对VPTR指针进行初始化
* 只有当对象的构造完全结束后VPTR的指向才最终确定
* 父类对象的VPTR指向父类虚函数表
* 子类对象的VPTR指向子类的虚函数表
```C++
#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)....." << endl;
		this->a = a;

		print();//这个print是在 Child的 vptr指针尚未建立时的输出，采用的是 Parent的。
	}
	virtual void print()
	{
		cout << "Parent::print() " << a << endl;
	}

private:
	int a;
};


class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		print();//在执行完父类的构造函数以后，vptr指针就建立了，此时执行的是 子类的print
		cout << "Child(int a, int b)....." << endl;
		this->b = b;
	}
	//重写父类的虚函数
	virtual void print()
	{
		cout << "Child::print() " << b << endl;
	}
private:
	int b;
};



int main()
{
	Parent *p = new Child(10, 20);
	p->print();
	delete p;


}


Parent(int a).....
Parent::print() 10
Child::print() -842150451
Child(int a, int b).....
Child::print() 20
```

## 1.6 父类指针和子类指针的步长
* 在父类中，int占据4个字节，VPTP占据4个字节。
```C++
#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::print()  " << endl;
	}
	int a;
private:
};

class Child :public Parent
{
public:
	Child(int a) :Parent(a)
	{

	}
	virtual void print()
	{
		cout << "Child::print()  " << a << endl;
	}
private:
	int b;//这里添加以后，子类的内存比父类大，12>8，指针++会出错
};


int main()
{
	Parent p1(10);
	Child c1(10);
	cout << "sizeof Child" << sizeof(c1) << endl;//8个字节，VPTR这里未初始化，不存在
	cout << "sizeof Parent" << sizeof(p1) << endl;//8个字节，a占了4个，VPTR指针占了4个

	Child array[] = { Child(0),Child(1),Child(2) };
	//这个不是匿名对象，   array[0],array[1],array[2]

	Child *cp = &array[0];
	Parent *pp = &array[0];

	cout << "------------" << endl;
	cp->print();//Child
	pp->print();//Child 发生多态

	cout << "------------" << endl;
	cp++;//+12个
	pp++;//+8个
	cp->print();//Child
	pp->print();//Child 发生多态


	cout << "------------" << endl;

	int i = 0;
	for (i = 0, pp = &array[0]; i < 3; i++,pp++)
	{
		pp->print();
	}
}
```

## 1.7 纯虚函数和抽象类
纯虚函数是一个在 **基类** 中说明的 **虚函数**，在基类中没有 **定义**，要求任何派生类都定义自己的版本。
纯虚函数为多个派生类提供一个公共界面(接口的封装和设计，软件的模块功能划分)

* 纯虚函数的语法：
**virutual 类型 函数名 (参数表) =0；**
一个具有纯虚函数的基类称为 **抽象类**。

* 含有纯虚函数的类，称为抽象基类，**不可实例化**。即不能创建对象，存在的意义就是 **被继承**，提供族类的公共接口。
* 纯虚函数只有 **声明**，没有实现，被“初始化”为0
* 如果一个类中声明了纯虚函数，而在派生类中没有对该函数的定义，在该虚函数在派生类中仍然为 **纯虚函数**，派生类仍然为纯虚基类。

```C++
#include "pch.h"
#include <iostream>
using namespace std;

//图像类
//拥有纯虚函数的类，称为 抽象类
class Shape
{
public:
	//是一个抽象的结构，说明图像是有一个得到面积的方法
	virtual double getArea() = 0;//这个等于0，代表了一个接口

	//打印接口
	virtual void print() = 0;

};

//圆类
//如果一个子类继承了抽象类，一定要重写这个纯虚函数
class Circle :public Shape
{
public:
	Circle(double r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		
		return 3.14*r*r;
	}
	virtual void print()
	{
		cout << "Circle Area: " << this->getArea() << endl;
	}
private:
	double r;
};
//实现一个正方形

class Rect :public Shape
{
public:
	Rect(double l)
	{
		this->l = l;
	}
	virtual double getArea()
	{
		return l*l;
	}
	virtual void print()
	{
		cout << "Rect Area: " << this->getArea() << endl;
	}
private:
	double l;
};


int main()
{
	//Shape p;//抽象类不能够实例化，子类继承于抽象类，一定要将纯虚函数重写。
	Shape *sp = new Circle(10);
	Shape *rp = new Rect(10);

	sp->print();//在这里发生了多态
	rp->print();//实现了面向 对象编程
}
```


