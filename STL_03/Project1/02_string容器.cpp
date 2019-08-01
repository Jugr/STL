#include<iostream>
#include<string>
using namespace std;

//初始化
void test03() {

	string s1;//调用无参构造
	string s2(10,'a');
	string s3("abcdefg");
	string s4(s3);//拷贝构造

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//赋值操作
void test04() {
	
	string s1;
	string s2("abcd");
	s1 = "aaaa";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;
	//成员方法assign  进行赋值
	s1.assign("jkl");
	cout << s1 << endl;
}


//取值操作
void test05() {
	string s1 = "abcdefg";

	//重载[]操作符
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << "  ";
	}
	cout << endl;

	//at成员函数
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << "  ";
	}

	//区别
	/*
	[] 方式：若访问越界，直接挂掉
	at方式：访问越界，抛异常out)of_range
	*/

	try
	{
		//cout << s1[100] << endl;
		cout << s1.at(100)<< endl;
	}
	catch (...)
	{
		cout << "越界" << endl;
	}


}

//查找操作
void test06() {

	string s = "abcdefgk";
	//查找第一次出现位置
	int  pos = s.find("fg");
	//查找最后一次出现位置
	int pos2 = s.rfind("fg");
	cout << pos << endl;
	cout << pos2 << endl;
}

//string 替换
void test07() {
	string s = "abcdefgk";
	s.replace(0, 2, "111");
	cout << s << endl;
}

//string 比较
void test08() {
	string s1 = "abcd";
	string s2 = "abce";

	if (s1.compare(s2) == 0) {
		cout << "相等" << endl;

	}
	else {
		cout << "不相等" << endl;

	}
}

//子串操作
void test09() {
	string s = "abcdefg";
	//从第几个位置开始 取几个
	string mysub = s.substr(0,2);
	cout << mysub << endl;
}

//插入和删除
void test10() {
	string s = "abcdefg";
	s.insert(3,"111");
	cout << s << endl;
	//abc111defg

	s.erase(0,2);
	cout << s << endl;
	//c111defg
}



int main2() {
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	test10();
	return 0;
}