// 等号操作符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

class Student
{
public:
	Student(int id,string name)
	{
		this->id = id;
		this->name = name;

	}
	~Student()
	{
		if (this->name)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}

	void Prints()
	{
		cout << "id: " << id << "  name: " << this->name << endl;
	}
private:
	int id;
	string name;
};




int main()
{
	Student s1(1, "zhangsan");
	s1.Prints();


}

