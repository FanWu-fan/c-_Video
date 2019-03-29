#pragma once
#include<cmath>
class Point
{
public:
	double distance(Point &p2) {
		return sqrt((x-p2.x)* (x - p2.x) + (y - p2.y)*(y-p2.y));
	}
	void setx_y(double i,double j) {
		x = i;
		y = j;
	}
	
private:
	double x, y;

};

