#include<iostream>
using namespace std;
//在C语言中，值非0为真，无论正负。

void test() {
	bool flag = true;
	cout << "bool类型的内存字节大小： " << sizeof(flag) << endl;//1个字节，8个位，0-255
	cout << "flag = " << flag << endl;//flag为真的时候等于 1
	flag = false;
	cout << "flag = " << flag << endl;//flag为假的时候等于 0

	flag = 100;
	cout << "flag = " << flag << endl;//flag为真的时候等于 1

	flag = -100;
	cout << "flag = " << flag << endl;//给bool赋非0时，都转化为 1，True
}





int main(void)
{	
	test();
	system("pause");
}