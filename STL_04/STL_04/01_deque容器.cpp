#include<iostream>
#include<deque>

using namespace std;

void PrintDeque(deque<int>& d4) {
	//��ӡ
	for (deque<int>::iterator it = d4.begin(); it != d4.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}


//����
void test101() {
	
	deque<int> d1;
	deque<int> d2(10,5);//deque(n,elem)
	deque<int> d3(d2.begin(),d2.end());
	deque<int> d4(d3);

	 //d4���10��5
}


//��ֵ
void test202() {
	
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10,5);//10��5
	d2.assign(d1.begin(),d2.end());//������ָ������
	d3 = d2;//�ȺŸ�ֵ

	d1.swap(d2);//����

	if (d1.empty()) {
		cout << "��" << endl;
	}

	d1.resize(5);//��5��Ԫ���ӵ�


}


//deque����ɾ��
void test203() {
	deque<int> d1;
	d1.push_back(100);
	d1.push_front(200);
	d1.push_back(300);
	d1.push_back(400);
	d1.push_front(500);
	//500 200 100 300 400
	PrintDeque(d1);


	int val = d1.front();//�õ���ɾ��������
	d1.pop_front();//ɾ��

	int val2 = d1.back();
	d1.pop_back();//ɾ��

	//begin() end()�ǵ�ַ/������    front() back()��Ԫ��

}


int main1() {

	//test201();
	test203();
	return 0;
}
