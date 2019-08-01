#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>& v4) {
	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++) {
		cout << *it << endl;

	}
}


void test301() {
	//Ĭ�Ͽ�������
	vector<int> v1;

	//��������
	int arr[] = { 10,20,30,40 };
	//vector(v.begin(),v.end())
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	
	//��������
	vector<int> v3(v2.begin(),v2.end());

	//��������
	vector<int> v4(v3);

	printVector(v2);

}


//���ø�ֵ����
void test302() {
	
	//��������
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//��Ա����
	vector<int> v2;
	//asign(begin,end)
	v2.assign(v1.begin(), v1.end());

	//���صȺ�
	vector<int> v3;
	v3 = v2;

	int arr1[] = { 100,200,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
	//v1 v4����  ʵ����ָ�뽻����
	v4.swap(v1);
}

//��С����
void test303() {

	//��������
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//.size()
	cout << v1.size() << endl;
	//.empty()
	if (v1.empty()) {
		cout << "��" << endl;
	}

	//.resize()   �������Ԫ������   �ٵĿ�λĬ�ϲ�0
	v1.resize(3);
	//��λ��1
	v1.resize(8,1);

	//.capacity()
	cout << v1.capacity() << endl;



}

//��ȡ����
void test304() {

	//��������
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	//v[i]
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << "  " << endl;
	}
	cout << endl;

	//v.at(i)  ���� .at()�����쳣
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << "  " << endl;
	}
	cout << endl;

}


//������ɾ��
void test305() {
	//Ĭ�Ͽ�������
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	//ͷ�巨
	v1.insert(v1.begin(),30);
	//β�巨
	v1.insert(v1.end(),30);

	v1.insert(v1.begin()+2, 30);//vector֧���������

	//֧�������ŵ�һ�붼֧���������
	//������֧��+1 +3 +5 -6

	//ɾ��
	v1.erase(v1.begin());
	v1.erase(v1.begin()+1,v1.end());
	v1.clear();
}

//����swap�����ռ�
void test306() {
	//vector���Ԫ�� ���Զ�����
	//vector���Ԫ�� capacity����

	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	cout << v.capacity()<< endl;

	v.resize(10);//capacity����
	cout << "----------------" << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;//capacity����

	//�����ռ�  ԭ����������
	vector<int>(v).swap(v);

	cout << "----------------" << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void test307() {

	//reserve Ԥ���ռ�  resize����

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

	cout << num << endl;//numΪ1

	//���֪��������Ŷ��,����reserve()

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
