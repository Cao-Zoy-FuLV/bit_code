#include "zhan.h"
//�����������
//void zhan::init()
//{
//    top = 0;
//    memset(arr, 0, 100);
//    //�����ַ� 0��һ���޷����ַ��������� arr ��ָ����ַ�����ǰ 100 ���ַ�"/0"ֹͣ
//    //memcpy(arr1,arr2,100)
//    //���ƴ洢�� arr2 ���洢�� arr1 ��ָ���ǰ 100 ���ֽ� ����Խ��
//}

bool Zhan::is_empty()
{
    return top==0;
}

bool Zhan::is_full()
{
    return top==_size;
}

//��ջ
char Zhan::pop()
{
    --top;
    return zhan[top];
}

//��ջ
void Zhan::push(char c)
{
    zhan[top] = c;
    top++;
}
