#include<iostream>
using namespace std;

//����һ�������������� 1.����ֵ 2.�����б�

//void (*fp)(int)
void func(int a) {
	cout << "func1 : " << endl;
	cout << a << endl;
}

//�������أ����ǶԲ����б�� �任 ���Ǻ�������ֵ�� �仯
//�����б�ͬ�����Һ�������ͬ�ĺ������� ���غ���
//����������ò�Ҫ��Ĭ�ϲ���

char func(int a, int b) {
	cout << "func2 : " << endl;
	cout << a <<","<< b << endl;
	return 'd';
}

int func(int a, int b,int c) {
	cout << "func3 : " << endl;
	cout << a << "," << b << ","<<c<<endl;
	return a;
}


int main()
{
	int c = 0;
	//����һ��ָ�� void func(int a)�ĺ���ָ��
	void(*fp)(int) = func;//fp����ִ�� void()(int)���ֺ������͵�ָ��
	fp(10);//���ú��� func
	func(20);
	func(10, 20);
	c=func(10, 20, 30);
	cout << c;

	system("pause");
}
