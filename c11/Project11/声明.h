#pragma once
//��װ�����������ݿ��ţ��߼����󣬶���,�ṩ�ӿ�

//	C���Եķ�װ��� ���ݷŵ�һ���� struct 
//Ȼ������������û�ָ��ķ�ʽ������Ϊ

//	C++��ΪC ��װ�����ס� 
//���ݺ���Ϊ���࣬��Ȩ�޿��ơ�
//Ȩ�޿��� rivate  public
//������Ϊ��һ�� =>>�������ݿ��ţ��߼�����  ����,�ṩ�ӿ�
//�� ==>����� ==>�ɶ��������Ϊ
//������ʵ��Ҫ�ֿ�  (����)

#include <iostream>
using namespace std;
class MyClass//�� ������ʵҲ��һ�ֱ������������
{
public://���е� C����Ĭ�� 
	void print();//����
	void init();
	bool Is_leap_year();
	int get_year(); 

private://˽�е�	Cܳ����Ĭ�� 
	int year;//����
	int month;
	int day;
};