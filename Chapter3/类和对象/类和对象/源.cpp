#include<iostream>
using namespace std;

//����һ����Ĺؼ���
class Hero //����һ������
{
public:	//���ʿ��Ʒ� ����Ȩ��
	int sex;
	char name[64];

	//��Ա����,����pythonһ������Ҫʹ��self������
	void print() {
		cout << name << " , "<<sex << endl;
	}

private:

};


//����һ��������
class Animal
{
public: //����Ȩ�޵Ŀ��Ʒ�
	char color[64];
	char kind[64];

	//ӵ��д�ֵķ���
	void write() {
		cout << kind <<":"<< "��ʼд��" << endl;

	}

	//ӵ���ܲ�������
	void run() {
		cout << kind <<":"<< "�ܲ���" << endl;
	}


private:

};

void main()
{	
	Hero wufan;//ͨ�� �ഴ��һ������
	wufan.sex=1;
	char ss[10] = "wufandas";
	strcpy_s(wufan.name, "wufanlalala");

	wufan.print();

	Animal dog;
	Animal sheep;
	strcpy_s(dog.kind, "��");
	strcpy_s(dog.color, "��ɫ");

	dog.run();
	dog.write();


	system("pause");
}