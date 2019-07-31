#include<iostream>
#include<string>
#include"swap.h"

using namespace std;


int max(int a, int b);
int main5() {

	int a = 3;
	int b = 5;
	//cout << max(a, b) << endl;
	cout <<myswap(a, b) << endl;

	system("pause");
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}
