#include "Circle.h"
#include<iostream>
using namespace std;
//��.cpp�ж��庯���� ����


void Circle::setR(double r)
{	//��������Ȼ�� Circle����ڲ�
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