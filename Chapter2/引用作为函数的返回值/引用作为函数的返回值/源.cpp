#include<iostream>
using namespace std;

int getA()
{
	int a = 10;
	return a;
}

int &getB() {
	int a = 20;
	cout << "getB��a�ĵ�ַ�� " << &a << endl;
	return a;
	
}//����ֵ�������� int & ������


int main() {
	int value_a = 0;
	int value_b = 0;

	value_a = getA();//��ȷ
	cout << "valuse_a: " << value_a << endl;

	value_b = getB();
	cout << "valuse_b: " << value_b << endl;//��ȷ����ֵ����
	cout << "&valuse_b: " << &value_b << endl;

	int &r_a = getB();
	//���û��ֵ�����Ķ��������ֲ������ı��������ˡ�����
	cout << "r_a: " << r_a << endl;
	cout << "r_a: " << r_a << endl;//�ٴ�����������Ϊ�ֲ������Ѿ�������
	cout << "&r_a: " << &r_a << endl;

	system("pause");
}