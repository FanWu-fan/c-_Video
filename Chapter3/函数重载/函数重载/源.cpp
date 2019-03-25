#include<iostream>
using namespace std;

//决定一个函数的特征： 1.返回值 2.参数列表

//void (*fp)(int)
void func(int a) {
	cout << "func1 : " << endl;
	cout << a << endl;
}

//函数重载，就是对参数列表的 变换 不是函数返回值的 变化
//参数列表不同，并且函数名相同的函数都是 重载函数
//函数重载最好不要有默认参数

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
	//定义一个指向 void func(int a)的函数指针
	void(*fp)(int) = func;//fp就是执行 void()(int)这种函数类型的指针
	fp(10);//调用函数 func
	func(20);
	func(10, 20);
	c=func(10, 20, 30);
	cout << c;

	system("pause");
}
