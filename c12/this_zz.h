#pragma once
#include <iostream>
using namespace std;

class this_zz
{
public:
	this_zz(int age,string str1, string str2)
		:str1(str1), str2(str2),age(age)//与下方同一个效果
	{
		//this->str1 = str1;
		//this->str2 = str2;
	}
	void display();
	this_zz& grow_up();
private:
	string str1;
	string str2;
	int age;
};


//this->
class This
{
public:
	This();
	This(const This& another);
	This& operator=(const This& another);
	~This();

private:

};

