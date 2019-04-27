#include "pch.h"
#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void printP()
	{
		cout << "x= " << x << " y= " << y << endl;
	}
	int getx()
	{
		return this->x;
	}
	int gety()
	{
		return this->y;
	}

	//1. 声明一个全局函数友元函数，可以访问 私有变量
	friend double PointDistance2(Point &p1, Point &p2);
	

private:
	//friend double PointDistance2(Point &p1, Point &p2);//友元函数，可以访问 私有变量写 public和 private都可以

	int x;
	int y;
};

//1.通过全局方式写一个 两点之间的距离
double PointDistance(Point &p1, Point &p2)
{
	int ddx = p1.getx() - p2.getx();
	int ddy = p1.gety() - p2.gety();
	return sqrt(ddx*ddx + ddy * ddy);
}

//2.通过友元来写，友元以后，可以访问私有变量
double PointDistance2(Point &p1, Point &p2)
{
	int ddx = p1.x- p2.x;
	int ddy = p1.y - p2.y;
	return sqrt(ddx*ddx + ddy * ddy);
}


int main()
{
	Point p1(10, 20);
	Point p2(20,10);
	cout << "Distance: " << PointDistance(p1, p2) << endl;
	cout << "Distance2: " << PointDistance2(p1, p2) << endl;
}

