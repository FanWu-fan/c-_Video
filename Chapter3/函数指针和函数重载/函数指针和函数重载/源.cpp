#include<iostream>
using namespace std;

void func(int a, int b)
{
	cout << a <<","<< b << endl;
}

//1.������һ����������
typedef void(myfunctype)(int, int);//������һ���������ͣ�����ֵ��void,�����б���int,int

//2.������һ������ָ������
typedef void(*myfunctype_pointer)(int, int);//������һ������ָ������,����ֵ��void,�����б���int,int



int main()
{
	void(*fp)(int, int) = func;
	fp(10, 20);//10,20
	
	//����һ������ָ��
	myfunctype *fp1 = func;
	fp1(10, 20);

	myfunctype_pointer fp2 = func;
	fp2(10, 20);



	system("pause");
}