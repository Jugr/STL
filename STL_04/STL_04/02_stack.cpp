#include<iostream>
#include<stack>
using namespace std;


void test201() {
	//³õÊ¼»¯
	stack<int> s1;
	stack<int>s2(s1);

	//²Ù×÷
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);
	cout << "Õ»¶¥ÔªËØ:" << s1.top() << endl;//100

	s1.pop();//É¾³ýÕ»¶¥ÔªËØ

	//´òÓ¡
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