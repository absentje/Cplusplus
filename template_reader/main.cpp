#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>
#include <string>

#include "Reader.h"

int main()
{
	Reader<int, std::string, std::string> reader_("Data.txt");
	auto tuple = reader_.getTuple();
	const size_t TEST_VALUE = 0; // may: 0 <= TEST_VALUE <= tuple_size - 1
	std::cout << std::get<TEST_VALUE>(tuple);
	return 0;
}
