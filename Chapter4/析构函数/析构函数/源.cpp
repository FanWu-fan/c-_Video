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