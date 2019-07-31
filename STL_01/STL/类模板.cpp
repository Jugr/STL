#include<iostream>
using namespace std;


template<class T>
class Person {
public:
	T mId;
	T mAge;


public:
	Person(T id, T age) {
		this->mAge = age;
		this->mId = id;
	}

	void show() {
		cout << "id:" <<this->mId << "age:" << this->mAge << endl;
	}

};

void test3() {

	//函数模板在调用时，可以自动类型推导
	//类模板调用时，必须显示指定类型
	Person<int> p(10, 20);
	p.show();
}



int main3() {

	test3();

	return 0;
}