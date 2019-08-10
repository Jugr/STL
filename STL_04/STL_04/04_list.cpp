#include<iostream>
#include<list>

using namespace std;

//初始化
void test401() {
	//无参构造
	list<int> mlist1;
	//有参构造
	list<int> mlist2(10,2);//10个2
	//拷贝构造
	list<int> mlist3(mlist2);

	list<int> mlist4(mlist3.begin(),mlist3.end());


	for (list<int>::iterator it = mlist4.begin(); it != mlist4.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;//10个2
}

//插入删除
void test402() {
	list<int> mlist;
	
	//插入
	//push_back()
	mlist.push_back(100);
	mlist.push_back(200);
	//insert()
	mlist.insert(mlist.begin(),300);//相对于mlist.push_front(}
	mlist.insert(mlist.end(),400);//相对于mlist.push_back()
	//iterator
	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it,500);
	
	//删除
	//pop_back()  pop_front()
	mlist.pop_back();
	mlist.pop_front();
	//erase
	mlist.erase(mlist.begin(), mlist.end());//相对于mlist.clear();
	//clear
	mlist.clear();
	//remove()删除*所有*匹配的值
	mlist.remove(200);

}

//大小操作
void test403() {
	//size()  empty()  resize(num) resize(nun,elem)

}

//赋值
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

	//元素反转
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
	//排序   默认从小到大
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