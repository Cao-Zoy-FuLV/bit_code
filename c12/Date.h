//
// Created by Administrator on 2026/3/4.
//

#ifndef BIT_CODE_DATA_H

#define BIT_CODE_DATA_H

#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
    friend  ostream& operator<<(ostream& os, const Date& d);
    friend  istream& operator>>(istream& is, Date& d);

public:
    //const成员函数
    //将const修饰的成员函数称之为const成员函数，const修饰成员函数放到成员函数参数列表的后面
    //函数调用的时候，会自动将const对象作为参数
    //bool CheckDate(const bool const *this);
    bool CheckDate() const;

    Date(int year = 1900, int month = 1, int day = 1);
    void Print() const;

    //类里定义默认是内敛inlined
    int GetMonthDay(int year, int month) const
    {
        assert(month >0 && month <= 13);
        static int month_day[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29;
        }
        return month_day[month];
    }

    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);

    Date& operator+=(int day);
    Date operator+(int n);

    Date& operator-=(int n);
    Date operator-(int n);

    //d1++
    //d1.operator(整数)
    Date operator++(int);
    //++d1
    //d1.operator()
    Date operator++();

    Date operator--(int);
    Date operator--();

    int operator+(const Date& d);
    int operator-(const Date& d);


private:
    int _year;
    int _month;
    int _day;
};


#endif //BIT_CODE_DATA_H
