#include "pch.h"
#include <iostream>
using namespace std;

void myswap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(int &a, int &b)
{
	cout << "a = " << a << "  b = " << b << endl;
}

//对char类型交换
void myswap(char &x, char &y)
{
	char temp = x;
	x = y;
	y = temp;
}

void print(char &x, char &y)
{
	cout << "x = " << x << "  y = " <<y << endl;
}



int main()
{
	int a = 10, b = 20;
	myswap(a, b);
	print(a, b);

	char x = 's',y = 'd';
	myswap(x, y);
	print(x, y);
}

