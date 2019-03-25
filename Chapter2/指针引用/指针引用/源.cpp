#include<iostream>
using namespace std;

//¶ş¼¶Ö¸Õë
int a = 10;
int b = 100;
int *q_out;


void func(int* &p)
{
	cout << "func:&p=" << &p << ",p=" << p << endl;
	p = &b;
	cout << "func:&p=" << &p << ",p=" << p << endl;
}

int main() {
	cout << "&a=" << &a << ",&b=" << &b << ",&q_out=" << &q_out << endl;
	q_out = &a;
	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;
	func(q_out);

	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;

	system("pause");
}