#include<iostream>
#include<set>
using namespace std;



//容器初始化
void test501() {

	set<int> s1;//自动从小到大排序

	s1.insert(4);
	s1.insert(6);
	s1.insert(7);
	s1.insert(3);
	s1.insert(9);
	s1.insert(0);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	
	//赋值
	set<int> s2;
	s2 = s1;

	//删除
	s2.erase(s1.begin());//s1.erase(pos)
	s2.erase(7); //s2.erase(elem)

}

//set查找
void test502() {
	//实值
	set<int> s1;

	s1.insert(4);
	s1.insert(6);
	s1.insert(7);
	s1.insert(3);
	s1.insert(9);
	s1.insert(0);


	//s.find()  
	//找到就返回迭代器 没找到返回s.end()
	set<int>::iterator ret = s1.find(4);
	if (ret == s1.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}


	//s.lowerbound(elem)  
	//若元素在set中 返回迭代器 若不在 找出比该elem大的所有元素中最小的元素的迭代器 
	//即找到第一个大于等于elem的元素
	ret = s1.lower_bound(3);
	if (ret == s1.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}
	//输出 3



	//s1.upper_bound(elem)
	//找到第一个大于elem的值
	ret = s1.upper_bound(3);
	if (ret == s1.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}
	//输出4


	//s1.equal_range 返回Lowerbound好upperbound值
	pair<set<int>::iterator,set<int>::iterator>myret = s1.equal_range(3);
	if (myret.first == s1.end()){
		cout<<"没有找到"<<endl;
	}
	else {
		cout<<"myret.first:"<<*(myret.first)<<endl;
	}//输出lower_bound  ：3

	if (myret.second == s1.end()){
		cout << "没有找到" << endl;
	}
	else {
		cout << "myret.second:" << *(myret.second) << endl;
	}//输出upper_bound  ：4

}


//仿函数
class mycompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

//如何改变默认排序
void test503() {
	//mycompare com;
	//com(10,20);

	set<int, mycompare> s1;//自动从小到大排序

	s1.insert(4);
	s1.insert(6);
	s1.insert(7);
	s1.insert(3);
	s1.insert(9);
	s1.insert(0);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	//从大到小输出


}


class Person
{
public:
	Person(int age, int id) :id(id), age(age) {}
public:
	int id;
	int age;
private:

};

class mycompare2
{
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.age > p2.age;
	}
};

void test504() {

	set<Person, mycompare2> sp;//set需要排序 当放入对象时 set不知道如何排序

	Person p1(10, 20), p2(30, 40), p3(50,60);

	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end(); it++) {
		cout << (*it).age << "  " << (*it).id << endl;
	}


	//***************************************************************************************
	Person p4(10,30);//p1.age == p4.age id不同
	//查找
	set<Person, mycompare2>::iterator ret = sp.find(p4);
	if (ret == sp.end()) {
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到:" << (*ret).age << "  " << (*ret).id << endl;
	}
	//一样能查找出来  因为set是按照age排序查找的
	//***************************************************************************************

}


int main5() {

	//test501();
	//test502();
	//test503();
	test504();

	return 0;
}