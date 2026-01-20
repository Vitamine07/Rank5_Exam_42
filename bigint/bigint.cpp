#include "bigint.hpp"
#include <string>

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num) : str(std::to_string(num)) {}

bigint::bigint(const bigint& other) : str(other.str) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        str = other.str;
    return (*this);
}

bigint::~bigint() {}

const std::string&   bigint::getStr()const
{
    return (str);
}

std::ostream&    operator<<(std::ostream &os, const bigint& big)
{
    os << big.getStr();
    return (os);
}

std::string reverse(const std::string& str)
{
    std::string rev;
    for (int i = str.length() - 1; i >= 0; i--)
        rev.push_back(str[i]);
    return (rev);
}

std::string& padding(const std::string& base, std::string& pad)
{
    int len1 = base.length();
    int len2 = pad.length();
    if (len2 < len1)
    {
        for (int i = 0; i < len1 - len2; i++)
            pad.push_back('0');           
    }
    return (pad);
}

bigint  bigint::operator+(const bigint& other)const
{
    int carry = 0;
    std::string res;
    bigint  ret;
    std::string str1 = reverse(str);
    std::string str2 = reverse(other.str);
    str1 = padding(str2, str1);
    str2 = padding(str1, str2);
    for (int i = 0; i < str1.length(); i++)
    {
        int sum = str1[i] - '0' + str2[i] - '0' + carry;
        if (sum > 9)
        {
            carry = 1;
            res.push_back(sum % 10 + '0');
        }
        else
        {
            res.push_back(sum + '0');
            carry = 0;
        }
    }
    if (carry != 0)
        res.push_back(carry + '0');
    ret.str = reverse(res);
    return (ret);
}

bigint& bigint::operator+=(const bigint& other)
{
    (*this) = (*this) + other;
    return (*this);
}

bigint& bigint::operator++()
{
    (*this) = (*this) + bigint(1);
    return (*this);
}

bigint  bigint::operator++(int)
{
    bigint  temp(*this);
    (*this) = (*this) + bigint(1);
    return (temp);
}