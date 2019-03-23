# Chapter2 C++对C语言的加强
## 2.1 namespace的用法
1. **使用 std::cin类型：**
```C++
#include<iostream>

int main(void) {
std::cout << "hello my dir" << std::endl;//将字符串流入到标准输出中。
			//	endl是为了加强跨平台的 \n回车作用

int a = 0;
std::cin>>a;
std::cout << "a= " << a << std::endl;

system("pause");
return 0;
}
```

2. **使用 using namespace std;**
```C++
#include<iostream>
using namespace std;//using namespace引入整个命名空间

int main(void) {
	cout << "I am fine" << endl;
	int a = 2;
	cin >> a;
	cout << "a= " << a << endl;

	system("pause");
	return 0;

}
```

3. **使用using std::cin;**
```C++
#include<iostream>
using std::cout;//using关键字可以引用命名空间的变量
using std::cin;
using std::endl;

int main(void) {
	cout << "hello my " << endl;
	system("pause");
}
```
## 2.2 **定义自己的namespace空间**
```C++
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

int a = 60;//属于默认的全局作用域命名空间
int main(void) {
	//using namespace spaceB;
    //此时加了这个，会出错，因为系统不知道是60还是40
	test();
	cout << "主函数的a: " << a << endl;
	system("pause");
}
```
* C语言的命名空间：在C语言中，就只有一个全局的作用域(main函数外面定义的变量都是全局作用域)，
* C++:在main函数之外的定义的变量可以利用 namespace 将全局作用域分成不同的部分。

## 2.3 逻辑bool类型的增强
```python
#include<iostream>
using namespace std;
//在C语言中，值非0为真，无论正负。

void test() {
	bool flag = true;
	cout << "bool类型的内存字节大小： " << sizeof(flag) << endl;
    //1个字节，8个位，0-255
	cout << "flag = " << flag << endl;//flag为真的时候等于 1
	flag = false;
	cout << "flag = " << flag << endl;//flag为假的时候等于 0

	flag = 100;
	cout << "flag = " << flag << endl;//flag为真的时候等于 1

	flag = -100;
	cout << "flag = " << flag << endl;
    //给bool赋非0时，都转化为 1，True
}

int main(void)
{	
	test();
	system("pause");
}
```

## 2.4 C++对三目运算符的增强
```C++
void test() {
	int a = 10;
	int b = 20;

	int min = 0;
	min = (a < b ? a : b);
	cout << "min " << min << endl;//10

	//在C++中，三目运算符可以作为左值
	(a < b ? a : b) = 30;//这里实际上返回的是a,可以改变a的值
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//20

	//在C语言中利用取地址来实现,在C++中实际上是 通过 别名来实现，
	*(a < b ? &a : &b) = 40;//返回的是地址，然后进行取 * 操作
	cout << "a: " << a << endl;//30
	cout << "b: " << b << endl;//40


}
```

## 2.5 C++对 CONST的增强
const是常量的意思，不可以被修改。实际上，在C++中，const就是真正意义上的常量，**没有开辟运行空间**。
* const修饰的常量a必须 **初始化**，因为在编译器检查的时候，const不在堆栈上 **开辟空间**，而是设置 **符号表**，**只读不可修改**，此时的a就是一个 **符号**。
* a是一个符号，是没有地址的，因此当C++发现对 const取地址时，会 **临时** 在栈上开辟一个空间，这个变量时 **匿名的**，将这个 匿名的变量 **取地址** 赋给 p.


```C++
void test1()
{
	const int a = 10;	
    //c++的const确实对a起到了保护作用，不能通过指针赋值改变a的值
	//const int 和 int const 是等价的。
	int *p = (int*)&a;//指向一个 临时变量temp
	*p = 20;//改变的是临时变量，而不是常量a的符号

    //在C语言中可以通过指针的间接赋值改变 const变量。C语言 漏洞
	cout << "a= " << a << endl;

}
---------------------------------------------------
#define A (3)
#define B (4)

void t2() {
	const int a = 6;
	int const b = 10;

	//数组类型的大小是固定的，不能使用变量，但是可以使用 const常量
	int array[a + b] = { 0 };
	int ss[A + B] = { 0 };//宏定义也是可以的

}
```

## const常量指针和指针常量
* const int *p 或 int const *p: **常量的指针**，表示该指针中存放的是 **常量的地址**，这个常量是指针的值（**地址**），而不是地址指向的值。常量的指针不能修改指向的值。即 *p 不能修改。
* int * const p :p本身不能修改，但是*P可以修改
```C++
void  test1() {
	const int value = 3;//常量
	int v = 5;
	int s = 10;
	const int *p = &v;//指向常量的指针
	//*p = 5;//不能修改 *p,但是可以修改 p
	p = &s;


	v = 6;//可以修改v

	int * const op = &v;
	*op = 10;
	//op = &s;//op本身不能修改，但是 *op可以修改
}
```
使用
```C++
struct Student
{
	int id;
	char name[64];
};

void change_stu(Student *s) {
	s->id = 10;//如果是指针就用 ->,如果是 对象，就用 .
}

void change_stu2(const Student *s) {
	//s->id = 20;
    //此时s所指向的区域是一个常量，即 *s 或 s->id 不能被修改
	Student s2;
	s = &s2;

	Student *s3;
	s = s3;
}

void change_stu3(Student * const s) {
	s->id = 10;
	Student s2;
	//s = &s2;//此时s不能被修改

	Student *s3;
	//s = s3;//此时s不能被修改
}

void change_stu4(const Student *const s) {
	//s->id = 10;
	//此时s所指向的区域是一个常量，即 *s 或 s->id 不能被修改

	Student s2;
	//s = &s2;//此时s不能被修改
}
```










