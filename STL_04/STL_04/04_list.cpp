#include<iostream>
#include<list>

using namespace std;

//��ʼ��
void test401() {
	//�޲ι���
	list<int> mlist1;
	//�вι���
	list<int> mlist2(10,2);//10��2
	//��������
	list<int> mlist3(mlist2);

	list<int> mlist4(mlist3.begin(),mlist3.end());


	for (list<int>::iterator it = mlist4.begin(); it != mlist4.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;//10��2
}

//����ɾ��
void test402() {
	list<int> mlist;
	
	//����
	//push_back()
	mlist.push_back(100);
	mlist.push_back(200);
	//insert()
	mlist.insert(mlist.begin(),300);//�����mlist.push_front(}
	mlist.insert(mlist.end(),400);//�����mlist.push_back()
	//iterator
	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it,500);
	
	//ɾ��
	//pop_back()  pop_front()
	mlist.pop_back();
	mlist.pop_front();
	//erase
	mlist.erase(mlist.begin(), mlist.end());//�����mlist.clear();
	//clear
	mlist.clear();
	//remove()ɾ��*����*ƥ���ֵ
	mlist.remove(200);

}

//��С����
void test403() {
	//size()  empty()  resize(num) resize(nun,elem)

}

//��ֵ
void test404() {
	list<int> mlist;
	mlist.assign(10,10);//(nun,elem)

	list<int> mlist2;
	mlist2 = mlist;

	mlist2.swap(mlist);

}

void test405() {
	list<int> mlist;

	for (int i = 0; i < 10; i++) {
		mlist.push_back(i);
	}

	//Ԫ�ط�ת
	mlist.reverse();

	for (list<int>::iterator it=mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool mySort(int a, int b) {
	return a > b;
}

void test406() {
	list<int>mlist;

	mlist.push_back(7);
	mlist.push_back(3);
	mlist.push_back(9);
	mlist.push_back(1);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//����   Ĭ�ϴ�С����
	//mlist.sort();
	mlist.sort(mySort);

	
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;



}




int main4() {
	//test401();
	//test405();
	test406();

	return 0;
}