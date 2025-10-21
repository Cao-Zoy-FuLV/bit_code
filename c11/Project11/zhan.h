#pragma once
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
class Zhan
{
public:
	//		构造器
	//	1. 与类名相同，无返回，被系统生成对象时自动调用，主要用于初始化。
	//	2. 如果没有提供构造器，系统默认生成一个无参的空构造器。
	//若提供，则不再生成造器
	//	3. 可有参数，可重载，可有默认参数，重载和默认参数不能同时存在,
	//包含默认参数，为了对象的无参创建。	
	Zhan(int size = 26)
		//参数列表在函数声明之后，实现体之前  ：开头   变量名(参数名)
		//参数列表，初始化顺序，跟变量的声明顺序有关，跟初始化表中的顺序无关
		:_size(size)	
	{
		cout << "构造器  “有参数 " << endl;
		//初始化
		top = 0;
		zhan = new char[size];
	}
	//Zhan()
	//{
	//	cout << " 构造器“与类名相同”  没有参数 " << endl;
	//	//初始化
	//	top = 0;
	//	zhan = new char [100];
	//}
	//
	//Zhan(int size)//重载构造器
	//{
	//	cout << " 构造器  “有参数 " << endl;
	//	//初始化
	//	top = 0;
	//	zhan = new char[size];
	//	_size = size;
	//}

	// void init();//（初始化）在构造器内完成
	
	//判空
	bool is_empty();
	//判满
	bool is_full();
	//出栈
	char pop();
	//进栈
	void push(char c);

	//		析构器
	//	1. 与类名相同，无参，无返回，在对象消失时
	//自动调用，用于对象销时的内存处理工作。
	//	2. 如果没有提供构造器，系统默认生成一个无参的空构造器。
	~Zhan()
	{
		delete zhan;
		cout << "析构器“无参数”  我阐述你的梦" << endl;
	}

private:
	char* zhan;
	int top;
	int _size;
};