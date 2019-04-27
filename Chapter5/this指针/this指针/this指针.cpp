#include "pch.h"
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int i)
	{
		this->mI = i;
	}
	int Change() const//在成员函数后面加const修饰的是隐藏的this指针，让this成为（const Test * const this）
	{
		//this++;this是常指针不能修改本身，(Test *const this)
		//this->mI = 0;

	}
private:
	int mI;
};
int main()
{
    
}


