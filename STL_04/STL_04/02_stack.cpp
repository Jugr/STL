#include<iostream>
#include<stack>
using namespace std;


void test201() {
	//��ʼ��
	stack<int> s1;
	stack<int>s2(s1);

	//����
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);
	cout << "ջ��Ԫ��:" << s1.top() << endl;//100

	s1.pop();//ɾ��ջ��Ԫ��

	//��ӡ
	while (!s1.empty()) {
		cout << s1.top() << "  ";
		s1.pop();
	}
	cout << endl;
}



int main2() {

	test201();
	return 0;
}