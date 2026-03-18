//
// Created by Administrator on 2026/3/4.
//

#include "Date.h"

bool Date::CheckDate()const
{
    if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;

    if (!CheckDate())
    {
        cout << "(���캯��)�������������" << endl;
        Print();
    }
}

void Date::Print() const
{
    cout << _year << " " << _month << " " << _day << endl;
}

//d1<d2
bool Date::operator<(const Date& d)
{
    if (_year < d._year)
    {
        return true;
    }
    else if (_year == d._year)
    {
        if (_month < d._month)
        {
            return true;
        }
        else if (_month == d._month)
        {
            return _day < d._day;
        }
    }
    return false;
}

bool Date::operator==(const Date& d)
{
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<=(const Date& d)
{
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d)
{
    return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
    return *this > d || *this == d;
}

bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}


Date& Date::operator+=(int day)
{
    if (day < 0)
    {
        return *this -= -day;
    }
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Date Date::operator+(int day)
{
    Date temp = *this;

    temp += day;
    /*while ( temp._day > GetMonthDay( temp._year, temp._month))
    {
        temp._day -= GetMonthDay( temp._year, temp._month);
        ++ temp._month;
        if ( temp._month == 13)
        {
             temp._year++;
             temp._month = 1;
        }
    }*/
    return temp;
}

//-����-=���Լ�ʵ��û�в���
//-=����-����3�ο���
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
        return *this += -day;
    }
    _day -= day;
    while (_day <= 0)
    {
        --_month;
        if (_month == 0)
        {
            _month = 12;
            --_year;
        }
        _day += GetMonthDay(_year, _month);
    }
    //-=����-����3�ο���
    /**this =*this - day;*/
    return *this;
}

Date Date::operator-(int day)
{
    Date temp = *this;
    temp -= day;
    // while (temp._day<=0)
    // {
    //     -- temp._month;
    //     if (temp. _month == 0)
    //     {
    //        temp. _month = 12;
    //         --temp._year;
    //     }
    //     temp._day += GetMonthDay(temp._year,temp._month);
    // }
    return temp;
}

//d1++
Date Date::operator++(int)
{
    Date temp = *this;
    *this += 1;
    return temp;
}

//++d1 ��һ�ο���
Date Date::operator++()
{
    *this += 1;
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    temp -= 1;
    return temp;
}

Date Date::operator--()
{
    *this -= 1;
    return *this;
}

int Date::operator+(const Date& d)
{
    return *this - d;
}

int Date::operator-(const Date& d)
{
    int flag = 1;
    Date max = *this;
    Date min = d;
    if (*this < d)
    {
        max = d;
        min = *this;
        flag = -1;
    }
    int n = 0;
    while (max != min)
    {
        ++min;
        ++n;
    }
    return n * flag;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d._year << "��" << d._month << "��" << d._day << "��" << endl;
    return os;
}

istream& operator>>(istream& is, Date& d)
{
    while (1)
    {
        std::cout << "����������������:>";
        is >> d._year >> d._month >> d._day;
        if (!d.CheckDate())
        {
            std::cout << "�������������";
            d.Print();
            std::cout << "����������:>";
        }
        else
        break;
    }

    return is;
}
