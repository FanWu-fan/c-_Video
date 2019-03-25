#include<iostream>
using namespace std;

void func(int a, int b)
{
	cout << a <<","<< b << endl;
}

//1.定义了一个函数类型
typedef void(myfunctype)(int, int);//定义了一个函数类型，返回值是void,参数列表是int,int

//2.定义了一个函数指针类型
typedef void(*myfunctype_pointer)(int, int);//定义了一个函数指针类型,返回值是void,参数列表是int,int



int main()
{
	void(*fp)(int, int) = func;
	fp(10, 20);//10,20
	
	//定义一个函数指针
	myfunctype *fp1 = func;
	fp1(10, 20);

	myfunctype_pointer fp2 = func;
	fp2(10, 20);



	system("pause");
}