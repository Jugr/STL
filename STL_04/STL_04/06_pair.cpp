#include<iostream>
using namespace std;


void test601() {

	//���췽��1
	pair<int, int> pair1(10,20);
	cout << pair1.first << "  " << pair1.second <<endl;
	
	//���췽��2
	pair<int, string> pair2 = make_pair(10,"zs");
	cout << pair2.first << "  " << pair2.second << endl;

	//pair��ֵ
	pair<int, string> pair3 = pair2;
	cout << pair3.first << "  " << pair3.second << endl;

}



int main6() {

	test601();

	return 0;
}