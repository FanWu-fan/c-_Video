#include<iostream>
using namespace std;

//��Զ����������ص㣺��װ���̳У���̬��

class MyDate
{
public://���ʿ���Ȩ�� //��public�¶���ĳ�Ա�����ͳ�Ա������������ ����ⲿ���ʺͿ���
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
		cout << "�����ǣ�" << year << "��" << month << "��" << day << "��" << endl;
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
	//����ǵ����࣬��private��һ���ģ�������ڲ��ܹ����ʣ�������ⲿ���ܹ�����
private://��private���ʿ��Ʒ��µĶ���� ��Ա�����ͳ�Ա���� ֻ���� ����ڲ����ʡ���װ
	int minutes;
};

void t1() {
	MyDate data;//��������

	data.init();
	data.printDate();
	if (data.isLeapYear() == true) {
		cout << "���������" << endl;
	}
	else {
		cout << "�����������" << endl;
	}

	data.year = 10;//�������ⲿֱ���޸� public�ı���
	//data.minutes; ˽�б����޷����ⲿ�޸�

	data.get_pri_min();
}



void main() {
	//t1();
	

	


	system("pause");
}