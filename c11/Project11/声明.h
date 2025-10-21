#pragma once
//封装——对内数据开放，逻辑抽象，对外,提供接口

//	C语言的封装风格 数据放到一起打包 struct 
//然后把数据以引用或指针的方式传给行为

//	C++认为C 封装不彻底。 
//数据和行为分类，无权限控制。
//权限控制 rivate  public
//数据行为在一起 =>>对内数据开放，逻辑抽象  对外,提供接口
//类 ==>类对象 ==>由对象调用行为
//声明和实现要分开  (声明)

#include <iostream>
using namespace std;
class MyClass//类 类名其实也是一种变向的命名宝间
{
public://共有的 C语言默认 
	void print();//函数
	void init();
	bool Is_leap_year();
	int get_year(); 

private://私有的	C艹语言默认 
	int year;//数据
	int month;
	int day;
};