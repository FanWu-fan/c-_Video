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

int run2()
{
	cout << "run2 start.." << endl;
	//ABCD(400, 500, 600);//临时对象的生命周期，匿名对象，匿名的临时对象编译器会立刻销毁，不等到正常的函数调用完毕
	//产生以后就开始析构
	ABCD abcd = ABCD(100, 200, 300);//这里产生匿名对象以后，不是通过 拷贝构造函数来传递，而是直接取 别名。所以只有一次构造
	//并且在run2结束以后才 进行 析构

	cout << "run2 end" << endl;
	return 0;
}

int main()
{
	//run();
	run2();
	system("pause");
	return 0;
}