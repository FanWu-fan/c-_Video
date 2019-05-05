#include "pch.h"
#include <iostream>
using namespace std;

class B { public: int b; };
class B1 : public B { private: int b1; };
class B2 : public B { private: int b2; };
class C :public B1, public B2
{
public:int f() {} private:int d;
};


int main()
{
	C c;
	c.B::b;
	c.B1::B::b;
	c.B1::b;

}

