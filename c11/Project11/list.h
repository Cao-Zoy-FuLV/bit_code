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
	List();//������
	void inserertList(string d);
	void traverseList();
	~List();// ������

private:
	Node* head;
};

