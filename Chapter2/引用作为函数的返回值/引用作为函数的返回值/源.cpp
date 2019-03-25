#include<iostream>
using namespace std;

int getA()
{
	int a = 10;
	return a;
}

int &getB() {
	int a = 20;
	cout << "getB的a的地址： " << &a << endl;
	return a;
	
}//返回值的类型是 int & 是引用


int main() {
	int value_a = 0;
	int value_b = 0;

	value_a = getA();//正确
	cout << "valuse_a: " << value_a << endl;

	value_b = getB();
	cout << "valuse_b: " << value_b << endl;//正确，是值拷贝
	cout << "&valuse_b: " << &value_b << endl;

	int &r_a = getB();
	//这个没有值拷贝的动作，将局部变量的别名出来了。错误
	cout << "r_a: " << r_a << endl;
	cout << "r_a: " << r_a << endl;//再次输出会出错，因为局部变量已经被覆盖
	cout << "&r_a: " << &r_a << endl;

	system("pause");
}