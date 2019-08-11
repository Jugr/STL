#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyPrint
{
public:
	MyPrint() {
		mNum = 0;
	}
	//函数对象重载括号
	void operator()(int val) {
		cout << val << endl;
		mNum++;
	}
public:
	int mNum;
};

int num = 0;
void MyPrint02(int val) {
	cout << val << endl;
	num++;
}
void test401() {
	MyPrint print;
	print(10);
	/*
	函数对象可以像普通函数一样调用
	函数对象可以像普通函数一样接收参数
	函数对象超出了函数的概念，函数对象可以保存函数调用的状态
	*/

}



void test402() {

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

#if 0
	//计算函数调用次数
	MyPrint02(10);
	MyPrint02(20);
	cout << num << endl;

	MyPrint print;
	print(10);
	print(20);
	cout << print.mNum << endl;

#endif

	MyPrint print;
	MyPrint print02 =  for_each(v.begin(),v.end(), print);//print是被拷贝过去的
	cout << "print调用次数"<<print.mNum << endl;
	cout << "print02调用次数"<<print02.mNum << endl;
	/*输出：
		10
		20
		30
		40
		print调用次数0
		print02调用次数4
	*/
}



int main4() {

	test402();

	return 0;
}