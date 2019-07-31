#include<iostream>
#include<string>
using namespace std;


template<class T1,class T2>
class Person {
public:
	T1 mName;
	T2 mAge;
public:
	Person(T1 name, T2 age) {
		this->mAge = age;
		this->mName = name;
	}
	void show() {
		cout << "name:" << this->mName << "age:" << this->mAge << endl;
	}

};

void test07() {
	Person<string,int> p("a",1);
	p.show();
}

int main7() {

	test07();
	return 0;
}