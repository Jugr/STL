#include <iostream>
using namespace std;

// int类型交换
//void MySwap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}


// int类型交换
//void MySwap(double& a, double& b) {
//	double tmp = a;
//	a = b;
//	b = tmp;
//}

//模板   忽略类型
// 让编译器区分是否是模板函数
template<class T>  //template<typename T>//告诉编译器下面是模板函数
void MySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

//template<class T1,class T2>


void test1() {
	int a = 10;
	int b = 20;
	//显示指定类型
	MySwap<int>(a, b);
	cout << "a:" << a << "b:" << b << endl;
}

int main1(void) {
	test1();


	return 0;
}
