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

//�����������ֻ�ǰ� other��ָ���ŵ�ַ�������������ǽ�
//һ���µ��ڴ�ռ��ַ���� other.m_name������
Teacher::Teacher(const Teacher & other)
{
	m_id = other.m_id;
	int len = strlen(other.m_name);
	m_name = (char*)malloc(len + 1);
	strcpy_s(m_name, len + 1, other.m_name);
}

Teacher::Teacher(int id, const char * name)
{
	cout << "�������вι��캯��" << endl;
	m_id = id;

	int len = strlen(name);	//�����ڴ��ĳ��λ�ã��������ַ�����ͷ���м�ĳ��λ�ã�������ĳ����ȷ�����ڴ����򣩿�ʼɨ�裬
	//ֱ��������һ���ַ���������'\0'Ϊֹ��Ȼ�󷵻ؼ�����ֵ��
	m_name = (char*)malloc(len + 1);//����ֱ�ӽ� name�ĵ�ַ�� m_name,��Ϊm_name��δ�����ڴ�ռ�
	strcpy_s(m_name,len+1,name);	
}

void Teacher::print()
{
	cout << "id : " << m_id ;
}

Teacher::~Teacher()
{
	//�ڹ��캯�����Ѿ������ڴ��ˣ�Ϊ�˷�ֹй¶�������������У�
	//�ڶ�������֮ǰ����m_name���ڴ��ͷŵ�
	if (m_name != NULL)
	{
		free(m_name);
		m_name = NULL;
		cout << "�ͷŵ���m_name" << endl;
	}
}

void test1()
{
	Teacher t1(10, "wufan");
	//������ṩһ����ʾ�� �������캯����ͨ��ϵͳĬ�ϵ� �������캯��
	Teacher t2(t1);//���˳� test1ʱ����t2�������ˣ��� t2��t1�� m_name ��ָ��ͬһ����ַ��
			//��ˣ�������t1ʱ��t1�� m_name �Ѿ�����������
}

int main()
{
	test1();
	system("pause");
}