#include<iostream>
using namespace std;
//��C�����У�ֵ��0Ϊ�棬����������

void test() {
	bool flag = true;
	cout << "bool���͵��ڴ��ֽڴ�С�� " << sizeof(flag) << endl;//1���ֽڣ�8��λ��0-255
	cout << "flag = " << flag << endl;//flagΪ���ʱ����� 1
	flag = false;
	cout << "flag = " << flag << endl;//flagΪ�ٵ�ʱ����� 0

	flag = 100;
	cout << "flag = " << flag << endl;//flagΪ���ʱ����� 1

	flag = -100;
	cout << "flag = " << flag << endl;//��bool����0ʱ����ת��Ϊ 1��True
}





int main(void)
{	
	test();
	system("pause");
}