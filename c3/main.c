#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*——————————————————————————————————————————结构体内存对齐————————————————————————————————————————
 对齐数 = 编译器默认的一个对齐数 与 该成员变量大小的较小值。
 VS 中默认的值为 8
 Linux中 gcc 没有默认对齐数，对齐数就是成员自身的大小
 如果嵌套了结构体的情况，嵌套的结构体成员对齐到自己的成员中最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体中成员的对齐数）的整数倍。
 原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问
 */
struct S1
{
    char c1; // 1
    int i; // 4
    char c2; // 1
};

//  c1 ___ i***  c2
//  1      4     9  sizeof（） 为最大的 i 整数倍 9-->12
struct S2
{
    char c1; // 1
    char c2; // 1
    int i; // 4
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
struct S4
{
    char c1;
    struct S3 s3;
    double d;
};

//   c1 ____  ____(跳过s3中最大对齐数 d 的整数倍8) s3*16 d*** ****
//   1                                        9     25          sizeof（） 为最大的 s3 最大对其数 d->8 整数倍 32 -->32

//柔性数组
//C99 中，结构中的最后一个元素允许是未知大小的数组（*前面必须至少一个其他成员），这就叫做『柔性数组』成员
//包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

struct S5
{
    int i;
    char arr[]; //柔性数组成员
} type_a;

//结构体
void main0()
{
    printf("%d\n", sizeof(struct S1)); //12
    printf("%d\n", sizeof(struct S2)); //8
    printf("%d\n", sizeof(struct S3)); //16
    printf("%d\n", sizeof(struct S4)); //32
    printf("%d\n", sizeof(struct S5)); //4
}

//那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到： 让占用空间小的成员尽量集中在一起s


/*
位段的内存分配
1. 位段的成员可以是int unsigned int signed int 或者是char 等类型
2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
*/
struct S
{
    unsigned int a : 1;
    int b : 4;
    int c : 5;
    int d : 4;
};

int main1()
{
    struct S s = {0};
    s.a = 1;
// 判断内存存储的方式 大端存储 & 小端存储
    //1 内存段位判断
    if (s.a == 1) {
        printf("小端存储  ");
    } else {
        printf("大端存储  ");
    }
    //  2 指针+取地址
    int num = 1;
    char* p = (char*)&num;
    if (*p == 1) {
        printf("小端存储\n");
    } else {
        printf("大端存储\n");
    }
    s.b = 3;
    s.c = 8;
    s.d = 16;//截断
    printf("%d %d %d %d \n", s.a, s.b, s.c, s.d);
    /*
        位段的几个成员共有同一个字节，这样有些成员的起始位置并不是某个字节的起始位置，那么这些位
    置处是没有地址的。内存中每个字节分配一个地址，一个字节内部的bit位是没有地址的。
    所以不能对位段的成员使用&操作符，这样就不能使用scanf直接给位段的成员输入值，只能是先输入
    放在一个变量中，然后赋值给位段的成员。
     */
    int b = 0;
    scanf("%d", &b);
    // s.b = b;
    printf("%d %d %d %d\n", s.a, s.b, s.c, s.d);
    return 0;
}

/* ——————————————————————————————————————联合体————————————————————————————————
联合体的特点是所有成员共用同一块内存空间 ，所以联合体也叫：共用体。
联合体成员不能有初始值，给联合体其中一个成员赋值，其他成员的值也跟着变化。
联合体成员不能有地址，不能使用sizeof()获取联合体的大小。联合的大小至少是最大成员的大小当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。


* 使用联合体是可以节省空间的，举例：
比如，我们要搞一个活动，要上线一个礼品兑换单，礼品兑换单中有三种商品：图书、杯子、衬衫。
每一种商品都有：库存量、价格、商品类型和商品类型相关的其他信息。
 */
struct gift_list
{
    int stock_number;//库存量
    double price; //定价
    int item_type;//商品类型
    union {
        struct
        {
            char title[20];//书名
            char author[20];//作者
            int num_pages;//页数
        }book;
        struct
        {
            char design[30];//app
        }mug;
        struct
        {
            char design[30];//设计
            int colors;//颜色
            int sizes;//尺寸
        }shirt;
    }item;
};
//联合体判断大小端
int check_sys()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c; //返回1是小端，返回0是大端
}
int main2()
{
    struct gift_list g;
    g.stock_number = 10;
    g.price = 10.5;
    g.item_type=114514;
    strcpy(g.item.book.title, "C++");
    strcpy(g.item.book.author, "long");
    g.item.book.num_pages = 100;
    printf(" 价格 %f 库存数 %d 商品类型 %d  页数 %d  书名 %s 作者 %s ",
        g.price,g.stock_number, g.item_type,g.item.book.num_pages, g.item.book.title, g.item.book.author);
    printf("大小%d \n" ,sizeof(g) );
    g.stock_number = 20;
    g.price = 20.5;
    g.item_type=1145141;
    strcpy(g.item.mug.design, "C++程序");
    printf(" 价格 %f 库存数 %d 商品类型 %d  app %s ",
        g.price,g.stock_number, g.item_type,g.item.mug.design);
    printf("大小%d \n" ,sizeof(g));
    g.item.shirt.sizes=10;
    printf(" 新尺寸 %d ",g.item.shirt.sizes);
    printf("大小%d \n" ,sizeof(g));


    if (check_sys())
    {
        printf("小端存储\n");
    }
    else
    {
        printf("大端存储\n");
    }
    return  0;
}


int main()
{
    //gcc 支持__STDC__
    // printf("%d",__STDC__);
    // main0();
    // main1();
    // main2();

}
