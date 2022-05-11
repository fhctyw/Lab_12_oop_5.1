#include "Number.h"
#include <sstream>
using namespace std;

Number::Number(int f, unsigned int s)
{
    first = f;
    if (s < 1000)
        second = s;
    else
        throw NumberException("дробова частина більше 1000");
}

Number::Number(const Number& n)
{
    *this = n;
}

void Number::multiply(double value)
{
    double d = first + second / 1000.;
    d *= value;
    first = d;
    second = (d - (int)d) * 1000;
}

Number::operator string() const
{
    stringstream ss;
    string zeros = "";
    for (size_t i = 0; i < 3 - numberSecondDigits(); i++)
        zeros += '0';
    ss << first << '.' << zeros << second;
    return ss.str();
}

Number& Number::operator--()
{
    --first;
    return *this;
}

Number& Number::operator++()
{
    ++first;
    return *this;
}

Number Number::operator--(int)
{
    Number n(*this);
    second--;
    if (second == (unsigned int) - 1)
        throw new int(-1);
    return n;
}

Number Number::operator++(int)
{
    Number n(*this);
    second++;
    return n;
}

Number& Number::operator=(const Number& n)
{
    first = n.first;
    second = n.second;
    return *this;
}

unsigned Number::numberSecondDigits() const
{
    return second > 0 ? (unsigned)log10((double)second) + 1 : 1;
}

ostream& operator<<(ostream& out, const Number& n)
{
    out << (string)n;
    return out;
}

istream& operator>>(istream& in, Number& n)
{
    cout << "Ціла частина: "; in >> n.first;
    cout << "Дробова частина: "; in >> n.second;
    if (n.second > 999)
        throw exception("дробова частина більше 1000");
    return in;
}
