//封装——对内数据开放，逻辑抽象，对外,提供接口

//	C语言的封装风格 数据放到一起打包 struct 
//然后把数据以引用或指针的方式传给行为

//	C++认为C 封装不彻底。 
//1. 数据和行为分类，无权限控制。
//2. 数据行为分开

//权限控制 rivate  public
//数据行为在一起 =>>对内数据开放，逻辑抽象  对外,提供接口
//类 ==>类对象 ==>由对象调用行为
//声明和实现要分开

#include "声明.h"
int main1()
{
	MyClass C;// C 是类对象
	C.init();
	C.print();
	if (C.Is_leap_year())
		cout << C.get_year() << "  IS leap year" << endl;
	else
		cout << C.get_year() << "  IS not leap year" << endl;
	return 0;
}


//封装栈
//构造器，析构器， 参数列表
#include "zhan.h"
int main2()
{
	//Zhan z;
	Zhan z(1);//申请1个 char 内存空间
	//Zhan z()与函数申明冲突
	for (char a = 'a'; !z.is_full() && a != 'z' + 1; a++)
		z.push(a);
	while (!z.is_empty())
		cout << z.pop() << "  ";
	cout << endl;

	Zhan* ps1 = new Zhan;//无参构造器，标配
	delete ps1;
	Zhan* ps2 = new Zhan(2);//无参构造器，标配
	delete ps2;
	//先构造的后析构，后构造的先析构。
	return 0;
}


//封装链表
#include"list.h"
int main3() {
	List list;
	list.inserertList("梦");
	list.inserertList("阐述你的");
	list.inserertList("我");
	list.traverseList();
	return 0;
}

#include "myclock.h"
int main4()
{
	myclock c;
	c.run();
	return 0;
}


// -----------72 一复台菽据婁型一应用例一转裢表一
#include"reverse_list.h"
int main()
{
	ListNode n5 = { 5,nullptr };
	ListNode n4 = { 4,&n5 };
	ListNode n3 = { 3,&n4 };
	ListNode n2 = { 2,&n3 };
	ListNode n1 = { 1,&n2 };
	ListNode* list_node = &n1;

	//打印列表
	ListNode* np = list_node;
	while (np)
	{
		cout << np->value << " - > ";
		np = np->next;
	}
	cout << "NLLL" << endl;

	//定义两个指针，一个指向当前遍历的节点，另一个指向之前的节点
	ListNode* curr = list_node;//当前遍历的节点
	ListNode* prev = nullptr;//之前的节点

	//翻转列表
	while (curr)
	{
		//先临时保存指向下一个节点的指针
		ListNode* temp = curr->next;

		curr->next = prev;
		// 两个指针都向前动
		prev = curr;
		curr = temp;
	}

	//打印新列表
	ListNode* new_list_node = prev;
	np = new_list_node;
	while (np)
	{
		cout << np->value << " - > ";
		np = np->next;
	}
	cout << "NLLL" << endl;
	return 0;
}