#include<iostream>
using namespace std;
class AA
{
public:
	AA(int a, int b) 
	{
		m_a = a;
		m_b = b;
	}
	int getC()
	{
		cout << "c= " << m_c <<" &c: "<< & m_c << endl;
		m_c++;
		return m_c;
	}
	static int m_c;//静态的成员变量//1. 在类的内部声明这个变量用 static
private:
	int m_a;
	int m_b;
};

class BB
{
public:
	void pring()
	{
		cout << "c= " << AA::m_c << " &c: " << &AA::m_c << endl;
	}
private:
	int h;
};



//2. 静态成员变量的初始化，在类的外部去写,必须要初始化，
//m_c不是在对象内部开辟空间，而是在全局
int AA::m_c = 0;

int main()
{
	AA aa1(10, 20),aa2(100,200),aa3(1000,2000);
	aa1.getC();
	aa2.getC();
	aa3.getC();
	AA::m_c = 200;
	aa1.getC();
	aa2.getC();
	aa3.getC();

	BB b;
	b.pring();
	system("pause");
	return 0;
}