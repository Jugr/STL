#pragma once   //防止头文件被重复包含

//#ifndef PERSON_H  //ifndef  防止头文件被重复包含  //转换大写 选中字符 ctrl+shift+U
//#define PERSON_H
//#endif
#include<iostream>
#include<string>
using namespace std;

//.h作声明

class Person {

public:
	string mName;
	int mAge;
	int mId;
public:
	Person(string name, int age);
	void Show();
};