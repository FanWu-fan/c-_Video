#include "pch.h"
#include <iostream>
using namespace std;

class c1
{
public:
	int i;//4
	int j;//4
	int k;//4
};//12


class c2
{
public:
	int i;
	int j;
	int k;
	static int m;  //4
public:
	int getK() const { return k; }	//4
	void setk(int val) { k = val; }//4
};

struct S1
{
	int i;
	int j;
	int k;
	
};//12

struct S2
{
	int i;
	int j;
	int k;
	static int m;
};//12

int main()
{
	cout << "c1: " << sizeof(c1) << endl;
	cout << "c2 : " << sizeof(c2) << endl;
	cout << "s1: " << sizeof(S1) << endl;
	cout << "s2: " << sizeof(S2) << endl;

}
