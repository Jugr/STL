#include<iostream>
#include<vector>//动态数组 可变数组
#include<algorithm>
using namespace std;


void PrintV(int v) {
	cout << v << endl;
}

void test01() {

	//定义一个容器 并指定这个容器存放的数据类型是Int
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//通过stl提供的for_each
	//容器提供的迭代器
	//vector<int>::iterator 迭代器类型
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//容器中可能存放基础数据类型，也可能存放自定义数据类型
	for_each(pBegin, pEnd, PrintV);

}

//容器存放自定义数据类型
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
	//创建容器并指定元素类型
	vector<Person> v;
	Person p1(1, 10), p2(2, 20), p3(3, 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).age << "  " << (*it).id << endl;
	}
}


int main1() {
	//test01();
	test2();

	return 0;
}

