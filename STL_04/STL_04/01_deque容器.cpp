#include<iostream>
#include<deque>

using namespace std;

void PrintDeque(deque<int>& d4) {
	//打印
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}


//构造
void test101() {
	
	deque<int> d1;
	deque<int> d2(10,5);//deque(n,elem)
	deque<int> d3(d2.begin(),d2.end());
	deque<int> d4(d3);

	 //d4输出10个5
}


//赋值
void test202() {
	
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10,5);//10个5
	d2.assign(d1.begin(),d2.end());//迭代器指定区间
	d3 = d2;//等号赋值

	d1.swap(d2);//交换

	if (d1.empty()) {
		cout << "空" << endl;
	}

	d1.resize(5);//后5个元素扔掉


}


//deque插入删除
void test203() {
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);
	//500 200 100 300 400
	PrintDeque(d1);


	int val = d1.front();//拿到被删除的数据
	d1.pop_front();//删除

	int val2 = d1.back();
	d1.pop_back();//删除

	//begin() end()是地址/迭代器    front() back()是元素

}


int main1() {

	//test201();
	test203();
	return 0;
}
