#include "String.h"

namespace l
{
    const size_t String::npos = -1;

    String::String(const char* p)
    {
        _size = strlen(p);
        //_capacity 不包含/0
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, p);
    }


    String::String(const String& another)
    {//拷贝构造函数(现代版)
        String tmp(another._str);
        swap(tmp);
    }

    //赋值运算符重载 ‘=’
    // String& String::operator=(const String& another)
    // {
    //     if (this == &another)
    //         return *this;
    //     delete[]this->_str;
    //     // int len = strlen(another._str);
    //     this->_str = new char[another._capacity + 1];
    //     strcpy(this->_str, another._str);
    //     _size = another._size;
    //     _capacity = another._capacity;
    //     return *this; //返回值this 经典用法
    // }
    //现代版
    String& String::operator=(String another)
    {
        swap( another);
        return *this;
    }

    String String::operator+(const String& another)
    {
        String tmp;
        delete[]tmp._str;
        int len = strlen(this->_str);
        len += strlen(another._str);
        tmp._str = new char[len + 1];
        memset(tmp._str, 0, len + 1);
        strcat(tmp._str, this->_str);
        strcat(tmp._str, another._str);
        return tmp;
    }

    bool operator>(const String& s1, const String& s2)
    {
        return (strcmp(s1.char_s(), s2.char_s()) > 0);
    }

    bool operator>=(const String& s1, const String& s2)
    {
        return s1 <= s2 || s1 == s2;
    }

    bool operator<(const String& s1, const String& s2)
    {
        return (strcmp(s1.char_s(), s2.char_s()) < 0);
    }

    bool operator<=(const String& s1, const String& s2)
    {
        return s1 >= s2 || s1 == s2;
    }

    bool operator==(const String& s1, const String& s2)
    {
        return strcmp(s1.char_s(), s2.char_s()) == 0;
    }

    bool operator!=(const String& s1, const String& s2)
    {
        return !(s1 == s2);
    }

    String& String::operator+=(char str)
    {
        push_back(str);
        return *this;
    }

    String& String::operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const String& s)
    {
        for (auto e : s)
        {
            out << e;
        }
        return out;
    }

    std::istream& operator>>(std::istream& in, String& s)
    {
        s.clear();

        const int BUFFER_SIZE = 1024;
        char buff[BUFFER_SIZE];
        int i = 0;

        char tmp;
        tmp = in.get();
        while (tmp != '\n' /*&& tmp != ' '*/)
        {
            buff[i++] = tmp;
            if (i == BUFFER_SIZE - 1)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }
            tmp = in.get();
        }
        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }
        return in;
    }

    char& String::operator[](int pos)
    {
        assert(pos >= 0 && pos < _size);
        return this->_str[pos];
    }

    char String::at(int idx)
    {
        return this->_str[idx];
    }

    const char* String::char_s() const
    {
        return _str;
    }

    size_t String::size() const
    {
        return _size;
    }

    size_t String::capacity() const
    {
        return _capacity;
    }

    void String::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[]_str;
            _str = tmp;
            _capacity = n;
        }
    }

    void String::reservex2()
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
    }

    void String::push_back(char ch)
    {
        reservex2();
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0';
    }

    void String::append(const char* str)
    {
        size_t len = strlen(str);
        reservex2();
        strcpy(_str + _size, str);
        _size += len;
    }

    void String::insert(size_t pos, char ch)
    {
        assert(pos >= 0 && pos <= _size);
        reservex2();
        // 从后往前移动字符，避免覆盖未处理的数据
        // 使用 int 类型或者确保 size_t 在减到 0 后能正确终止循环
        // end 为 size_t (无符号)，当 end=0 时 --end 会溢出变成极大值，+1 防止越界访问
        size_t end = _size + 1;
        while (end > pos)
        {
            _str[end] = _str[end - 1];
            --end;
        }
        _str[pos] = ch;
        ++_size;
    }

    void String::insert(size_t pos, const char* str)
    {
        assert(pos >= 0 && pos <= _size);

        size_t len = strlen(str);
        if (len > _capacity - _size)
        {
            //大于2倍按需开，否则开2倍
            reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
        }
        size_t end = _size + len;
        while (end > pos + len - 1)
        {
            _str[end] = _str[end - len];
            end--;
        }
        for (size_t i = 0; i < len; i++)
        {
            _str[pos + i] = str[i];
        }
        _size += len;
    }

    void String::erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        if (len >= _size - pos)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            for (size_t i = 0; i <= _size - pos - len; i++)
            {
                _str[pos + i] = _str[pos + len + i];
            }
            _size -= len;
        }
    }

    size_t String::find(char ch, size_t pos) const
    {
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }

    size_t String::find(const char* str, size_t pos) const
    {
        assert(pos < _size);
        const char* p = strstr(_str + pos, str);
        return p ? p - _str : npos;
    }

    String String::substr(size_t pos, size_t len) const
    {
        assert(pos < _size);
        //如果输入的长度超过字符串的长度则更新下len
        if (len > _size - pos)
        {
            len = _size - pos;
        }
        String sub;
        sub.reserve(len);
        for (size_t i = 0; i < len; ++i)
        {
            sub += _str[pos + i];
        }
        return sub;
    }

    String::~String()
    {
        delete[]_str;
        _str = nullptr;
        _size = _capacity = 0;
    }
}
