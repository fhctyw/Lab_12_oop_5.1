#include <Windows.h>
#include "Number.h"
#include <iostream>
using namespace std;

Number makeNumber(int f, unsigned int s) throw(int, bad_exception)
{
	if (s > 999)
		throw "ERROR";
	Number n(f, s);
	return n;
}

void F()
{
	throw;
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_unexpected(F);

	Number n;
	try {
		cin >> n;
		cout << n << endl;
	}
	catch (NumberException e)
	{
		cout << "NumberException " << e.what() << endl;
	}
	
	try {
		n--;
		cout << n << endl;
	}
	catch (exception& e)
	{
		cout << "exception& " << e.what() << endl;
	}
	int f;
	unsigned int s;
	try {
		cin >> f;
		cin >> s;
		n = Number(f, s);
		cout << n << endl;
	}
	catch (int* n)
	{
		cout << "int* " << n << " " << *n << endl;
	}
	try {
		
		cin >> f;
		cin >> s;
		cout << makeNumber(f, s) << endl;
	}
	catch (bad_exception b)
	{
		cout << "bad_exception " << b.what() << endl;
	}

	return 0;
}
