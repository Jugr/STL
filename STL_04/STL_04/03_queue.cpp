#include<iostream>
#include<queue>

using namespace std;

void test301() {
	//无参构造  拷贝构造
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	
	cout << q.back() << endl;//队尾元素 (不删除)
	
	//输出顺序
	while (!q.empty()) {
		cout << q.front() << "  ";//输出对头元素
		q.pop();
	}
	cout << endl;//10  20  30  40  50

}

int main3() {

	test301();
	return 0;
}