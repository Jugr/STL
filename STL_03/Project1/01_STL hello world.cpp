#include<iostream>
#include<vector>//��̬���� �ɱ�����
#include<algorithm>
using namespace std;


void PrintV(int v) {
	cout << v << endl;
}

void test01() {

	//����һ������ ��ָ�����������ŵ�����������Int
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//ͨ��stl�ṩ��for_each
	//�����ṩ�ĵ�����
	//vector<int>::iterator ����������
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//�����п��ܴ�Ż����������ͣ�Ҳ���ܴ���Զ�����������
	for_each(pBegin, pEnd, PrintV);

}

//��������Զ�����������
class Person
{
public:
	Person(int age, int id) :age(age), id(id) {}
	
public:
	int age;
	int id;
private:

};

void test2() {
	//����������ָ��Ԫ������
	vector<Person> v;
	Person p1(1, 10), p2(2, 20), p3(3, 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).age << "  " << (*it).id << endl;
	}
}


int main1() {
	//test01();
	test2();

	return 0;
}

