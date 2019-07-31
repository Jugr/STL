#include<iostream>
#include<string>


using namespace std;

int main3()
{
	/*
	int arr[5];
	arr[0] = 1;
	cout << arr[0] << endl;
	*/
	/*
	int arr[5] = {1,2,3,4,5};
	cout << &arr[0] << endl;
	cout << &arr << endl;
	cout << (int)&arr[0] << endl;
	*/
	
	int arr[10] = { 4,7,0,2,6,9,3,1,8,5 };
	bool flag = false;
	int temp = arr[0];

	while (flag == false) {
		flag = true;
		for (int i = 0; i < 9; i++) {
			if (arr[i] < arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = false;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	system("pause");

	return 0;
}