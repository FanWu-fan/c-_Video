#include<iostream>
using namespace std;

class Test
{
public:
	//Ĭ�Ϲ��캯��������һ�� �޲����Ĺ��캯��
	//�������ʾ���ṩ ���캯����ϵͳ���ǵ���Ĭ�ϵĹ��캯��

	//��������ṩ��һ������ĺ���(�����Ƿ��в���)����ôĬ�ϵĹ��캯���ͱ� ������
	//���캯��һ�����ֶ��ṩ��Ĭ�Ͻ���������
	/*Test(){}*/				//0.Ĭ�Ϲ��캯��
	Test();						//1. �޲ι��캯��
	Test(int, int);				//2.�вι��캯��
	Test(const Test & another);	//3.�������캯��


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

//ͨ������һ������Test���� another �������󿽱�,ʹ�� const��ֹanother���޸�
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
	cout << "����������ִ����" << endl;
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

	//Test t4 = t2;//���Ҳ����� �������캯��

	//Test t5;//���ȵ��� �޲ι��캯��
}


int main()
{
	tt();
	
	system("pause");
}