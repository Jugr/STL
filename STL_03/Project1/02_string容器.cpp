#include<iostream>
#include<string>
using namespace std;

//��ʼ��
void test03() {

	string s1;//�����޲ι���
	string s2(10,'a');
	string s3("abcdefg");
	string s4(s3);//��������

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//��ֵ����
void test04() {
	
	string s1;
	string s2("abcd");
	s1 = "aaaa";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;
	//��Ա����assign  ���и�ֵ
	s1.assign("jkl");
	cout << s1 << endl;
}


//ȡֵ����
void test05() {
	string s1 = "abcdefg";

	//����[]������
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << "  ";
	}
	cout << endl;

	//at��Ա����
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << "  ";
	}

	//����
	/*
	[] ��ʽ��������Խ�磬ֱ�ӹҵ�
	at��ʽ������Խ�磬���쳣out)of_range
	*/

	try
	{
		//cout << s1[100] << endl;
		cout << s1.at(100)<< endl;
	}
	catch (...)
	{
		cout << "Խ��" << endl;
	}


}

//���Ҳ���
void test06() {

	string s = "abcdefgk";
	//���ҵ�һ�γ���λ��
	int  pos = s.find("fg");
	//�������һ�γ���λ��
	int pos2 = s.rfind("fg");
	cout << pos << endl;
	cout << pos2 << endl;
}

//string �滻
void test07() {
	string s = "abcdefgk";
	s.replace(0, 2, "111");
	cout << s << endl;
}

//string �Ƚ�
void test08() {
	string s1 = "abcd";
	string s2 = "abce";

	if (s1.compare(s2) == 0) {
		cout << "���" << endl;

	}
	else {
		cout << "�����" << endl;

	}
}

//�Ӵ�����
void test09() {
	string s = "abcdefg";
	//�ӵڼ���λ�ÿ�ʼ ȡ����
	string mysub = s.substr(0,2);
	cout << mysub << endl;
}

//�����ɾ��
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