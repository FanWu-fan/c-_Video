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
	static int m_c;//��̬�ĳ�Ա����//1. ������ڲ�������������� static
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



//2. ��̬��Ա�����ĳ�ʼ����������ⲿȥд,����Ҫ��ʼ����
//m_c�����ڶ����ڲ����ٿռ䣬������ȫ��
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