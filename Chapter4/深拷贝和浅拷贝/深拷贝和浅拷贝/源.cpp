#include<iostream>
#include<cstring>
using namespace std;

class Teacher
{
public:
	Teacher();
	Teacher(const Teacher& other);
	Teacher(int id,const char * name);
	void print();
	~Teacher();

private:
	int m_id;
	char *m_name;
};

Teacher::Teacher()
{
}

//深拷贝，不仅仅只是把 other的指针存放地址拷贝过来，而是将
//一个新的内存空间地址放入 other.m_name的内容
Teacher::Teacher(const Teacher & other)
{
	m_id = other.m_id;
	int len = strlen(other.m_name);
	m_name = (char*)malloc(len + 1);
	strcpy_s(m_name, len + 1, other.m_name);
}

Teacher::Teacher(int id, const char * name)
{
	cout << "调用了有参构造函数" << endl;
	m_id = id;

	int len = strlen(name);	//它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，
	//直到碰到第一个字符串结束符'\0'为止，然后返回计数器值。
	m_name = (char*)malloc(len + 1);//不能直接将 name的地址给 m_name,因为m_name还未分配内存空间
	strcpy_s(m_name,len+1,name);	
}

void Teacher::print()
{
	cout << "id : " << m_id ;
}

Teacher::~Teacher()
{
	//在构造函数中已经开辟内存了，为了防止泄露，在析构函数中，
	//在对象销毁之前，将m_name的内存释放掉
	if (m_name != NULL)
	{
		free(m_name);
		m_name = NULL;
		cout << "释放掉了m_name" << endl;
	}
}

void test1()
{
	Teacher t1(10, "wufan");
	//如果不提供一个显示的 拷贝构造函数，通过系统默认的 拷贝构造函数
	Teacher t2(t1);//在退出 test1时，将t2析构掉了，而 t2和t1的 m_name 都指向同一个地址，
			//因此，在析构t1时，t1的 m_name 已经被析构掉了
}

int main()
{
	test1();
	system("pause");
}