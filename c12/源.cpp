
#include "String.h"
#include "this_zz.h"
int main1()
{
	String s1;
	String s2("�Ҳ��������");
	cout << s1.char_s();
	cout << s2.char_s() << endl;

	//����������������һ��������������һ������
	String s3(s2);
	cout << s3.char_s() << endl;
	String s4 = s3;//���ʣ����������������ü���һ���������һ��������޵��еĴ�������
	cout << s4.char_s() << endl;

	this_zz _this(20, "�Ҳ������", "��");
	_this.display();
	_this.grow_up().grow_up().grow_up().display();//��ʽ���

	//��ֵ��������� ��=��
	String s5;
	//s5 = s4;//==>s5.operator = (s4);
	s5 = s4 = s3 = s2 = s1;//==>s5.operator =(s4.operator=(s3.operator=(s2.operator=(s1))));
	//(s5 = s4)=s3//s3=>(main�ռ��ջ�ϵ���ʱ�ռ�) s4=>s5 (��ʱ�ռ�)=>s5
	cout << s5.char_s() << endl;
	cout << s3.char_s() << endl;
	
	String x = "�Ҳ������ ", y = "��";
	String z = x + y;
	cout << z.char_s() << endl;
	if (x == y)
		cout << " x = y " << endl;
	if (x > y)
		cout << " x > y " << endl;
	if (x < y)
		cout << " x < y " << endl;
	x[8] = 'S';
	cout << x[8] << endl;
	return 0;
}

//����������������ʱ��
//  1�� �����¶���  This This_a�� This This_b = This_a;
//  2�� ���λ򷵻ضԽ�
//������ͨ������˵��������Ч�������ԡ�
//�����������ԣ�������Ч�ʺܸߡ�
//�����õȼ��ڣ�������ԭ�����������
void fun1(This& This_1) {}//������(&This_1)Ч�ʸ�
//����
int main2()
{
	This This_a;
	This This_b = This_a;
	fun1(This_a);
	return 0;
}
//ջ�ϵĶ����ǿ��Է��صģ������ܻ�ջ�ϵ����á����Ƿ��ض�����
This fun2(This& This_1) { return This_1; }
int main3()
{
	This This_a;
	//���÷���ʱ,�ֿ��ٿռ���main����ջ��
	This This_b;
	This_b = fun2(This_a);
	return 0;
}
//����2
This fun3() { This This_1; return This_1; }
int main4()
{
	This This_a;
	This_a = fun3();
	cout << "This_a �ĵ�ַ" << &This_a << endl;
	return 0;
}