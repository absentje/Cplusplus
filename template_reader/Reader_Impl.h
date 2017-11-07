#ifndef _READER_IMPL_H__
#define _READER_IMPL_H__
#include <tuple>
#include <fstream>

template <typename... Args>
template <std::size_t... I>
void Reader<Args...>::setTupleElements(std::index_sequence<I...>) {
	f_nothing(getFromFile<I>()...);
}

template <typename... Args>
template<size_t I>
bool Reader<Args...>::getFromFile() {
	fin >> std::get<(std::tuple_size_v<std::tuple<Args...>> - I - 1)>(Tuple);
	return true;
}


template <typename... Args>
std::tuple<Args...> Reader<Args...>::getTuple() const {
	return Tuple;
}

template <typename... Args>
Reader<Args...>::Reader(const char *NameOfFile) : fin(NameOfFile) {
	if (!fin.is_open())
		throw("File didn't open.");
	setTupleElements(std::make_index_sequence<std::tuple_size_v<std::tuple<Args...>>>{});
}

template <typename... Args>
Reader<Args...>::~Reader() {
	fin.close();
}
template<typename... Args>
void f_nothing(const Args&... a) {}

#endif //_READER_IMPL_H__
