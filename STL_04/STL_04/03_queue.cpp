#include<iostream>
#include<queue>

using namespace std;

void test301() {
	//�޲ι���  ��������
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	
	cout << q.back() << endl;//��βԪ�� (��ɾ��)
	
	//���˳��
	while (!q.empty()) {
		cout << q.front() << "  ";//�����ͷԪ��
		q.pop();
	}
	cout << endl;//10  20  30  40  50

}

int main3() {

	test301();
	return 0;
}