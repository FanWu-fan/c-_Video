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
	cout << "������Ĭ���޲����Ĺ��캯����" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::Test(int a, int b)
{
	m_x = a;
	m_y = b;
	cout << "�����˴��ι��캯����" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::Test(const Test  &  another )
{
	m_x = another.m_x;
	m_y = another.m_y;
	cout << "�����˿���������" << "m_x: " << m_x << " m_y: " << m_y << endl;
}

Test::~Test()
{
	cout << "����������������" << "m_x: " << m_x << " m_y: " << m_y<<endl;
}

void Test::print()
{
	cout << "�����������m_x: " << m_x << " m_y: " << m_y<<endl;
}

//1.�����������÷���������
void test1() {
	Test t1(10,10);
	Test t2(t1);
}

//2.�����������÷���������
void test2() {
	Test t1(20, 20);
	Test t2;
	t2 = t1;
	t2.print();
}

//3.����þֲ�����t�Ŀ������캯��
void func(Test t)
{
	cout << "func����������" << endl;
	t.print();
	cout << "func�����������" << endl;
}
void test3()
{
	Test t1(30, 30);
	func(t1);
	cout << "����3�������" << endl;
}

//����4
Test fun2()
{
	cout << "func����������" << endl;
	Test temp(40, 40);	//���ô��ι��캯��		
	cout << "func�����������" << endl;
	return temp;		//��һ����ʱ����������=temp,
						//�������ʱ��������Ŀ������캯������temp�����ݸ����� ��ʱ����������
						//temp��������������������
}

void test4()
{
	fun2();
	//���������ڴ˱����������һ����ʱ�����������û���κ�һ������ȥ����������������Ϊ���
	//��ʱ�����������κ��ô������������������������ʱ�� ��������
	cout << "����4�������" << endl;
}



//����5
void test5()
{
	Test t1 = fun2();
	cout << "����5�������" << endl;
}

//����6
void test6()
{

	Test t1;//����t1�� �޲ι��캯��
	t1 = fun2();	//�����˵ȺŲ�����,��ʱt1�Ѿ�������һ�� ���캯��
				//��ÿ������ֻ�ܵ���һ�� ���캯������ˣ���ʱ��������û�� ���������ᱻ ��������
	
	cout << "����6�������" << endl;
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