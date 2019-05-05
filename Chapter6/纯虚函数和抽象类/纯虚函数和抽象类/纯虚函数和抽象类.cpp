#include "pch.h"
#include <iostream>
using namespace std;

//图像类
//拥有纯虚函数的类，称为 抽象类
class Shape
{
public:
	//是一个抽象的结构，说明图像是有一个得到面积的方法
	virtual double getArea() = 0;//这个等于0，代表了一个接口

	//打印接口
	virtual void print() = 0;

};

//圆类
//如果一个子类继承了抽象类，一定要重写这个纯虚函数
class Circle :public Shape
{
public:
	Circle(double r)
	{
		this->r = r;
	}
	virtual double getArea()
	{
		
		return 3.14*r*r;
	}
	virtual void print()
	{
		cout << "Circle Area: " << this->getArea() << endl;
	}
private:
	double r;
};
//实现一个正方形

class Rect :public Shape
{
public:
	Rect(double l)
	{
		this->l = l;
	}
	virtual double getArea()
	{
		return l*l;
	}
	virtual void print()
	{
		cout << "Rect Area: " << this->getArea() << endl;
	}
private:
	double l;
};


int main()
{
	//Shape p;//抽象类不能够实例化，子类继承于抽象类，一定要将纯虚函数重写。
	Shape *sp = new Circle(10);
	Shape *rp = new Rect(10);

	sp->print();//在这里发生了多态
	rp->print();//实现了面向 对象编程
}