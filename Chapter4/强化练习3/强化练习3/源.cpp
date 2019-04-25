#include<iostream>
using namespace std;

//构造中调用构造是危险的行为

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
		MyTest(a, b, 100);//这个是匿名临时对象
		//直接被释放了

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