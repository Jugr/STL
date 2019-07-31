#include<iostream>
using namespace std;

template<class T>
class Person {
public :
	T mAge;
public:
	Person() {
		mAge = 0;
	}
};
//类模板派生普通类
class subPerson :public Person<int> {};

//类模板派生类模板
template<class T>
class subPerson2 :public Person<T> {};

int main5(void)
{
	subPerson2<int>();
	return 0;
}