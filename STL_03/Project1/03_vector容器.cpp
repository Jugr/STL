#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>& v4) {
	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++) {
		cout << *it << endl;

	}
}


void test301() {
	//默认拷贝构造
	vector<int> v1;

	//拷贝构造
	int arr[] = { 10,20,30,40 };
	//vector(v.begin(),v.end())
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	
	//拷贝构造
	vector<int> v3(v2.begin(),v2.end());

	//拷贝构造
	vector<int> v4(v3);

	printVector(v2);

}


//常用赋值操作
void test302() {
	
	//拷贝构造
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//成员方法
	vector<int> v2;
	//asign(begin,end)
	v2.assign(v1.begin(), v1.end());

	//重载等号
	vector<int> v3;
	v3 = v2;

	int arr1[] = { 100,200,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
	//v1 v4交换  实质是指针交换了
	v4.swap(v1);
}

//大小操作
void test303() {

	//拷贝构造
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//.size()
	cout << v1.size() << endl;
	//.empty()
	if (v1.empty()) {
		cout << "空" << endl;
	}

	//.resize()   多出来的元素抛弃   少的空位默认补0
	v1.resize(3);
	//空位补1
	v1.resize(8,1);

	//.capacity()
	cout << v1.capacity() << endl;



}

//存取数据
void test304() {

	//拷贝构造
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//v[i]
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << "  " << endl;
	}
	cout << endl;

	//v.at(i)  区别 .at()会抛异常
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << "  " << endl;
	}
	cout << endl;

}


//插入与删除
void test305() {
	//默认拷贝构造
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	//头插法
	v1.insert(v1.begin(),30);
	//尾插法
	v1.insert(v1.end(),30);

	v1.insert(v1.begin()+2, 30);//vector支持随机访问

	//支持中括号的一半都支持随机访问
	//迭代器支持+1 +3 +5 -6

	//删除
	v1.erase(v1.begin());
	v1.erase(v1.begin()+1,v1.end());
	v1.clear();
}

//巧用swap收缩空间
void test306() {
	//vector添加元素 会自动增长
	//vector添加元素 capacity不变

	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	cout << v.capacity()<< endl;

	v.resize(10);//capacity不变
	cout << "----------------" << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;//capacity不变

	//收缩空间  原理匿名对象
	vector<int>(v).swap(v);

	cout << "----------------" << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void test307() {

	//reserve 预留空间  resize区别

	int num = 0;
	int* address = NULL;

	vector<int> v;

	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		v.reserve(10000);
		if (address != &(v[0])) {
			address = &(v[0]);
			num++;
		}
	}

	cout << num << endl;//num为1

	//如果知道容器大概多大,可以reserve()

}


int main() {
	//test301();
	//test302();
	//test303();
	//test304();
	//test305();
	//test306();
	test307();


	return 0;
}
