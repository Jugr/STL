#include<iostream>
#include<map>
using namespace std;

//map������ʼ��
void test101() {

	//map����ģ���������һ������key���ͣ��ڶ�������value����
	map<int, int> mymap;

	//��������  pair.first  keyֵ  pai.second  valueֵ
	//��һ��
	//mymap.insert(pair<int,int>(10,10));
	pair<map<int,int>::iterator,bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "��һ�β���ɹ���"<<endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	//��һ�β���ɹ���

	ret = mymap.insert(pair<int, int>(10, 20));
	if (ret.second) {
		cout << "�ڶ��β���ɹ���" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	//����ʧ��

	//�ڶ���
	mymap.insert(make_pair(20, 20));
	//������
	mymap.insert(map<int, int>::value_type(30, 30));
	//������
	mymap[40] = 40;//����key�����ڣ�����pair����map������
	mymap[10] = 20;//����key���ڣ��޸�key��Ӧ��valueֵ
	
	//���ͨ��[]��ʽ����,ap�в����ڵ�key,map�Ὣ��key����map�У������һ��Ĭ�ϵ�valueֵ0
	cout << "mymap[60]:" << mymap[60] << endl;

	//��ӡ
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		//*itȡ��������һ��pair
		cout << "key:" << (*it).first << "value:" << (*it).second << endl;
	}

}



//map�������
class MyKey
{
public:
	MyKey(int mIdex, int mID) :mIndex(mIdex), mID(mID) {}
public:
	int mIndex;
	int mID;
};

//�ṩ���򷽷�  ��������
struct mycompare
{
	bool operator()(const MyKey& key1, const MyKey& key2) {
		return key1.mIndex > key2.mIndex;
	}
};

void test102() {
	map<MyKey, int, mycompare> mymap;//�����������Ҫ�ṩ���򷽷�
	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		//*itȡ��������һ��pair
		cout << "mIndex:" << (*it).first.mIndex << "value:" << (*it).second << endl;
	}
}


//equal_range
void test103() {

	map<int, int> mymap;
	mymap.insert(make_pair(1, 1));
	mymap.insert(make_pair(2, 2));
	mymap.insert(make_pair(3, 3));

	//�����ڣ����ظö���Ԫ�صĵ����� ���򷵻�map.end()
	//mymap.find(key);


	//��һ����lower_bound  �ڶ�����upper_bound
	//lower_bound(keyelem)���ص�һ��key<=keyelemԪ�صĵ�����
	//upper_bound(keyelem)���ص�һ��key>keyelemԪ�صĵ�����
	pair<map<int,int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
	if (ret.first->second) {//->second��bool���� ָ�Ƿ��ҵ�
		cout << "�ҵ�lower_bound" << endl;
	}
	else {
		cout << "û���ҵ�lower_bound" << endl;
	}

	if (ret.second->second) {
		cout << "�ҵ�upper_bound" << endl;
	}
	else {
		cout << "û���ҵ�upper_bound" << endl;
	}

	/*�����
	�ҵ�lower_bound
	�ҵ�upper_bound
	*/

}


int main1() {
	//test101();
	//test102();
	test103();
	return 0;
}