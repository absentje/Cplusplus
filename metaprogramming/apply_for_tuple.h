#include <tuple>
#include "IntList.h"

// определение функции apply,
// которая принимает функтор и кортеж с аргументами для вызова этого функтора и вызывает функтор от этих аргументов.

template< typename Func, typename Tuple, int... Args >
auto exc_func(IntList<Args...>, const Func& func, const Tuple& tuple_)
//->decltype(func(std::get<Args>(tuple_)...)) - for C++11
{
	return func(std::get<Args>(tuple_)...);
};

template<typename Func, typename... Types>
auto apply(const Func& func, const std::tuple<Types...>& tuple_)
//->decltype(exc_func(typename Generate<sizeof...(Types)>::type(), func, tuple_)) - for C++11
{
	return exc_func(typename Generate<sizeof...(Types)>::type(), func, tuple_);
}
