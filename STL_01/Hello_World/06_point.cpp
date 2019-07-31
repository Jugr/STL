#include <iostream>
using namespace std;

int main6() {

	int a = 9;
	int* p = &a;

	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;

	system("pause");
	return 0;
}