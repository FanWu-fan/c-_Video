#include<iostream>
using namespace std;

void test() {
	int a = 10;
	int b = 20;

	int min = 0;
	min = (a < b ? a : b);
	cout << "min " << min << endl;//10

	//在C++中，三目运算符可以作为左值
	(a < b ? a : b) = 30;//这里实际上返回的是a,可以改变a的值
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//20

	//在C语言中利用取地址来实现,在C++中实际上是 通过 别名来实现，
	*(a < b ? &a : &b) = 40;//返回的是地址，然后进行取 * 操作
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//40


}




int main()
{
	test();
	system("pause");
}