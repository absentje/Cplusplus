#include "IntList.h"

// Определение метафункции Zip, которая принимает два списка целых чисел одинаковой длины, 
// а так же бинарную метафункцию, и возвращает список, получившийся в результате 
// поэлементного применения метафункции к соответствующим элементам исходных списков.

template<typename L1, typename L2, template<int, int> class MetaFunc>
struct Zip;

template<typename L1, typename L2, template<int, int> class MetaFunc>
struct Zip {
private:
	static const int result = MetaFunc<L1::Head, L2::Head>::value;
	using pre_Zip_type = typename Zip<typename L1::Tail, typename L2::Tail, MetaFunc >::type;
public:
	using type = typename IntCons<result, pre_Zip_type>::type;
};

template<template<int, int> class MetaFunc>
struct Zip<IntList<>, IntList<>, MetaFunc> {
	using type = IntList<>;
};
