#include<iostream>
using namespace std;

void test1()
{
	const int a =10;	//c++��constȷʵ��a���˱������ã�����ͨ��ָ�븳ֵ�ı�a��ֵ
	//const int �� int const �ǵȼ۵ġ�
	int *p = (int*)&a;

	*p = 20;//��C�����п���ͨ��ָ��ļ�Ӹ�ֵ�ı� const������C���� ©��
	cout << "a= " << a << endl;

}

#define A (3)
#define B (4)

void t2() {
	const int a = 6;
	int const b = 10;

	//�������͵Ĵ�С�ǹ̶��ģ�����ʹ�ñ��������ǿ���ʹ�� const����
	int array[a + b] = { 0 };
	int ss[A + B] = { 0 };//�궨��Ҳ�ǿ��Ե�

}






int main()
{
	test1();
	system("pause");
}