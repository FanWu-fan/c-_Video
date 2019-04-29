// 等号操作符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
#if 0
class Student
{
public:
	Student(int id, const char *name)
	{
		this->id = id;
		this->name =  new char[strlen(name)+1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	//提供一个深拷贝，防止浅拷贝
	Student(const Student & other)
	{
		this->id = other.id;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
	}

	//重写等号 操作符，返回引用实现 连等
	Student & operator=(const Student & other)
	{
		if (this->name)
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}//首先删除原值
		this->id = other.id;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		return *this;
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
	char *name;
};
#endif
//使用string来实现，可以不用析构，等号操作符重载
class Student
{
private:
	int id;
	string name;
public:
	Student(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
	void Prints()
	{
		cout << "id: " << this->id << "  name: " << this->name << endl;

	}
};





int main()
{
	Student s1(1, "zhangsan");
	Student s2(s1); //如果是浅拷贝会发生两遍对同一个内存地址 析构

	s1.Prints();

	Student s3(1, "lishi");
	s3 = s1;//这个是调用 等号 操作符,浅拷贝，因此要重载 等号操作符
	s3.Prints();
}

