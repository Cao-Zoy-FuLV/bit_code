//��װ�����������ݿ��ţ��߼����󣬶���,�ṩ�ӿ�

//	C���Եķ�װ��� ���ݷŵ�һ���� struct 
//Ȼ������������û�ָ��ķ�ʽ������Ϊ

//	C++��ΪC ��װ�����ס� 
//1. ���ݺ���Ϊ���࣬��Ȩ�޿��ơ�
//2. ������Ϊ�ֿ�

//Ȩ�޿��� rivate  public
//������Ϊ��һ�� =>>�������ݿ��ţ��߼�����  ����,�ṩ�ӿ�
//�� ==>����� ==>�ɶ��������Ϊ
//������ʵ��Ҫ�ֿ�

#include "����.h"
int main1()
{
	MyClass C;// C �������
	C.init();
	C.print();
	if (C.Is_leap_year())
		cout << C.get_year() << "  IS leap year" << endl;
	else
		cout << C.get_year() << "  IS not leap year" << endl;
	return 0;
}


//��װջ
//���������������� �����б�
#include "zhan.h"
int main2()
{
	//Zhan z;
	Zhan z(1);//����1�� char �ڴ�ռ�
	//Zhan z()�뺯��������ͻ
	for (char a = 'a'; !z.is_full() && a != 'z' + 1; a++)
		z.push(a);
	while (!z.is_empty())
		cout << z.pop() << "  ";
	cout << endl;

	Zhan* ps1 = new Zhan;//�޲ι�����������
	delete ps1;
	Zhan* ps2 = new Zhan(2);//�޲ι�����������
	delete ps2;
	//�ȹ���ĺ��������������������
	return 0;
}


//��װ����
#include"list.h"
int main3() {
	List list;
	list.inserertList("��");
	list.inserertList("�������");
	list.inserertList("��");
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


// -----------72 һ��̨�ľ݊���һӦ����һת�ͱ�һ
#include"reverse_list.h"
int main()
{
	ListNode n5 = { 5,nullptr };
	ListNode n4 = { 4,&n5 };
	ListNode n3 = { 3,&n4 };
	ListNode n2 = { 2,&n3 };
	ListNode n1 = { 1,&n2 };
	ListNode* list_node = &n1;

	//��ӡ�б�
	ListNode* np = list_node;
	while (np)
	{
		cout << np->value << " - > ";
		np = np->next;
	}
	cout << "NLLL" << endl;

	//��������ָ�룬һ��ָ��ǰ�����Ľڵ㣬��һ��ָ��֮ǰ�Ľڵ�
	ListNode* curr = list_node;//��ǰ�����Ľڵ�
	ListNode* prev = nullptr;//֮ǰ�Ľڵ�

	//��ת�б�
	while (curr)
	{
		//����ʱ����ָ����һ���ڵ��ָ��
		ListNode* temp = curr->next;

		curr->next = prev;
		// ����ָ�붼��ǰ��
		prev = curr;
		curr = temp;
	}

	//��ӡ���б�
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