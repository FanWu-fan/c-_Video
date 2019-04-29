#include "pch.h"
#include <iostream>

using namespace std;


class A
{
private:
public:
	A()
	{
		cout << "调用了无参构造函数" << endl;
	}
	~A()
	{
		cout << "调用了 析构 函数" << endl;
	}
	void func()
	{
		cout << "func-------" << endl;
	}
};





int main()
{
	shared_ptr <A> ps(new A);
	shared_ptr <A> ss;
	ss = ps;

	//A *ap = new A;
	//ap->func();
	//delete ap;
	//return 0;

}
