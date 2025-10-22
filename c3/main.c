#include <stdio.h>
// struct Stu
// {
//     char name[20];//名字
//     int age;//年龄
//     char sex[5];//性别
//     char id[20];//学号
// };
// int main()
// {
//     //按照结构体成员的顺序初始化
//     struct Stu s = { "张三", 20, "男", "20230818001" };
//     printf("name: %s\n", s.name);
//     printf("age : %d\n", s.age);
//     printf("sex : %s\n", s.sex);
//     printf("id : %s\n", s.id);
//     //按照指定的顺序初始化
//     struct Stu s2 = {.name = "lisi",  .sex = "女" , .age = 18, .id = "20230818002" };
//     printf("name: %s\n", s2.name);
//     printf("age : %d\n", s2.age);
//     printf("sex : %s\n", s2.sex);
//     printf("id : %s\n", s2.id);
//     return 0;
// }

//——————————————————————————————————————————结构体内存对齐————————————————————————————————————————
//对齐数 = 编译器默认的一个对齐数 与 该成员变量大小的较小值。
// VS 中默认的值为 8
// Linux中 gcc 没有默认对齐数，对齐数就是成员自身的大小
// 如果嵌套了结构体的情况，嵌套的结构体成员对齐到自己的成员中最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体中成员的对齐数）的整数倍。
// 原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问
struct S1
{
    char c1;    // 1
    int i;      // 4
    char c2;    // 1
};
//  c1 ___ i***  c2
//  1      4     9  sizeof（） 为最大的 i 整数倍 9-->12
struct S2
{
    char c1;    // 1
    char c2;    // 1
    int i;      // 4
};
//  c1 c2 __ i***
//  1  2     4       sizeof（） 为最大的 i 整数倍  8-->8
struct S3
{
    double d;
    char c;
    int i;
};
//  d*** **** c ___ i***
//          8 9     12   sizeof（） 为最大的 d 整数倍  16-->16
struct S4 {
    char c1;
    struct S3 s3;
    double d;
};
//   c1 ____  ____(跳过s3中最大对齐数 d 的整数倍8) s3*16 d*** ****
//   1                                        9     25          sizeof（） 为最大的 s3 最大对其数 d->8 整数倍 32 -->32
int main()
{
    printf("%d\n", sizeof(struct S1));//12
    printf("%d\n", sizeof(struct S2));//8
    printf("%d\n", sizeof(struct S3));//16
    printf("%d\n", sizeof(struct S4));//32

}
//那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到： 让占用空间小的成员尽量集中在一起s



