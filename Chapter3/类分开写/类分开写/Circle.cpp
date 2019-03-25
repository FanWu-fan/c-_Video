#include "Circle.h"
#include<iostream>
using namespace std;
//在.cpp中定义函数的 内容


void Circle::setR(double r)
{	//这里面依然是 Circle类的内部
	m_r = r;
}

void Circle::getR()
{
	cout << m_r << endl;
}

void Circle::getArea() {
	cout << m_r * m_r*3.14 << endl;
}

void Circle::getGirth() {
	cout << 2 * 3.14*m_r << endl;
}