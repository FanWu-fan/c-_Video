#include<iostream>
using namespace std;
namespace spaceA	//namespace��ռ���κ��ڴ�ռ䣬���ᶨ�������
{
	int a = 10;
	int b = 20;
}

namespace spaceB//����Ĭ�ϵ�ȫ�������������ռ��һ�� �ӿռ�
{
	int a = 40;
	namespace spaceC
	{
		struct Teacher
		{
			char name[64];
			int id;
		};
	}
}

void test(void) {
	
	using spaceA::a;
	//using spaceB::a;//����ʾ���������ֻ������һ��
	cout << "A:a = " << spaceA::a << endl;//10
	cout << "B:a= " << spaceB::a << endl;//20
	cout << "ȫ�ֵ�a:	" << a << endl;//10

	//����һ�� struct teacher�ı���
	//using namespace spaceB::spaceC;//��Ƕ�׵�������Cȫ���������
	//using spaceB::spaceC::Teacher;
	//Teacher wang;
	spaceB::spaceC::Teacher wang;
}

void t2(void) {
	int i = 10;

	for (int i = 0; i < 5; i++) {//���i������forѭ�����棬�������ں�forѭ��һ��
		int temp;
		cout << "ѭ��i��" << i<<endl;
	}
	cout << i;
}



int a = 60;//����Ĭ�ϵ�ȫ�������������ռ�
int main(void) {
	//using namespace spaceB;
	//��ʱ����������������Ϊϵͳ��֪����60����40
	//test();
	//cout << "��������a: " << a << endl;

	t2();
	system("pause");
}