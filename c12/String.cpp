#include "String.h"

String::String(const char* p)
{
	if (p == NULL)
	{
		_s = new char[1];
		*_s = '\0';
	}
	else
	{
		int len = strlen(p);
		_s = new char[len + 1];
		strcpy(_s, p);
	}
}

//String::String(const String& another)//默认拷贝构造器
////浅拷贝，会导致，内存重析构。 double free.
//{
//	//在同类之间，是没有隐私的可随意调用	
//	_s = another._s;
//	//在没有开辟新空间时默认优先
//}

String::String(const String& another)//拷贝构造器
{
	int len = strlen(another._s);
	_s = new char[len + 1];
	strcpy(_s, another._s);
}


String& String::operator=(const String& another)//赋值运算符重载 ‘=’
{
	if (this == &another)
		return*this;
	delete[]this->_s;
	int len = strlen(another._s);
	this->_s = new char[len + 1];
	strcpy(this->_s, another._s);
	return *this;
}

String String::operator+(const String& another)
{
	String tmp;
	delete[]tmp._s;
	int len = strlen(this->_s);
	len += strlen(another._s);
	tmp._s = new char[len + 1];
	memset(tmp._s, 0, len + 1);
	strcat(tmp._s, this->_s);
	strcat(tmp._s, another._s);
	return tmp;
}

bool String::operator>(const String& another)
{
	if (strcmp(this->_s, another._s) > 0)
		return true;
	else
		return false;
}

bool String::operator<(const String& another)
{
	if (strcmp(this->_s, another._s) < 0)
		return true;
	else
		return false;
}

bool String::operator==(const String& another)
{
	if (strcmp(this->_s, another._s) == 0)
		return true;
	else
		return false;
}

char& String::operator[](int idx)
{
	return this->_s[idx];
}

char String::at(int idx)
{
	return this->_s[idx];
}

char* String::char_s()
{
	return _s;
}

String::~String()
{
	delete[]_s;
}
