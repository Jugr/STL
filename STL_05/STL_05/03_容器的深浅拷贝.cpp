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
	char* pName;//ָ�����׳���ǳ��������
	int mAge;
};



void test301() {


	//Person p("aaa", 40);

	//vector<Person> vPerson;
	//vPerson.push_back(p);

}


int main3() {
	/*
	STL�����ṩ����ֵԢ���������Ԣ�⣬
	�����������в���Ԫ�أ������ڲ�ʵʩ�˿���������
	��������Ԫ�ؿ���һ�ݷ��������У������ǽ�ԭ���ݷ���������
	****************������ṩ��Ԫ�ر����ܹ�����***************
	*/
	test301();


	return 0;
}