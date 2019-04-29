#include "pch.h"
#include <iostream>
#include <memory>

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
	unique_ptr <A>  auto_p (new A);
	auto_p->func();




	//A *ap = new A;
	//ap->func();
	//delete ap;
	//return 0;

}
