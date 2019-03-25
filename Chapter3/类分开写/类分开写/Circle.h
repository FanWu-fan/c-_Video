#pragma once
/*
#pragma one 
和下面的语句一样的作用,保证头文件只被引用一次，
防止重复定义

#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#endif
*/
//.H文件作用是 声明
//原类
class Circle
{
public:
	void setR(double r);
	void getR();

	void getArea();
	 void getGirth();

private:
	double m_r;
};

