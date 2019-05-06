#include "pch.h"
#include <iostream>
using namespace std;

void test1()
{
	double dPi = 3.1415926;
	int num1 = int(dPi);	//c语言的 旧式类型转换
	int num2 = dPi;		//隐式类型转换

	//静态的类型转换
	//在编译的时候进行基本类型的转换，能代替C风格的类型转换 可以进行一部分检查
	int num3 = static_cast<int>(dPi); //C++的新式的类型转换运算符
	cout << "num1: " << num1 << " num2: " << num2 << " num3: " << num3 << endl;

}

void test2()
{


}



int main()
{
	test1();
   
}

