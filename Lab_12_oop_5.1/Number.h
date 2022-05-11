#pragma once
#include "NumberException.h"
#include <iostream>
using namespace std;

class Number
{
	int first;
	unsigned int second;
public:
	Number(int f = 0, unsigned int s = 0) throw(NumberException);
	Number(const Number& n);
	int getFirst() const { return first; }
	unsigned int getSecond() const { return second; }

	void multiply(double value);

	operator string() const;
	Number& operator--();
	Number& operator++();
	Number operator--(int) throw(int);
	Number operator++(int);
	Number& operator=(const Number& n);
	friend ostream& operator<<(ostream& out, const Number& n);
	friend istream& operator>>(istream& in, Number& n) throw(exception);
private:
	unsigned numberSecondDigits() const;
};
