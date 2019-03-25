#include<iostream>
#include"Circle.h"//引用.h文件用双引号 " "


using namespace std;

int main(void) {
	Circle c1;
	c1.setR(10.0);

	c1.getArea();
	c1.getGirth();
	system("pause");
}