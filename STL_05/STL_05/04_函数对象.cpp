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
	//����������������
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
	���������������ͨ����һ������
	���������������ͨ����һ�����ղ���
	�������󳬳��˺����ĸ������������Ա��溯�����õ�״̬
	*/

}



void test402() {

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

#if 0
	//���㺯�����ô���
	MyPrint02(10);
	MyPrint02(20);
	cout << num << endl;

	MyPrint print;
	print(10);
	print(20);
	cout << print.mNum << endl;

#endif

	MyPrint print;
	MyPrint print02 =  for_each(v.begin(),v.end(), print);//print�Ǳ�������ȥ��
	cout << "print���ô���"<<print.mNum << endl;
	cout << "print02���ô���"<<print02.mNum << endl;
	/*�����
		10
		20
		30
		40
		print���ô���0
		print02���ô���4
	*/
}



int main4() {

	test402();

	return 0;
}