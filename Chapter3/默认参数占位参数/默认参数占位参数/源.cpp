#include<iostream>
using namespace std;

//Ĭ�ϲ���Ϊ100
void func1(int x,int) {
	cout << "func1: x " << x << endl;
}



int main() {
	int y = 10;
	func1(y,10);//10

	system("pause");
}