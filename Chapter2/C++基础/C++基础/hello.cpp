
#if 0
#include<stdio.h>

int main(void) {
	int a = 0;
	printf("hello word");
	
	return 0;
}
//#endif 

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



//#endif



#include<iostream>
using namespace std;

int main(void) {
	cout << "I am fine" << endl;
	int a = 2;
	cin >> a;
	cout << "a= " << a << endl;

	system("pause");
	return 0;

}
//#endif

#include<iostream>
using std::cout;//using关键字可以引用命名空间的变量
using std::cin;
using std::endl;

int main(void) {
	cout << "hello my " << endl;
	system("pause");
}
#endif

