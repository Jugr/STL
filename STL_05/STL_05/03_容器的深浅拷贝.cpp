#include<iostream>
#include<vector>
using namespace std;

class Person
{
public:
#if 0
	Person(char* pName, int mAge) {
		this->pName = new char[strlen(pName) + 1];
		strcpy(this->pName, pName);
		this->mAge = mAge; 
	}

	Person(const Person& p) {
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = p.mAge;
	}
	Person& operator=(const Person& p) {
		if (this->pName != NULL) {
			delete[] this->pName;
		}
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = p.mAge;
	}
#endif
	~Person()
	{
		if (this->pName != NULL) {
			delete[] this->pName;
		}
	}

public:
	char* pName;//指针容易出现浅拷贝问题
	int mAge;
};



void test301() {


	//Person p("aaa", 40);

	//vector<Person> vPerson;
	//vPerson.push_back(p);

}


int main3() {
	/*
	STL容器提供的是值寓意而非引用寓意，
	即当给容器中插入元素，容器内部实施了拷贝动作，
	将待插入元素拷贝一份放入容器中，而不是将原数据放入容器，
	****************因此所提供的元素必须能够拷贝***************
	*/
	test301();


	return 0;
}