#include<iostream>
using namespace std;

class A
{
public:
	A(int a);//��ʵ�ṩһ���������Ĺ��캯��
	~A();
	void printA();

private:
	int m_a;
};

A::A(int a)
{
	this->m_a = a;
}

A::~A()
{
	cout << "a= " << m_a << "��������" << endl;
}

void A::printA()
{
	cout << "a= " << this->m_a << endl;
}

class B
{
public:
	B(int b):a1(10),a2(100)//�ڳ�ʼ��B��ʱ��ͨ����ʼ���б���ڲ�����a1��a2�����˳�ʼ��
	{//���ڲ��Ķ����ʼ����˳��Ͷ������˳��һ��������ʼ���б��е�˳���޹�
	//������˳��Ͷ������˳���෴
		m_b = b;
	}

	B(int aa1, int aa2, int b) : a1(aa1), a2(aa2), m_b(b)//ͨ����ʼ���б����ܹ���ʼ����Ա���󣬻����Գ�ʼ����Ա����
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
		cout << "B= " <<m_b<<"��������������"<< endl;
	}

private:
	int m_b;
	A a1;
	A a2;
}; 

class ABC
{
public:
	ABC(int a, int b, int c, int d ) : m_a(a), m_b(b), m_c(c), m_m(d)//������Աֻ��ͨ����ʼ���б���г�ʼ�����������¸�ֵ
	{
		//this->m_m = d;
	}
private:
	int m_a;
	int m_b;
	int m_c;
	const int m_m;//����
};

class ABCD
{
public:
	ABCD(int a, int b, int c, int d) :a4(a, b, c), m_a(d) {}

private:
	ABC a4;
	int m_a;
};


class ABCD
{
public:
private:

};


void test1()
{
	A a(10);
}

void test2()
{
	B b(1);
	b.printB();

	B b2(10);
	b2.printB();
}

int main()
{	
	//test1();
	test2();
	system("pause");
}