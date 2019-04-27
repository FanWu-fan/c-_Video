#include "pch.h"
#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		m_a = 0;
		m_b = 0;
		cout << "a = " << m_a << "b = " << m_b << "无参构建" << endl;
	}
	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "a = " << m_a << "b = " << m_b << "有参构建" << endl;

	}
	~Test()
	{
		cout << "a = " << m_a << "b = " << m_b << "析构"<<endl;
	}

	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}
	void printf()
	{
		cout << "a = " << m_a << "  b = " << m_b << "输出打印" << endl;
	}
private:
	int m_a;
	int m_b;
};



//c语言中：
void test1()
{
	int *p = (int*)malloc(sizeof(int));//开辟一个4字节的空间
	*p = 10;
	cout << *p << endl;
	if (p != NULL)
	{
		free(p);
	}

	int *array_p = (int*)malloc(sizeof(int) * 10);//开辟10个数组
	for (int i = 0; i < 10; i++)
	{
		array_p[i] = i + 10;
	}
	//给数组赋值
	for (int i = 0; i < 10; i++)
	{
		cout << array_p[i] << endl;
	}
	if (array_p != NULL)
	{
		free(array_p);
	}

	cout << "----------" << endl;

	Test *tp = (Test *)malloc(sizeof(Test));
	
	tp->setA(10);
	tp->setB(20);//malloc出来的对象指针，只能够通过成员函数来进行初始化
	tp->printf();
	if (tp) free(tp);//用malloc无法调用构造函数，同样无法构建析构函数
}

//C++中的 new和delete

void test2()
{
	//new可以完成所有malloc的需求
	int *p = new int;//在动态堆上开辟4个字节
	*p = 10;
	cout << *p << endl;
	if (p != NULL)
		free(p);//delete 一个变量


	int *array_p = new int[10];//开辟了10个int的数组
	for (int i = 0; i < 10; i++)
		array_p[i] = i + 10;
	for (int i = 0; i < 10; i++)
		cout << array_p[i] << endl;
	if (array_p != NULL)
		//free(array_p);//delete 一个数组
		delete[] array_p;

	cout << "----------------" << endl;
	//Test *tp = new Test(10, 20);//new在创建一个对象的时候，会调用构造函数
	Test *tp = new Test();
	if (tp) delete  tp;//delete在释放一个对象的时候，会调用对象的析构函数
}
//malloc和free是函数，在对于普通变量是可以混合使用的
//但是new和delete是操作符，不是一个函数，没有压栈和出栈过程
int main()
{
	test1();
	test2();
	return 0;
}


