#include<iostream>
using namespace std;

class Test
{
public:
	Test();
	Test(int a, int b);
	Test(const	Test &another);

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
	cout << "调用了带参构造函数：" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::Test(const Test  &  another )
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

//1.拷贝函数调用发生场景：
void test1() {
	Test t1(10,10);
	Test t2(t1);
}

//2.拷贝函数调用发生场景：
void test2() {
	Test t1(20, 20);
	Test t2;
	t2 = t1;
	t2.print();
}

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



//场景5
void test5()
{
	Test t1 = fun2();
	cout << "函数5调用完毕" << endl;
}

//场景6
void test6()
{

	Test t1;//调用t1的 无参构造函数
	t1 = fun2();	//调用了等号操作符,此时t1已经调用了一次 构造函数
				//而每个函数只能调用一此 构造函数，因此，此时匿名函数没有 别名，将会被 销毁析构
	
	cout << "函数6调用完毕" << endl;
}



int main()
{  
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	system("pause");
}