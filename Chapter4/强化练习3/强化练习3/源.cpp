#include<iostream>
using namespace std;

//�����е��ù�����Σ�յ���Ϊ

class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	MyTest(int a, int b)
	{
		_a = a;
		_b = b;
		//_c = 100;
		MyTest(a, b, 100);//�����������ʱ����
		//ֱ�ӱ��ͷ���

	}
	~MyTest()
	{
		cout << "MyTest~:" << _a << ", " << _b << ", " << _c << endl;
	}

	int getC()
	{
		return this->_c;
	}

	void setC(int val)
	{
		_c = val;
	}
private:
	int _a;
	int _b;
	int _c;

};

void test1()
{
	MyTest t1(1, 2);
	cout << "c: " << t1.getC() << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}