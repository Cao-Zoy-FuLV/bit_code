#pragma once
#include <iostream>
using namespace std;
class String
{
public:
	String(const char* p=NULL);//Ĭ�ϲ���ֻ����������
	//			����������������һ��������������һ������
	//  1.	�ɼ����ڵĶ��󴴽��¶���Ҳ�����¶��󣬲��ɹ����������죬
	//�����ɿ�������������ɵģ������������ĸ�ʽ�ǹ̶��ġ�
	//class ����
	//{
	//		���� (const ����& another){����������}
	// }
	//	2. �����ṩ��ϵͳ����Ĭ�ϣ��ɹ����룩��һ���Զ��壬ϵͳ�����ṩĬ�ϡ�
	//	3. ϵͳ�ṩ��Ĭ�ϣ���һ�ֵ�λ������Ҳ���ǽ���˵�ģ�ǳǳ�Ŀ�����
	//	4. ǳ�������ᵼ�£��ڴ��������� double free.
	//����Щ����£����жѿռ��ʱ��)��Ҫ��ʵ�ֿ�������
	String(const String& another); //����������
	







	//		��ֵ��������� ��=��
	//	1. ��һ�����еĸ�����һ�����ж���ֵ��������������������������ĸ�ֵ��Ϊ
	//����
	//{
	//		����& operator=(const ����& Դ����
	//			������
	//}
	//	2. �����ṩĬ�ϡ�����ɹ���ԭ��,һ���Զ��壬ϵͳ�����ṩĬ�ϡ�
	//	3. Ĭ�ϸ�ֵ���������,Ҳ��һ�ֵ�λ��ֵ,ǳ��ֵ
	//	4. ǳ��ֵ,�п��ܵ���:
	//		4.1 �����ڴ�й©��
	//		4.2 �ڴ淢���ع���
	//		4.3 �Ը�ֵ�� 
	String& operator=(const String& another);	
	String operator+(const String& another);
	bool operator>(const String& another);
	bool operator<(const String& another);
	bool operator==(const String& another);
	char& operator[](int idx);
	char at(int idx);
	
	
	char* char_s();
	~String();

private:
	char* _s;
};

