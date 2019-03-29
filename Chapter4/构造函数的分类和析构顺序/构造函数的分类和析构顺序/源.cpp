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
	m_y = 0;
	m_x = 0;
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
	cout << "析构函数被执行了" << endl;
	cout << "m_x ;" << m_x << " m_y: " << m_y << endl;
}

void tt() {
	Test t1;
	t1.print();

	Test t2(10, 20);
	t2.print();

	Test t3(20,30);
	t3.print();

	Test t4(30, 40);

	//Test t4 = t2;//这个也会调用 拷贝构造函数

	//Test t5;//优先调用 无参构造函数
}


int main()
{
	tt();
	
	system("pause");
}