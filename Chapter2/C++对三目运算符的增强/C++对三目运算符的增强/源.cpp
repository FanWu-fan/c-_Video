#include<iostream>
using namespace std;

void test() {
	int a = 10;
	int b = 20;

	int min = 0;
	min = (a < b ? a : b);
	cout << "min " << min << endl;//10

	//��C++�У���Ŀ�����������Ϊ��ֵ
	(a < b ? a : b) = 30;//����ʵ���Ϸ��ص���a,���Ըı�a��ֵ
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//20

	//��C����������ȡ��ַ��ʵ��,��C++��ʵ������ ͨ�� ������ʵ�֣�
	*(a < b ? &a : &b) = 40;//���ص��ǵ�ַ��Ȼ�����ȡ * ����
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//40


}




int main()
{
	test();
	system("pause");
}