#include<iostream>
using namespace std;

void t1() {
	const int a = 10;//const���������ʼ��
	//int &b = a;//������Ϸ���������ԣ���ôb���ı䳣��a��ֵ��
	int const &b = a;//������const������ ����
}





int main() {

	const int x = 20;

	//int &p = 10;//�����޷���һ�� ��������������û�� �ڴ��ַ��
	const int &p = 10;//���Զ�����һ����ʱ���� temp��temp =10��ʵ���� 10�Ѿ���ʧ��
	cout << "p: " << p << " ,&p " << &p << endl;



	system("pause");
}