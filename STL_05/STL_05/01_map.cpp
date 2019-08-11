#include<iostream>
#include<map>
using namespace std;

//map容器初始化
void test101() {

	//map容器模板参数，第一个参数key类型，第二个参数value类型
	map<int, int> mymap;

	//插入数据  pair.first  key值  pai.second  value值
	//第一种
	//mymap.insert(pair<int,int>(10,10));
	pair<map<int,int>::iterator,bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second) {
		cout << "第一次插入成功！"<<endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	//第一次插入成功！

	ret = mymap.insert(pair<int, int>(10, 20));
	if (ret.second) {
		cout << "第二次插入成功！" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	//插入失败

	//第二种
	mymap.insert(make_pair(20, 20));
	//第三种
	mymap.insert(map<int, int>::value_type(30, 30));
	//第四种
	mymap[40] = 40;//发现key不存在，创建pair插入map容器中
	mymap[10] = 20;//发现key存在，修改key对应的value值
	
	//如果通过[]方式访问,ap中不存在的key,map会将此key插入map中，并会给一个默认的value值0
	cout << "mymap[60]:" << mymap[60] << endl;

	//打印
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		//*it取出来的是一个pair
		cout << "key:" << (*it).first << "value:" << (*it).second << endl;
	}

}



//map插入对象
class MyKey
{
public:
	MyKey(int mIdex, int mID) :mIndex(mIdex), mID(mID) {}
public:
	int mIndex;
	int mID;
};

//提供排序方法  重载括号
struct mycompare
{
	bool operator()(const MyKey& key1, const MyKey& key2) {
		return key1.mIndex > key2.mIndex;
	}
};

void test102() {
	map<MyKey, int, mycompare> mymap;//放入对象类型要提供排序方法
	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		//*it取出来的是一个pair
		cout << "mIndex:" << (*it).first.mIndex << "value:" << (*it).second << endl;
	}
}


//equal_range
void test103() {

	map<int, int> mymap;
	mymap.insert(make_pair(1, 1));
	mymap.insert(make_pair(2, 2));
	mymap.insert(make_pair(3, 3));

	//若存在，返回该对象元素的迭代器 否则返回map.end()
	//mymap.find(key);


	//第一个是lower_bound  第二个是upper_bound
	//lower_bound(keyelem)返回第一个key<=keyelem元素的迭代器
	//upper_bound(keyelem)返回第一个key>keyelem元素的迭代器
	pair<map<int,int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
	if (ret.first->second) {//->second是bool类型 指是否找到
		cout << "找到lower_bound" << endl;
	}
	else {
		cout << "没有找到lower_bound" << endl;
	}

	if (ret.second->second) {
		cout << "找到upper_bound" << endl;
	}
	else {
		cout << "没有找到upper_bound" << endl;
	}

	/*输出：
	找到lower_bound
	找到upper_bound
	*/

}


int main1() {
	//test101();
	//test102();
	test103();
	return 0;
}