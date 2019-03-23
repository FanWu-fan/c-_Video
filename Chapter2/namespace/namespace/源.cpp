#include<iostream>
using namespace std;
namespace spaceA	//namespace不占用任何内存空间，不会定义变量，
{
	int a = 10;
	int b = 20;
}

namespace spaceB//属于默认的全局作用域命名空间的一个 子空间
{
	int a = 40;
	namespace spaceC
	{
		struct Teacher
		{
			char name[64];
			int id;
		};
	}
}

void test(void) {
	
	using spaceA::a;
	//using spaceB::a;//会显示多次声明，只能声明一次
	cout << "A:a = " << spaceA::a << endl;//10
	cout << "B:a= " << spaceB::a << endl;//20
	cout << "全局的a:	" << a << endl;//10

	//创建一个 struct teacher的变量
	//using namespace spaceB::spaceC;//将嵌套的作用域C全部引入进来
	//using spaceB::spaceC::Teacher;
	//Teacher wang;
	spaceB::spaceC::Teacher wang;
}

void t2(void) {
	int i = 10;

	for (int i = 0; i < 5; i++) {//这个i定义在for循环里面，生命周期和for循环一致
		int temp;
		cout << "循环i：" << i<<endl;
	}
	cout << i;
}



int a = 60;//属于默认的全局作用域命名空间
int main(void) {
	//using namespace spaceB;
	//此时加了这个，会出错，因为系统不知道是60还是40
	//test();
	//cout << "主函数的a: " << a << endl;

	t2();
	system("pause");
}