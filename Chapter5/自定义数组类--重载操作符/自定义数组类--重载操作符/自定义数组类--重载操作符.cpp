#include "pch.h"
#include <iostream>
using namespace std;


class Myarray
{
public:
	friend ostream & operator<<(ostream & os, const Myarray &array);
	

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
	//实现操作符重载[]取值,返回引用可以直接修改值
	int &operator[](int index) const //array[i]是取值。array[i]=10是赋值,
		//这个const修饰的是 (const Myarray *this,int index)
	{
		return this->space[index];
	}
	//实现等号操作符的重载
	Myarray & operator=(const Myarray &other)
	{
		this->length = other.length;
		if (this->space)
		{
			delete[] this->space;
			this->space = NULL;
		}
		this->space = new int[this->length];
		for (int i = 0; i < this->length; i++)
			this->space[i] = other.space[i];
		return *this;
	}
	//重载双等号操作符 ==
	bool operator==(const Myarray & other)
	{
		if (this->length == other.length) 
		{
			for (int i = 0; i < this->length; i++)
			{
				if (this->space[i] != other.space[i])
					return false;
			}
			return true;

		}

		return false;

	}



	////实现重载左移操作符,这个不能写在成员函数里面
	//ostream & operator <<(ostream &os)
	//{
	//	for (int i = 0; i < this->length;i++)
	//	{
	//		os << this->space[i] << endl;
	//	}
	//	return os;
	//}


	Myarray(const Myarray &another)
	{
		cout << "使用了拷贝构造函数" << endl;
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

ostream & operator<<(ostream & os, const Myarray &array)
{
	os << "遍历了整个数组" << endl;
	for (int i = 0; i < array.length; i++)
	{
		os << array[i] << endl;//这个同时也要变为 const
		//array.operator[]（&array,i)
	}
	return os;
}



int main()
{
	Myarray array(10);//调用有参构造函数

	for (int i = 0; i < array.Myarraygetlen(); i++)
	{
		//array.setData(i, i + 10);
		array[i] = i+100;
	}

	cout << array[4] << endl;//取值
	//array.operator<<(cout);
	cout<<array;//cout不能写在


	cout << "---以下是拷贝构造函数的测试----" << endl;
	Myarray array2 = array;//这里将使用拷贝构造函数
	array2.printf();

	cout << "---以下是等号操作符的重载的测试----" << endl;
	Myarray array4;
	array4 = array2;
	cout << array4;

	cout << "---以下是双等号 == 重载的测试----" << endl;
	if (array4 == array2)
		cout << "array4 == array2" << endl;

}