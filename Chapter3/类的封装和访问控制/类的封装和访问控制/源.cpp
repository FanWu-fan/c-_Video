#include<iostream>
using namespace std;

//面对对象有三大特点：封装，继承，多态。

class MyDate
{
public://访问控制权限 //在public下定义的成员变量和成员函数都可以在 类的外部访问和看见
	int year;
	int month;
	int day;

	void init() {
		cout << "year,month,day,minutes" << endl;
		cin >> year;
		cin >> month;
		cin >> day	;
		cin >> minutes;
	}

	void printDate() {
		cout << "日期是：" << year << "年" << month << "月" << day << "日" << endl;
	}

	bool isLeapYear() {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void get_pri_min() {
		cout << "min " << minutes;
	}

protected:
	//如果是单个类，和private是一样的，在类的内部能够访问，在类的外部不能够访问
private://在private访问控制符下的定义的 成员变量和成员函数 只能在 类的内部访问。封装
	int minutes;
};

void t1() {
	MyDate data;//创建对象

	data.init();
	data.printDate();
	if (data.isLeapYear() == true) {
		cout << "这个是闰年" << endl;
	}
	else {
		cout << "这个不是闰年" << endl;
	}

	data.year = 10;//可以在外部直接修改 public的变量
	//data.minutes; 私有变量无法在外部修改

	data.get_pri_min();
}



void main() {
	//t1();
	

	


	system("pause");
}