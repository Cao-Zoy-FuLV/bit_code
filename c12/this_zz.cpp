#include "this_zz.h"

void this_zz::display()
{
	cout << age << " �� " << str1 << " " << str2 << endl;
}

this_zz& this_zz::grow_up()
{
	this->age++;
	return *this;
}



This::This()
{
	cout << "��������ַ " << this << endl;
}

This::This(const This& another)
{
	cout << "��������ַ " << &another << " ������ " << this << endl;
}

This& This::operator=(const This& another)
{
	cout << this << " ������ " << &another << endl;
	return *this;
}

This::~This()
{
	cout << endl;
	cout << "��������ַ " << this << endl;
	cout << endl;
}