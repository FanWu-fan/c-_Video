#include<iostream>
using namespace std;

void test1()
{
	const int a =10;	//c++的const确实对a起到了保护作用，不能通过指针赋值改变a的值
	//const int 和 int const 是等价的。
	int *p = (int*)&a;

	*p = 20;//在C语言中可以通过指针的间接赋值改变 const变量。C语言 漏洞
	cout << "a= " << a << endl;

}

#define A (3)
#define B (4)

void t2() {
	const int a = 6;
	int const b = 10;

	//数组类型的大小是固定的，不能使用变量，但是可以使用 const常量
	int array[a + b] = { 0 };
	int ss[A + B] = { 0 };//宏定义也是可以的

}






int main()
{
	test1();
	system("pause");
}