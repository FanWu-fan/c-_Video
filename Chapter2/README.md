# Chapter2 C++对C语言的加强
## 1.1 namespace的用法
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
## 1.2 **定义自己的namespace空间**
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

## 1.3 逻辑bool类型的增强
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

## 1.4 C++对三目运算符的增强
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

## 1.5 C++对 CONST的增强
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

## 1.6 const常量指针和指针常量
* const int *p 或 int const *p: **常量的指针**，表示该指针中存放的是 **常量的地址**，这个常量是指针的值（**地址**），而不是地址指向的值。常量的指针不能修改指向的值。即 *p 不能修改。
* int * const p :p本身不能修改，但是*p可以修改
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
const相对于 define:
* define没有区域划分，是预处理器处理
* const是编译器处理，完全符合逻辑判断和词法分析

## 1.7 引用
**变量名**：
* 变量名实质上是一段连续存储空间的别名，是一个标号(门牌号)
* 通过变量来申请并命名内存空间
* 通过变量的名字可以使用存储空间

**引用**：
* 引用的语法：*Type &name = var*
  
```C++
int main() {
	int a=10;//在内存上开辟了4个字节，a就代表这4个字节内存
	int *p = &a;//让一个指针去指向这4个字节的空间
	*p = 20;//改变指向的值

	//C++提供了“引用”来对变量的间接操作

	int &b = a;//定义一个引用 b去指向a，b此时就是变量a的别名

	b = 40;//a也变为了 40

	system("pause");
}
```
* 引用没有定义，是一种关系型的声明。声明它和原有某一变量(实体)的关系，故而 **类型**与原类型保持 **一致**。而且 **不分配内存**(函数传参利用 **引用**，可以减少内存消耗)。与被引用的变量具有相同的 地址。
* 声明的时候必须 **初始化**，一经声明，不可变更。
* 可对引用再次引用，多次引用的结果是，某一变量具有多个别名。
* **&** 符号前有**数据类型**时，是引用，其余皆为 **取地址**。
```C++
//利用 引用 当函数入口，节省内存。直接改变实参
void pA(int a) {
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
}


// 用引用传入的参数，指向同一个内存块地址，可以节省内存，同时改变实参的数值，
void pB(int &b2) {
	cout << "b2: " << b2 << endl;
	cout << "&b2: " << &b2 << endl;
	b2 = 50;
}
```

```C++
void pT(Teacher t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;//这里不能修改 t1的值。
}

void pT2(Teacher &t) {

	cout << "id = " << t.id << endl;
	cout << "name = " << t.name << endl;
	cout << "num = " << t.num << endl;
	t.id = 200;//这里利用 引用 可以修改传进来的值
}

void t2() {
	Teacher t1 = { 3,"wufan",20 };
	pT(t1);
	cout << "id = " << t1.id << endl;//3

	pT2(t1);
	cout << "id = " << t1.id << endl;//200

}
```
## 1.8 引用的本质
* 在C++内部，**引用** 就是 **常指针**：*Type & name <===> Type\* const name*
* C++在编译过程中使用 **常指针** 作为引用的内部实现，因此 引用所占内存空间和指针一样大。

## 1.9 引用作为函数的返回值
* 函数返回值是一个引用时，禁止用 **引用** 接受，会将局部变量的地址引用出来，会出BUG.
* 当引用作为函数的返回值时，如果不是局部变量(static)。是可以作为 **左值**。
```C++
int getA()
{
	int a = 10;
	return a;
}

int &getB() {
	int a = 20;
	cout << "getB的a的地址： " << &a << endl;
	return a;
	
}//返回值的类型是 int & 是引用


int main() {
	int value_a = 0;
	int value_b = 0;

	value_a = getA();//正确
	cout << "valuse_a: " << value_a << endl;

	value_b = getB();
	cout << "valuse_b: " << value_b << endl;//正确，是值拷贝
	cout << "&valuse_b: " << &value_b << endl;

	int &r_a = getB();
	//这个没有值拷贝的动作，将局部变量的别名拷贝出来了。错误
	cout << "r_a: " << r_a << endl;
	cout << "&r_a: " << &r_a << endl;

	system("pause");
}

输出：
valuse_a: 10

getB的a的地址： 008FFB54
valuse_b: 20
&valuse_b: 008FFC44

getB的a的地址： 008FFB54
r_a: 20
&r_a: 008FFB54
```

## 2.0 指针引用
二级指针作为函数参数的作用:在函数外部定义一个指针p，在函数内给指针赋值，函数结束后对指针p生效，那么我们就需要二级指针。

看看下面一段代码：有两个变量a,b,指针q,q指向a，我们想让q指向b,在函数里面实现。
```C++

void func(int *p) {
	cout << "func:&p=" << &p << ",p=" << p << endl;  //note:3
	p = &b;
	cout<<"func:&p="<<&p<<",p="<<p<<endl;  //note:4
}


int main(void) {
	cout << "&a=" << &a << ",&b=" << &b << ",&q=" << &q << endl;  //note:1
	q = &a;
	cout << "*q=" << *q << ",q=" << q << ",&q=" << &q << endl;  //note:2
	func(q);

	cout << "func-->*q=" << *q << ",q=" << q << ",&q=" << &q << endl;  //note:5

	system("pause");
}

输出：
&a=010FC000,&b=010FC004,&q_out_out=010FC148
*q_out=10,q_out=010FC000,&q_out=010FC148
func:&p=00B5F668,p=010FC000

函数里面的p_out指向和q指向一样都是a，但是q传入函数时，&p != &q_out
func:&p=00B5F668,p=010FC004
func-->*q_out=10,q_out=010FC000,&q_out=010FC148
```
编译器总是要为函数的每个参数制作临时副本，指针参数p的副本是 p，编译器使 p = q(但是&p != &q,也就是他们并不在同一块内存地址，只是他们的内容一样，都是a的地址)。如果函数体内的程序修改了p的内容(比如在这里它指向b)。在本例中，p申请了新的内存，只是把 p所指的内存地址改变了(变成了b的地址,但是q指向的内存地址没有影响)，所以在这里并不影响函数外的指针q。

```C++
//二级指针
int a = 10;
int b = 100;
int *q_out;

void func(int **p)  //2
{
	cout << "func:&p=" << &p << ",p=" << p << endl;
	*p = &b;  //3
	cout << "func:&p=" << &p << ",p=" << p << endl;
}


int main()
{
	cout << "&a=" << &a << ",&b=" << &b << ",&q_out=" << &q_out << endl;
	q_out = &a;
	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;
	func(&q_out);  //1
	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;

	system("pause");
	return 0;
}

输出：
&a=0130C000,&b=0130C004,&q_out=0130C148
*q_out=10,q_out=0130C000,&q_out=0130C148
这里的p里面存放的是 q的地址。
func:&p=004FFA64,p=0130C148
func:&p=004FFA64,p=0130C148
*q_out=100,q_out=0130C004,&q_out=0130C148
```
利用引用，可以避免编译器为传入的参数制作 **临时副本**。
```C++
#include<iostream>
using namespace std;

//二级指针
int a = 10;
int b = 100;
int *q_out;


void func(int* &p)
{
	cout << "func:&p=" << &p << ",p=" << p << endl;
	p = &b;
	cout << "func:&p=" << &p << ",p=" << p << endl;
}

int main() {
	cout << "&a=" << &a << ",&b=" << &b << ",&q_out=" << &q_out << endl;
	q_out = &a;
	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;
	func(q_out);

	cout << "*q_out=" << *q_out << ",q_out=" << q_out << ",&q_out=" << &q_out << endl;

	system("pause");
}

输出：
&a=00C1C000,&b=00C1C004,&q_out=00C1C148
*q_out=10,q_out=00C1C000,&q_out=00C1C148
func:&p=00C1C148,p=00C1C000

可以看见函数里面的指针 P的地址和 q_out一样，就是别名。
func:&p=00C1C148,p=00C1C004
*q_out=100,q_out=00C1C004,&q_out=00C1C148
```
## 2.1 const引用
* const对象的引用必须是 **const** 的，将普通引用绑定到const对象是不合法的。
```C++
void t1() {
	const int a = 10;//const变量必须初始化
	//int &b = a;//这个不合法，如果可以，那么b将改变常量a的值。
	int const &b = a;//可以用const引用来 引用
}
```
* 一般const引用用于接受形参，防止被改变
```C++
void func(const int &p)//p是不能被改变的。
{

}
```





