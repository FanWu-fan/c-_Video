# Chapter8 类型转换
C++的类型转换
* static_cast 静态类型转换
* reinterpreter_cast 重新解释类型转换
* dynamic_cast 子类和父类之间的多态类型转换
* const_cast 去掉const属性转换

static_cast 静态类型转换
> static_cast<目标类型> (标识符)
> 所谓的静态，即在编译期间内即可决定其类型的转换，用的也是最多的一种。
```C++
void test1()
{
	double dPi = 3.1415926;
	int num1 = int(dPi);	//c语言的 旧式类型转换
	int num2 = dPi;		//隐式类型转换

	//静态的类型转换
	//在编译的时候进行基本类型的转换，能代替C风格的类型转换 可以进行一部分检查
	int num3 = static_cast<int>(dPi); //C++的新式的类型转换运算符
	cout << "num1: " << num1 << " num2: " << num2 << " num3: " << num3 << endl;

}
```

dynamic_cast 子类和父类之间的多态类型转换
>dynamic_cast <目标类型> (标识符)
>用于动态中的父子类之间的强制转化
