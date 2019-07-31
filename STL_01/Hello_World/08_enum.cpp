#include <iostream>
#include<string>
using namespace std;


enum Season
{
	SPR = 0,
	SUM,
	AUT,
	WIN
};

int main8() {

	enum Season s = AUT;
	if (s == AUT) {
		cout << "1" << endl;
	}

	system("pause");
	return 0;
}