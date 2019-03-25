#include<iostream>
using namespace std;

class Circle
{
public:
	
	void setr(int r) {
		m_r = r;
	}
	void getr() {
		cout << m_r << endl;
	}
	void getArea() {
		cout << Area << endl;
	}
private:
	int m_r;
	//2.在通过setr()设置m_r,以后，Area不会再次计算
	int Area = m_r * m_r*3.14;

};


int main() {
	Circle one;
	one.setr(10);
	one.getArea();
	one.getr();

	system("pause");
}