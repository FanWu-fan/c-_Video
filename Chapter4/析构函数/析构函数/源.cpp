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

Test::Test()//���캯��
{
	m_x = 10;
	m_y = 15;
}

Test::Test(int a, int b) {
	m_x = a;
	m_y = b;
}


Test::~Test()//��������û�в�����
{
	cout << "��������������" << endl;
}

void Test::print()
{
	cout << "m_x : " << m_x << "  m_y : " << m_y << endl;
}

void mm() {
	Test t4;
	t4.print();
	//t4��һ���ֲ������������������ں� mm()һ���ģ���Ҫ������
	//�ں��������ͷ�֮ǰ��������������
	//��� "����������������
}


int main() {
	Test t1;
	t1.print();
	Test t2(2,2);
	t2.print();
	mm();

	system("pause");
}