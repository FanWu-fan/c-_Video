#include "pch.h"
#include <iostream>
using namespace std;

class Goods
{
public:
	Goods()
	{
		next = NULL;
		weight = 0;
	}
	Goods(int w)
	{
		cout << "创建了一个货物重量是： " << w;
		next = NULL;
		weight = w;
		total_weight += w;
	}
	static int gettotal()
	{
		return total_weight;
	}
	//将
	Goods* next;

private:
	int weight;
	static int total_weight;
};

int Goods::total_weight = 0;



int main()
{
	int choice = 0;

	Goods *head = NULL; 
	while (1) 
	{
		cout << "1 进货" << endl;
		cout << "2 出货" << endl;
		cout << "0 退出" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "输出创建货物的重量:	" << endl;
			int w;

			break;
		case 2:
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}

	}

	return 0;
    
}


