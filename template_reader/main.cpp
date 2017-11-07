#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>
#include <string>

#include "Reader.h"

int main()
{
	Reader<int, std::string, std::string> a("kek.txt");
	auto tuple = a.getTuple();
	std::cout << std::get<0>(tuple);
	return 0;
}
