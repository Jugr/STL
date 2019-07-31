#include<iostream>
#include<string>
using namespace std;

struct Student
{
	long id;
	int age;
	string name;
}s3;//初始化方法三：定义结构体时顺便创建


struct Teacher
{
	string name;
	Student s;
};

void myprint1(Student s);
void myprint2(Student* p);
int main7() {

	//初始化方法一**********************************************
	struct Student s1;
	s1.age = 18;
	s1.id = 139245;
	s1.name = "张三";
	//cout << s1.name << endl;

	//初始化方法二：
	struct Student s2 = { 3215324,13,"李四"};
	//cout << s2.id << endl;

	//初始化方法三
	s3.name = "王五";

	//结构体数组**************************************************************
	struct Student stuarr[3] = {
		{2324,12,"ds"},
		{2325,15,"ds1"},
		{25454,17,"ds2"}
	};
	/*for (int i = 0; i < 3; i++) {
		cout << stuarr[i].age<<"  "<< stuarr[i].id<< "  " << stuarr[i].name << endl;
	}*/

	//结构体指针****************************************************************

	Student s4 = { 3215324,13,"李四" };
	/*Student* p;
	p = &s4;*/
	Student * p = &s4;
	//cout << p->name << endl;

	//结构体嵌套****************************************************************
	struct Teacher t1;
	t1.name = "aa";
	t1.s.name = "bb";
	//cout << t1.s.name << endl;


	//结构体做函数参数*****************************************************
	//指传参
	//myprint1( s1);

	//地址传参
	//myprint2(&s1);



	system("pause");
	return 0;
}

void myprint1(Student s) {
	cout << s.name << endl;
}

//const修饰参数，防止地址传参时，参数被修改
void myprint2(const Student *p) {
	cout << p->name<< endl;
}
