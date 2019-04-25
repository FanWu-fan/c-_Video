#include<iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
		cout << "ADBC() construct, a: " << _a << " b: " << _b << " c: " << _c << endl;
	}
	~ABCD()
	{
		cout << "~ADBC() construct, a: " << _a << " b: " << _b << " c: " << _c << endl;
	}
	int getA()
	{
		return _a;
	}

private:
	int _a;
	int _b;
	int _c;
};

class MyE
{
public:
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout << "MyD()" << endl;
	}
	~MyE()
	{
		cout << "~MtD()" << endl;
	}
	MyE(const MyE & obj) :abcd2(10, 11, 12), abcd1(7, 8, 9), m(100)// ��ʼ����Ա�������ʼ��˳���޹أ�ֻ�Ͷ����˳���й�
	{
		cout << "MyD(const MyE &obj)" << endl;
	}



public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};

int doThing(MyE mye1)//�ֲ������� ʹ�ÿ������캯��
{
	cout << "doThing() mye1.abc1.a: " << mye1.abcd1.getA() << endl;//���ڿ���������ԭ�����ﲻ�����1�������7
	return 0;
}
int run()
{
	MyE mye;
	doThing(mye);//�������� ��Ŀ�������
	return 0;
}

int run2()
{
	cout << "run2 start.." << endl;
	//ABCD(400, 500, 600);//��ʱ������������ڣ�����������������ʱ������������������٣����ȵ������ĺ����������
	//�����Ժ�Ϳ�ʼ����
	ABCD abcd = ABCD(100, 200, 300);//����������������Ժ󣬲���ͨ�� �������캯�������ݣ�����ֱ��ȡ ����������ֻ��һ�ι���
	//������run2�����Ժ�� ���� ����

	cout << "run2 end" << endl;
	return 0;
}

int main()
{
	//run();
	run2();
	system("pause");
	return 0;
}