#include <iostream>
using namespace std;

//		const 
// 1. �������ݳ�Ա 
//��ʼ��λ��ֻ���ڲ����б�����,���ε����ݳ�Ա�����ܱ��޸�
// 2. ���γ�Ա����,λ�ú�������֮��ʵ����֮ǰ,���������Ͷ��崦��Ҫ�� const ���� 
//	 const ������ŵ 
//�����޸����ݳ�Ա�ܷ��� const �ͷ� const ���ݳ�Ա,
//�������޸�,�� const ���ݳ�Ա,ֻ�ܷ��� const ��Ա������
//   ��������
// const ����ֻ�ܵ��� const ��Ա������
// �� const �������ȵ��÷� const ��Ա��������������� const ��Ա����
// 4. ���������
// const ���κ������ǴӺ����Ĳ��棬���޸����ݡ�
// const ���ζ����ǴӶ���Ĳ��棬���޸�����,ֻ�ܵ��� const ��Ա������
// 
class _const
{
public:
	_const(int val)
		:val(val) {}//constֻ���ڲ����б�����;
	void print1()
	{
		cout << val << endl;

	}
	void print2() const
	{
		cout << "const" << endl;
		//a=0  �����޸����ݳ�Ա
		int a = 0; //�����޸ľֲ�����
		//print1();ֻ�ܷ��� const ��Ա������
	}
	void print2()
	{
		cout << "not const" << endl;
	}
private:
	const int val;//�������ݳ�Ա
	int a = 0;
};
int main1()
{
	_const a(1);
	//a.print1();
	a.print2();
	const _const b(1);
	b.print2();
	return 0;
}



class _static;//ǰ��������
//class����Ԫ
class dis2//ǰ��������
{
public:
	void dis(_static& t);
};
//		static
//ȫ�ֱ��� ������ static ������,�������ļ�
//�ֲ����� auto ��������=main  
//�洢λ�ã�DATA �Σ�ȫ�ֳ�ʼ������������ų�ʼ����ȫ�ֱ����;�̬���� 
//			�� BSS �Σ�ȫ��δ��ʼ���������δ��ʼ����ȫ�ֱ����;�̬�������������н���ʱ�Զ��ͷ�
//			�� RW ��
//
// 1. static �����ڲ��ı�F������ʵ��������������ݹ���
//���ɶ����ʱ��static��Ա����������ʱ�򣬾ͼ��������˿ռ䣨data rw��������ͨ����Ա���пռ䡣
// static ���ݳ�Ա���������࣬Ҳ���ڶ��󣬵��չ�����
// 2. ��ʼ��
//���ڶ��壬�����ʼ���� type ����::������=ֵ
// 3. ���γ�Ա��������������ֻ��һ�������ڹ��� static ��Ա��
// static ���εĳ�Ա������������Ҳ���ڶ��󣬵��չ����ࡣ
//��Ϊ�������࣬����û�� this ָ��,���ܷ��ʷ� static ���ݳ�Ա�����Ա����
class _static
{
public:
	_static() {};

	void print()
	{
		cout << as << endl;
	}
	int& gat_x()
	{
		return x;
	}
	static int& gat_as()
	{
		//x=0;û��thisָ��
		return as;
	}
	friend void dis1(_static& t); //������ȫ�֣�Ҳ����ĳ�Ա��������������Ԫ����Ϊ��Ԫ������
	friend void dis2::dis(_static& t);//������Ԫ����
	friend class dis3;//��B����A����Ԫ���Ϳ���ӿ��A�ı����ü�A��private:���ݳ�Ա��

private:
	int x;
	int y;
	int z;
	static int as;

};
//ȫ�ֵ���Ԫ
void dis1(_static& t)
{
	cout << t.x << t.y << t.z << endl;
}
//��ĳ�Ա����
void dis2::dis(_static& t)
{
	cout << t.x << t.y << t.z << endl;
}
//��Ԫ��--��Ա����ȫΪ��Ԫ����
class dis3
{
public:
	void dis(_static& t)
	{
		cout << t.x << t.y << t.z << endl;
	}
};


int _static::as = 0;//ֻ���������ʼ��
int main()
{
	_static a, b, c;
	cout << "sizeof(_static) " << sizeof(_static) << endl;
	cout << "sizeof(a) " << sizeof(a) << endl;

	_static::gat_as() = 97;
	a.gat_x() = 1;
	b.gat_x() = 2;
	c.gat_x() = 3;
	a.gat_as()++;
	b.gat_as()++;
	c.gat_as()++;
	cout << a.gat_as() << endl;
	cout << _static::gat_as() << endl;

	//��Ԫ
	dis1(a);
	dis2 v; v.dis(a);
	dis3 n; n.dis(a);

	return 0;
}





class CCSprite
{
public:
	CCSprite(int d)
	{
		data = d;
		if (head == NULL)
		{
			this->next = NULL;
			head = this;
		}
		else
		{
			this->next = head->next;
			head = this;
		}
	}
	static void traverseCCSprit()
	{
		CCSprite* ph = head;
		while (ph != NULL)
		{
			cout << ph->data << endl;
			ph = ph->next;
		}
	}
	~CCSprite() {};
private:
	int data;
	CCSprite* next;
	static CCSprite* head;
	static const int a = 0; //��static const����ֻ�ܾ͵س�ʼ��
};
CCSprite* CCSprite::head = NULL;
int main3()
{
	CCSprite a(1), b(2), c(3);
	CCSprite::traverseCCSprit();
	cout << endl;
	for (size_t i = 0; i <= 9; i++)
	{
		new CCSprite(i);
		CCSprite::traverseCCSprit();
	}
	cout << endl;
	CCSprite::traverseCCSprit();


	return 0;
}

