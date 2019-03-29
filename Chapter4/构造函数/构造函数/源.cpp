#include<iostream>	
using namespace std;

class Test
{
public:
	//构造函数，函数没有返回值，函数名字和 类型名字一样
	Test() {
		m_x = 10;
		m_y = 15;
	}

	//构造函数重载
	Test(int x,int y) {
		m_x = x;
		m_y = y;
	}
	void print() {
		cout << "m_x: " << m_x << "  m_y: " << m_y << endl;
	}

private:
	int m_x;
	int m_y;
};

int main() {
	Test t1;//调用无参函数
	t1.print();
	Test t2(20, 20);//重载构造函数，调用 有参函数
	t2.print();

	system("pause");
}