#include "����.h"
void MyClass::print()//��Ϊ
{
	cout << "year:" << "month:" << "day" << endl;
	cout << year << ":" << month << ":" << day << endl;
}
void MyClass::init()//��Ϊ
{
	cin >> year;
	cin >> month;
	cin >> day;
}
bool MyClass::Is_leap_year()
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
int MyClass::get_year() 
{ 
	return year; 
}