#include<iostream>
using namespace std;

//inline是一个关键字，代表此函数是一个内联函数，放在函数返回值的前面
inline int my_func(int a, int b) {

	return (a < b ? a : b);
}




int main() {



	system("pause");
}