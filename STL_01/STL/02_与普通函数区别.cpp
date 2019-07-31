#include<iostream>
using namespace std;


template<class T>
int MyAdd(T a, T b) {
	return a + b;
}

int MyAdd(int a, char c) {
	return a + c;
}

void test02() {

	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	MyAdd(a, c1);//调用普通函数  模板函数类型不匹配
	MyAdd(a, b);//调用普通函数   两种函数都满足条件时，优先调用普通函数
	MyAdd<>(a, b);//强制调用模板函数
	MyAdd(c1,a);//调用普通函数  发生类型转换


	double d1 = 10.;
	double d2 = 10.;
	MyAdd(d1, d2);//即传入的两个参数完全与模板函数定义时一致
}





//模板函数可以被重载
template<class T>
void Print(T a) {

}

template<class T>
void Print(T a,T b) {

}


int main2()
{	
	test02();
	return 0;
}