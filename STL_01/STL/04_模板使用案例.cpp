#include<iostream>
using namespace std;



//打印函数
template<class T>
void printArray(T* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//排序
template<class T>
void MySort(T* arr, int len) {

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < len - 1; i++) {
			if (arr[i] < arr[i + 1]) {
	            T tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}	
		}
	}
	

}


int main4() {

	//数组
	int arr[] = { 2,4,8,1,9,0,3,5 };
	//数组长度
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	MySort(arr, len);
	printArray(arr, len);


	char chArr[] = { 'a','c','b','p','t' };
	len = sizeof(chArr) / sizeof(char);
	printArray(chArr,len);
	MySort(chArr, len);
	printArray(chArr, len);

	return 0;
}