#pragma once
#include <iostream>
using namespace std;


struct Node
{
	string date;
	struct Node* next;
};


class List
{
public:
	List();//ø’¡¥±Ì
	void inserertList(string d);
	void traverseList();
	~List();// «Â¡¥±Ì

private:
	Node* head;
};

