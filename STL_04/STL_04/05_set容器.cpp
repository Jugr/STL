#include<iostream>
#include<set>
using namespace std;



//������ʼ��
void test501() {

	set<int> s1;//�Զ���С��������

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
	
	//��ֵ
	set<int> s2;
	s2 = s1;

	//ɾ��
	s2.erase(s1.begin());//s1.erase(pos)
	s2.erase(7); //s2.erase(elem)

}

//set����
void test502() {
	//ʵֵ
	set<int> s1;

	s1.insert(4);
	s1.insert(6);
	s1.insert(7);
	s1.insert(3);
	s1.insert(9);
	s1.insert(0);


	//s.find()  
	//�ҵ��ͷ��ص����� û�ҵ�����s.end()
	set<int>::iterator ret = s1.find(4);
	if (ret == s1.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}


	//s.lowerbound(elem)  
	//��Ԫ����set�� ���ص����� ������ �ҳ��ȸ�elem�������Ԫ������С��Ԫ�صĵ����� 
	//���ҵ���һ�����ڵ���elem��Ԫ��
	ret = s1.lower_bound(3);
	if (ret == s1.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}
	//��� 3



	//s1.upper_bound(elem)
	//�ҵ���һ������elem��ֵ
	ret = s1.upper_bound(3);
	if (ret == s1.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "ret:" << *ret << endl;
	}
	//���4


	//s1.equal_range ����Lowerbound��upperboundֵ
	pair<set<int>::iterator,set<int>::iterator>myret = s1.equal_range(3);
	if (myret.first == s1.end()){
		cout<<"û���ҵ�"<<endl;
	}
	else {
		cout<<"myret.first:"<<*(myret.first)<<endl;
	}//���lower_bound  ��3

	if (myret.second == s1.end()){
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "myret.second:" << *(myret.second) << endl;
	}//���upper_bound  ��4

}


//�º���
class mycompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

//��θı�Ĭ������
void test503() {
	//mycompare com;
	//com(10,20);

	set<int, mycompare> s1;//�Զ���С��������

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
	//�Ӵ�С���


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

	set<Person, mycompare2> sp;//set��Ҫ���� ���������ʱ set��֪���������

	Person p1(10, 20), p2(30, 40), p3(50,60);

	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end(); it++) {
		cout << (*it).age << "  " << (*it).id << endl;
	}


	//***************************************************************************************
	Person p4(10,30);//p1.age == p4.age id��ͬ
	//����
	set<Person, mycompare2>::iterator ret = sp.find(p4);
	if (ret == sp.end()) {
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�:" << (*ret).age << "  " << (*ret).id << endl;
	}
	//һ���ܲ��ҳ���  ��Ϊset�ǰ���age������ҵ�
	//***************************************************************************************

}


int main5() {

	//test501();
	//test502();
	//test503();
	test504();

	return 0;
}