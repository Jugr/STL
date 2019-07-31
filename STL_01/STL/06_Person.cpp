#include"Person.h"

//.cpp×÷ÊµÏÖ

Person::Person(string name, int age) {
	this->mName = name;
	this->mAge = age;
}
void Person::Show() {
	cout << "name:" << this->mName << "age:" << this->mAge << endl;
}