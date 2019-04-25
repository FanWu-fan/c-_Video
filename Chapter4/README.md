# Chapter4 类和对象
## 1.0 构造函数
在创建一个对象的时候，系统直接初始化就是 构造函数
* 构造函数是为了给对象初始化而出现的，函数名字和 **类型** 是一样的，没有 **返回值**，并且可以 **重载**


```C++
#include<iostream>	
using namespace std;

class Test
{
public:
	//构造函数，函数没有返回值，函数名字和 类型名字一样
	Test() {
		m_x = 10;
		m_y = 15;
	}

	//构造函数重载
	Test(int x,int y) {
		m_x = x;
		m_y = y;
	}
	void print() {
		cout << "m_x: " << m_x << "  m_y: " << m_y << endl;
	}

private:
	int m_x;
	int m_y;
};

int main() {
	Test t1;//调用无参函数
	t1.print();
	Test t2(20, 20);//重载构造函数，调用 有参函数
	t2.print();

	system("pause");
}
```
## 1.1 析构函数
* 析构函数语法格式： ~ + 类型名字 没有任何的参数
* 在对象被销毁之前，系统 自动调用 析构函数，
* 一般用于释放内存空间，在对象销毁前完成 一些 清理工作
* 由于是无参函数，因此没有重载

```C++
#include<iostream>
using namespace std;

class Test
{
public:
	Test();
	Test(int, int);
	~Test();
	void print();

private:
	int m_x;
	int m_y;
};

Test::Test()//构造函数
{
	m_x = 10;
	m_y = 15;
}

Test::Test(int a, int b) {
	m_x = a;
	m_y = b;
}


Test::~Test()//析构函数没有参数，
{
	cout << "调用了析构函数" << endl;
}

void Test::print()
{
	cout << "m_x : " << m_x << "  m_y : " << m_y << endl;
}

void mm() {
	Test t4;
	t4.print();
	//t4是一个局部变量，它的声明周期和 mm()一样的，需要被销毁
	//在函数对象被释放之前，调用析构函数
	//输出 "调用了析构函数”
}


int main() {
	Test t1;
	t1.print();
	Test t2(2,2);
	t2.print();
	mm();

	system("pause");
}
```

## 1.2 构造函数的种类和析构函数的顺序
* 默认构造函数，就是一个 无参数的构造函数,如果不显示地提供 构造函数，系统就是调用默认的构造函数,如果我们提供了一个构造的函数(无论是否有参数)，那么默认的构造函数就被 隐藏了,构造函数一旦被手动提供，默认将不复存在.
* 析构函数的顺序是：压栈，谁最后被创建，谁首先被执行。
```C++
#include<iostream>
using namespace std;

class Test
{
public:
	//默认构造函数，就是一个 无参数的构造函数
	//如果不显示地提供 构造函数，系统就是调用默认的构造函数

	//如果我们提供了一个构造的函数(无论是否有参数)，那么默认的构造函数就被 隐藏了
	//构造函数一旦被手动提供，默认将不复存在
	/*Test(){}*/				//0.默认构造函数
	Test();						//1. 无参构造函数
	Test(int, int);				//2.有参构造函数
	Test(const Test & another);	//3.拷贝构造函数


	void print();
	~Test();

private:
	int m_x;
	int m_y;
};

Test::Test()
{
}

Test::Test(int a, int b)
{
	m_y = a;
	m_x = b;
}

//通过另外一个对象Test对象 another 将本对象拷贝,使用 const防止another被修改
Test::Test(const Test & another)
{
	m_x = another.m_x;
	m_y = another.m_y;
}

void Test::print()
{
	cout << "m_x : " << m_x << "  m_y: " << m_y << endl;
}

Test::~Test()
{
}

int main()
{
	Test t1;
	t1.print();

	Test t2(10, 20);
	t2.print();

	Test t3(t2);
	t3.print();

	Test t4 = t2;//这个也会调用 拷贝构造函数

	Test t5;//优先调用 无参构造函数
	t5 = t2;
	system("pause");
}
```
## 1.3 拷贝构造函数调用的发生场景
```C++
class Test
{
public:
	Test();//将默认 无参构造函数 重载了！
	Test(int a, int b);
	Test(const	Test &another);//将函数的默认 构造函数拷贝 重载了！

	~Test();
	void print();


private:
	int m_x;
	int	m_y;
};

Test::Test()
{
	cout << "调用了默认无参数的构造函数：" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::Test(int a, int b)
{
	m_x = a;
	m_y = b;
}

Test::Test(const Test & another)
{
	m_x = another.m_x;
	m_y = another.m_y;
	cout << "调用了拷贝函数：" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::~Test()
{
	cout << "调用了析构函数：" << "m_x: " << m_x << " m_y: " << m_y<<endl;
}

void Test::print()
{
	cout << "调用了输出：m_x: " << m_x << " m_y: " << m_y<<endl;
}
```
* 拷贝构造函数第一个场景：通过t1给t2初始化
```C++
//1.拷贝函数调用发生场景：
void test1() {
	Test t1(10,10);
	Test t2(t1);
}
```
* 拷贝构造函数第二个场景：先初始化t2,再调用 t2=t1,但不是调用t2的拷贝构造函数。**构造函数只能被调用一次。**
```C++
//2.拷贝函数调用发生场景：
void test2() {
	Test t1(20, 20);
	Test t2;
	t2 = t1;
	t2.print();
}
```
* 拷贝构造函数第三个场景：
```C++

//3.会调用局部变量t的拷贝构造函数
void func(Test t)
{
	cout << "func函数被调用" << endl;
	t.print();
	cout << "func函数调用完毕" << endl;
}
void test3()
{
	Test t1(30, 30);
	func(t1);
	cout << "函数3调用完毕" << endl;
}

/*
调用了拷贝函数：m_x: 30 m_y: 30
func函数被调用
调用了输出：m_x: 30 m_y: 30
func函数调用完毕
调用了析构函数：m_x: 30 m_y: 30
函数3调用完毕
调用了析构函数：m_x: 30 m_y: 30
*/
```

* 拷贝构造函数第四个场景：函数返回 Test t1,会首先将t1 拷贝到一个临时的匿名变量，然后将 t1 析构，返回 临时的匿名变量，如果没有来接收 临时的匿名变量。这个临时的匿名变量也将被 析构
```C++
//场景4
Test fun2()
{
	cout << "func函数被调用" << endl;
	Test temp(40, 40);	//调用带参构造函数		
	cout << "func函数调用完毕" << endl;
	return temp;		//有一个临时的匿名对象=temp,
		//会调用临时匿名对象的拷贝构造函数，把temp的数据给到了 临时的匿名对象
				//temp将被析构，函数被销毁
}

void test4()
{
	fun2();
//匿名对象在此被析构，如果一个临时匿名对象，如果没有任何一个变量去接收它，编译器认为这个
//临时匿名对象无任何用处，编译器会立刻销毁这个临时的 匿名对象
	cout << "函数4调用完毕" << endl;
}

/* 
func函数被调用
调用了带参构造函数：m_x: 40 m_y: 40
func函数调用完毕
调用了拷贝函数：m_x: 40 m_y: 40 //匿名对象拷贝传进来 temp
调用了析构函数：m_x: 40 m_y: 40//temp被析构，函数func2执行完毕
调用了析构函数：m_x: 40 m_y: 40//匿名对象由于没有外部变量接收，故立刻被编译器 析构
函数4调用完毕
*/
```

* 拷贝函数的第五个场景：拷贝构造函数第四个场景：函数返回 Test t1,会首先将t1 拷贝到一个临时的匿名变量，然后将 t1 析构，返回 临时的匿名变量，如果有来接收这个 临时的匿名变量，那么将直接 将 临时的匿名变量变为 局部变量，不会再 发生拷贝。
```C++
Test fun2()
{
	cout << "func函数被调用" << endl;
	Test temp(40, 40);	//调用带参构造函数		
	cout << "func函数调用完毕" << endl;
	return temp;		//有一个临时的匿名对象=temp,
		//会调用临时匿名对象的拷贝构造函数，把temp的数据给到了 临时的匿名对象
				//temp将被析构，函数被销毁
}
void test5()
{
	Test t1 = fun2();
//如果有变量接收这个临时匿名对象，这个匿名对象不会被销毁
//t1 = fun2()没有调用 拷贝构造函数，此时 t1 就是匿名临时对象
	cout << "函数5调用完毕" << endl;
}
/*
func函数被调用
调用了带参构造函数：m_x: 40 m_y: 40
func函数调用完毕
调用了拷贝函数：m_x: 40 m_y: 40
调用了析构函数：m_x: 40 m_y: 40 //此时析构了temp
		//如果有变量接收这个临时匿名对象，这个匿名对象不会被销毁
		//t1 = fun2()没有调用 析构函数，此时 t1 就是匿名临时对象
函数5调用完毕
调用了析构函数：m_x: 40 m_y: 40
*/
```
* 拷贝函数的第六个场景:用一个已经被 构造的t去接收 匿名的临时变量，将不会调用拷贝构造函数，而且也不使用 匿名临时变量的 空间区域，匿名临时变量将会被 销毁析构。
```C++
//场景6
void test6()
{

	Test t1;//调用t1的 无参构造函数
	t1 = fun2();	//调用了等号操作符,此时t1已经调用了一次 构造函数
				//而每个函数只能调用一此 构造函数，因此，此时匿名函数没有 别名，将会被 销毁析构
	
	cout << "函数6调用完毕" << endl;
}
/*
调用了默认无参数的构造函数：m_x: -858993460 m_y: -858993460
func函数被调用
调用了带参构造函数：m_x: 40 m_y: 40
func函数调用完毕
调用了拷贝函数：m_x: 40 m_y: 40
调用了析构函数：m_x: 40 m_y: 40  //销毁析构 temp
调用了析构函数：m_x: 40 m_y: 40	//销毁匿名临时变量，因此此时匿名对象没有别名。
函数6调用完毕
调用了析构函数：m_x: 40 m_y: 40
*/
```

## 1.4 默认的拷贝构造和默认构造函数
* 构造函数分为三种：普通构造函数(无参构造函数)，拷贝构造函数，析构函数
* 三者之间互不影响，只有在出现相同类时,才会隐藏系统默认提供的 构造函数。
```C++
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
```
## 1.5 深拷贝浅拷贝
* 一旦在类中开辟 内存空间，一定要手写一个 拷贝构造函数，不能使用默认的 拷贝构造函数。因为默认的 拷贝构造函数 会将两个 实例化指向同一个 内存地址。
```C++
#include<iostream>
#include<cstring>
using namespace std;

class Teacher
{
public:
	Teacher();
	Teacher(const Teacher& other);
	Teacher(int id,const char * name);
	void print();
	~Teacher();

private:
	int m_id;
	char *m_name;
};

Teacher::Teacher()
{
}

//深拷贝，不仅仅只是把 other的指针存放地址拷贝过来，而是将
//一个新的内存空间地址放入 other.m_name的内容
Teacher::Teacher(const Teacher & other)
{
	m_id = other.m_id;
	int len = strlen(other.m_name);
	m_name = (char*)malloc(len + 1);
	strcpy_s(m_name, len + 1, other.m_name);
}

Teacher::Teacher(int id, const char * name)
{
	cout << "调用了有参构造函数" << endl;
	m_id = id;

	int len = strlen(name);	//它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，
	//直到碰到第一个字符串结束符'\0'为止，然后返回计数器值。
	m_name = (char*)malloc(len + 1);//不能直接将 name的地址给 m_name,因为m_name还未分配内存空间
	strcpy_s(m_name,len+1,name);	
}

void Teacher::print()
{
	cout << "id : " << m_id ;
}

Teacher::~Teacher()
{
	//在构造函数中已经开辟内存了，为了防止泄露，在析构函数中，
	//在对象销毁之前，将m_name的内存释放掉
	if (m_name != NULL)
	{
		free(m_name);
		m_name = NULL;
		cout << "释放掉了m_name" << endl;
	}
}

void test1()
{
	Teacher t1(10, "wufan");
	//如果不提供一个显示的 拷贝构造函数，通过系统默认的 拷贝构造函数
	Teacher t2(t1);//在退出 test1时，将t2析构掉了，而 t2和t1的 m_name 都指向同一个地址，
			//因此，在析构t1时，t1的 m_name 已经被析构掉了
}

int main()
{
	test1();
	system("pause");
}
```
## 1.6 构造函数的初始化列表
1. 在类中，成员变量为常量的，只能在初始化列表中进行初始化，不能赋值
2. 在类中，成员变量为 对象时，只能在初始化列表中进行 对象的初始化，不能在 {}中初始化,如果在{}中使用，是为 “函数调用”

```C++
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
```
## 1.7 强化练习1
```C++
#include<iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
		cout << "ADBC() construct, a: " << _a << " b: " << _b << " c: " << _c << endl;
	}
	~ABCD()
	{
		cout << "~ADBC() construct, a: " << _a << " b: " << _b << " c: " << _c << endl;
	}
	int getA()
	{
		return _a;
	}

private:
	int _a;
	int _b;
	int _c;
};

class MyE
{
public:
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout << "MyD()" << endl;
	}
	~MyE()
	{
		cout << "~MtD()" << endl;
	}
	MyE(const MyE & obj) :abcd2(10, 11, 12), abcd1(7, 8, 9), m(100)// 初始化成员对象，与初始化顺序无关，只和定义的顺序有关
	{
		cout << "MyD(const MyE &obj)" << endl;
	}



public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};

int doThing(MyE mye1)//局部变量会 使用拷贝构造函数
{
	cout << "doThing() mye1.abc1.a: " << mye1.abcd1.getA() << endl;//由于拷贝函数的原因，这里不再输出1而是输出7
	return 0;
}
int run()
{
	MyE mye;
	doThing(mye);//这里会调用 类的拷贝函数
	return 0;
}

int main()
{
	run();
	system("pause");
	return 0;
}
/*
ADBC() construct, a: 1 b: 2 c: 3
ADBC() construct, a: 4 b: 5 c: 6
MyD()
ADBC() construct, a: 7 b: 8 c: 9
ADBC() construct, a: 10 b: 11 c: 12
MyD(const MyE &obj)
doThing() mye1.abc1.a: 7
~MtD()
~ADBC() construct, a: 10 b: 11 c: 12
~ADBC() construct, a: 7 b: 8 c: 9
~MtD()
~ADBC() construct, a: 4 b: 5 c: 6
~ADBC() construct, a: 1 b: 2 c: 3
请按任意键继续. . .*/
```

## 1.8 强化练习2
```C++
int run2()
{
	cout << "run2 start.." << endl;
	ABCD(400, 500, 600);//临时对象的生命周期，匿名对象，匿名的临时对象编译器会立刻销毁，不等到正常的函数调用完毕
	//产生以后就开始析构
	cout << "run2 end" << endl;
	return 0;
}

/*run2 start..
ADBC() construct, a: 400 b: 500 c: 600
~ADBC() construct, a: 400 b: 500 c: 600
run2 end*/
```

```C++
int run2()
{
	cout << "run2 start.." << endl;
	//ABCD(400, 500, 600);//临时对象的生命周期，匿名对象，匿名的临时对象编译器会立刻销毁，不等到正常的函数调用完毕
	//产生以后就开始析构
	ABCD abcd = ABCD(100, 200, 300);//这里产生匿名对象以后，不是通过 拷贝构造函数来传递，而是直接取 别名。所以只有一次构造
	//并且在run2结束以后才 进行 析构

	cout << "run2 end" << endl;
	return 0;

/*
run2 start..
ADBC() construct, a: 100 b: 200 c: 300
run2 end
~ADBC() construct, a: 100 b: 200 c: 300
请按任意键继续. . .
*/
}
```
## 1.9强化练习3
```c++
#include<iostream>
using namespace std;

//构造中调用构造是危险的行为

class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	MyTest(int a, int b)
	{
		_a = a;
		_b = b;
		//_c = 100;
		MyTest(a, b, 100);//这个是匿名临时对象
		//直接被释放了

	}
	~MyTest()
	{
		cout << "MyTest~:" << _a << ", " << _b << ", " << _c << endl;
	}

	int getC()
	{
		return this->_c;
	}

	void setC(int val)
	{
		_c = val;
	}
private:
	int _a;
	int _b;
	int _c;

};

void test1()
{
	MyTest t1(1, 2);
	cout << "c: " << t1.getC() << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}
/*
MyTest~:1, 2, 100 //首先匿名对象在被创建以后就会被析构
c: -858993460
MyTest~:1, 2, -858993460 //t1然后被析构
请按任意键继续. . .
*/
```
## 2.0 静态成员变量和成员函数
静态static:
* 修饰全局变量，代表这个全局变量不能被其他文件访问。
* 修饰局部变量，会在静态区开辟一个空间，生命周期和整个程序一样。
* 修饰函数，表示这个函数只能够在本文件中使用，其他文件不能使用。
* 修饰类中的成员变量，由于空间开辟在全局上，必须在类外面，全局空间中进行初始化。 
* 只有静态成员函数，才能不用与特定的对象相对，直接当成类的全局函数。静态函数成员函数的意义，在于管理静态数据成员，完成对静态数据成员的封装；静态成员函数只能访问静态数据成员，因为非静态成员函数，在调用时this指针被当作参数传进，而静态成员函数属于类，而不属于对象，没有this指针。
```C++
#include"pch.h"
#include<iostream>
using namespace std;

class Student
{
public:
	Student(int num, double score)
	{
		this->m_num = num;
		this->m_score = score;
		count++;
		sum_score += score;
	}
	 static double getAvg()
	{

		return sum_score / count;
	}

private:
	int m_num;
	double m_score;
	static int count;
	static double sum_score;
};

int Student::count = 0;
double Student::sum_score = 0;

int main()
{
	Student s1(1, 100);
	Student s2(2, 90);
	Student s3(3, 80);
	cout << "AVG : " << Student::getAvg() << endl;//只有静态成员函数，才能不用与特定的对象相对，直接当成类的全局函数
	cout << "AVG : " << s2.getAvg() << endl;
	return 0;

}
```
## 2.1 static变量占用空间的大小
实际上，static成员变量和函数都不占用空间，决定类空间大小的只有普通的成员变量。
```c++
#include "pch.h"
#include <iostream>
using namespace std;

class c1
{
public:
	int i;//4
	int j;//4
	int k;//4
};//12


class c2
{
public:
	int i;
	int j;
	int k;
	static int m;  //4
public:
	int getK() const { return k; }	//4
	void setk(int val) { k = val; }//4
};

struct S1
{
	int i;
	int j;
	int k;
	
};//12

struct S2
{
	int i;
	int j;
	int k;
	static int m;
};//12

int main()
{
	cout << "c1: " << sizeof(c1) << endl;
	cout << "c2 : " << sizeof(c2) << endl;
	cout << "s1: " << sizeof(S1) << endl;
	cout << "s2: " << sizeof(S2) << endl;

}

c1: 12
c2 : 12
s1: 12
s2: 12

```











