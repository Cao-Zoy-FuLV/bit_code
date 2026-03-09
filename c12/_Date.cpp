//
// Created by Administrator on 2026/3/4.
//

#include "Date.h"
int main(int argc, char* argv[])
{
    Date d1(2001, 1, 1);
    d1.Print();

    Date d2(d1+100);
    d2.Print();

    Date d3(d2-100);
    d3.Print();

    std::cout << std::endl;

   Date d4=d1++;
    d4.Print();
    d1.Print();

   Date d5=++d3;
    d5.Print();
    d1.Print();

    Date d6(2026, 3, 9);
    Date d7(2026, 12, 20);
    std::cout << d7 - d6<< std::endl;

    Date d8, d9;
    std::cin>>d8 >> d9  ;
    std::cout << d8<< d9;
    std::cout << d8-d9<< std::endl;


    cin.get();
    cin.get();
    return 0;
}
