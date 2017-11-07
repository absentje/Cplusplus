#ifndef _READER_H__
#define _READER_H__
#include <tuple>
#include <fstream>

template <typename... Args>
class Reader {
	std::tuple<Args...> Tuple;
	std::ifstream fin;

	template <size_t... I>
	void setTupleElements(std::index_sequence<I...>);

	template<size_t I>
	bool getFromFile();
public:
	Reader(const char *NameOfFile);
	std::tuple<Args...> getTuple() const;
	~Reader();
};

#include "Reader_Impl.h"

#endif //_READER_H__
