#include "pch.h"
#include <iostream>
using namespace std;


class Myarray
{
public:
	Myarray()
	{
		this->space = NULL;
		this->length = 0;
	}

	Myarray(int len)//开辟长度为 len的空间
	{
		if (len <= 0)
		{
			this->length = 0;
			return;
		}
		else
		{
			this->length = len;
			this->space = new int[this->length];//在堆上开辟了 长度为length的连续int 空间
			cout << "数组的构造函数被调用了" << endl;
		}
	}

	Myarray(const Myarray &another)
	{
		if (another.length >= 0)
		{
			this->length = another.length;
			this->space = new int[this->length];
			for (int i = 0; i < this->length; i++)
			{
				this->space[i] = another.space[i];
			}
		}
	}

	~Myarray()
	{
		cout << "执行析构函数" << endl;
		if (this->space)
		{
			delete[] this->space;
			this->length = 0;
			this->space = NULL;
		}

	}
	int Myarraygetlen()
	{
		return this->length;
	}

	void setData(int index, int value)
	{
		if (this->space)
		this->space[index] = value;
	}

	void printf()
	{
		for (int i = 0; i < this->length; i++)
			cout << this->space[i] << " ," << endl;
	}

private:
	int *space; //space在堆上开辟数组空间的首元素地址
	int length;

};

int main()
{
	Myarray array(10);//调用有参构造函数

	for (int i = 0; i < array.Myarraygetlen(); i++)
	{
		array.setData(i, i + 10);
	}

	array.printf(); 

	cout << "---一下是拷贝构造函数的测试----" << endl;
	Myarray array2 = array;
	array2.printf();
}

