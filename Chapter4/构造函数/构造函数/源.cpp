#include<iostream>	
using namespace std;

class Test
{
public:
	//���캯��������û�з���ֵ���������ֺ� ��������һ��
	Test() {
		m_x = 10;
		m_y = 15;
	}

	//���캯������
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
	Test t1;//�����޲κ���
	t1.print();
	Test t2(20, 20);//���ع��캯�������� �вκ���
	t2.print();

	system("pause");
}