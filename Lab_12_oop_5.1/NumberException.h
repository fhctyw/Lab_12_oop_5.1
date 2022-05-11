#pragma once
#include <exception>
using namespace std;

class NumberException : public exception
{
public:
	NumberException(const char* const msg) : exception(msg) {};
};
