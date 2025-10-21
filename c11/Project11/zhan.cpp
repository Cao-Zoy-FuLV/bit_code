#include "zhan.h"
//构造器内完成
//void zhan::init()
//{
//    top = 0;
//    memset(arr, 0, 100);
//    //复制字符 0（一个无符号字符）到参数 arr 所指向的字符串的前 100 个字符"/0"停止
//    //memcpy(arr1,arr2,100)
//    //复制存储区 arr2 到存储区 arr1 所指向的前 100 个字节 不管越界
//}

bool Zhan::is_empty()
{
    return top==0;
}

bool Zhan::is_full()
{
    return top==_size;
}

//出栈
char Zhan::pop()
{
    --top;
    return zhan[top];
}

//进栈
void Zhan::push(char c)
{
    zhan[top] = c;
    top++;
}
