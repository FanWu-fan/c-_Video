#include<iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int);
	~A();

private:
	int m_a;
};

A::A(int a)//�����ͨ�Ĺ��캯�����ṩ��һ����ʾ�Ĺ���,Ĭ�ϵ��޲ι��캯������ ������
			//���ǣ�Ĭ�ϵĹ��캯��ֻ�ᱻ ��ʾ�Ĺ��캯�� �� �ڸ�
{
	m_a = a;
}

A::~A()//ֻ���ṩһ����ʾ�Ĺ��캯�����ŻὫĬ�ϵ� �������� ����
{
}



void main()
{
	//A  obj;//���㲻�ṩ�κι��캯����ʱ��ϵͳ����һ��Ĭ�ϵĹ��캯��
	A obj2 = obj; // ������obj2�� Ĭ�ϵĿ�������
	//A obj2(obj);

	system("pause");
}