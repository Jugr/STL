#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

struct MyPrint : public binary_function<int,int,void> {
	void operator()(int v,int addNum) const {
		cout << "v +addNum:" << v + addNum << "  ";
		cout << "v:" << v << "  addNum:" << addNum << endl;
	}
};


//仿函数适配器 bindlst bind2nd  绑定适配器
void test601() {

	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	/*
	MyPrint print;
	for_each(v.begin(), v.end(), print);
	*/
	//for_each(v.begin(), v.end(),MyPrint());//放print匿名对象
	
	int addNum=100;
	for_each(v.begin(), v.end(),bind2nd(MyPrint(), addNum));//
	/*输出:
	v +addNum:100  v:0  addNum:100
	v +addNum:101  v:1  addNum:100
	v +addNum:102  v:2  addNum:100
	v +addNum:103  v:3  addNum:100
	v +addNum:104  v:4  addNum:100
	v +addNum:105  v:5  addNum:100
	v +addNum:106  v:6  addNum:100
	v +addNum:107  v:7  addNum:100
	v +addNum:108  v:8  addNum:100
	v +addNum:109  v:9  addNum:100
	*/


	//绑定适配器:将一个二元函数对象变成一个一元函数对象
	/*
	bind1st bind2nd区别：
	bind1st 将addNum绑定为函数对象的第一个参数
	bind2nd 将addNum绑定为函数对象的第二个参数
	*/

}

struct MyPrint02 {
	void operator()(int v)  {
		cout << v << "  ";
	}
};

struct MyCompare :public binary_function<int,int,bool>{
	bool operator()(int v1,int v2) const {
		return v1 > v2;
	}
};

struct MyGreater5 :public unary_function<int, bool> {
	bool operator()(int v)  const{
		return v > 5;
	}
};

//仿函数适配器 not1 not2
void test602() {
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(rand()%100);
	}

	for_each(v.begin(), v.end(), MyPrint02()); cout << endl;
	//sort(v.begin(),v.end(), MyCompare());
	sort(v.begin(),v.end(), not2(MyCompare()));//改成从小到大
	for_each(v.begin(),v.end(), MyPrint02()); cout << endl;
	/*输出
	41  67  34  0  69  24  78  58  62  64
	0  24  34  41  58  62  64  67  69  78
	*/

	//not1 not2
	//如果对二元谓词取反（2个参数）  用not2
	//如果对一元谓词取反 （1个参数） 用not1


	//vector<int>::iterator it = find_if(v.begin(), v.end(),MyGreater5());
	vector<int>::iterator it = find_if(v.begin(), v.end(),not1(MyGreater5()));//改成第一个小于5
	if (it == v.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << *it << endl;
	}
	

}

void MyPrint03(int val) {
	cout << val << "   ";
}


//仿函数适配器 ptr_fun
void teat603(){

	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}


	for_each(v.begin(), v.end(), MyPrint03);//传函数或仿函数对象都行

}



//成员函数适配器 mem_fun mem_fun_ref


int main() {
	//test601();
	//test602();
	teat603();
	return 0;
}