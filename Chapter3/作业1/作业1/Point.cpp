#include "Point.h"
#include<iostream>

using namespace std;

int main() {

	Point pa, pb;
	pa.setx_y(1, 1);
	pb.setx_y(2, 2);
	double dis;
	dis = pa.distance(pb);
	cout << dis << endl;
	system("pause");
}


