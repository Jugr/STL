#include <iostream>
#include<string>
using namespace std;


void change_value1(int* p) {
	*p = 30;
}

void change_value2(int& re) {
	re = 40;
}

int main9() {

	int a = 10;

	/*
		//re就是a的别名,与a有相同的地址
	int& re = a;

	cout << re << endl;
	re = 20;
	cout << a << endl;
	*/
	
	//都一样 都不用子拷贝
	//a值变化
	change_value1(&a);
	cout << a << endl;
	//a值变化
	change_value2(a);
	cout << a << endl;




	system("pause");
	return 0;
}










