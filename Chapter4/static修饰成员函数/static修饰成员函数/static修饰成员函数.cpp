#include"pch.h"
#include<iostream>
using namespace std;

class Student
{
public:
	Student(int num, double score)
	{
		this->m_num = num;
		this->m_score = score;
		count++;
		sum_score += score;
	}
	static double getAvg()
	{

		return sum_score / count;
		//cout << this->m_score << endl;this只能用于非静态成员函数内部
	}

private:
	int m_num;
	double m_score;
	static int count;
	static double sum_score;
};

int Student::count = 0;
double Student::sum_score = 0;

int main()
{
	Student s1(1, 100);
	Student s2(2, 90);
	Student s3(3, 80);
	cout << "AVG : " << Student::getAvg() << endl;//只有静态成员函数，才能不用与特定的对象相对，直接当成类的全局函数
	cout << "AVG : " << s2.getAvg() << endl;
	return 0;

}