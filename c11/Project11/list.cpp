#include "list.h"

List::List()
{
	head = new Node;
	head->next = NULL;
}
void List::inserertList(string d)
{
	Node* cur = new Node;
	cur->date = d;

	cur->next = head->next;
	head->next = cur;
}

void List::traverseList()
{
	Node* ph = head->next;
	while (ph != NULL)
	{
		cout << ph->date << endl;
		ph = ph->next;
	}
}
List::~List()
{
	Node* t = head;
	while (head)
	{
		head = head->next;
		delete t;
		t = head;
	}
}