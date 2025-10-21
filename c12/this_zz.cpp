#include "this_zz.h"

void this_zz::display()
{
	cout << age << " 岁 " << str1 << " " << str2 << endl;
}

this_zz& this_zz::grow_up()
{
	this->age++;
	return *this;
}



This::This()
{
	cout << "构造器地址 " << this << endl;
}

This::This(const This& another)
{
	cout << "构造器地址 " << &another << " 拷贝到 " << this << endl;
}

This& This::operator=(const This& another)
{
	cout << this << " 拷贝完 " << &another << endl;
	return *this;
}

This::~This()
{
	cout << endl;
	cout << "析构器地址 " << this << endl;
	cout << endl;
}