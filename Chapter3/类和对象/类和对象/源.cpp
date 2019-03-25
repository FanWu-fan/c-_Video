#include<iostream>
using namespace std;

//定义一个类的关键字
class Hero //定义一个类名
{
public:	//访问控制符 访问权限
	int sex;
	char name[64];

	//成员函数,不像python一样，需要使用self来调用
	void print() {
		cout << name << " , "<<sex << endl;
	}

private:

};


//定义一个动物类
class Animal
{
public: //访问权限的控制符
	char color[64];
	char kind[64];

	//拥有写字的方法
	void write() {
		cout << kind <<":"<< "开始写作" << endl;

	}

	//拥有跑步法方法
	void run() {
		cout << kind <<":"<< "跑步了" << endl;
	}


private:

};

void main()
{	
	Hero wufan;//通过 类创建一个对象
	wufan.sex=1;
	char ss[10] = "wufandas";
	strcpy_s(wufan.name, "wufanlalala");

	wufan.print();

	Animal dog;
	Animal sheep;
	strcpy_s(dog.kind, "狗");
	strcpy_s(dog.color, "黄色");

	dog.run();
	dog.write();


	system("pause");
}