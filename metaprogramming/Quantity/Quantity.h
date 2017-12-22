#include "IntList_Zip_Impl.h"

template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
using Dimension = IntList<m, kg, s, A, K, mol, cd>;

using NumberQ   = Quantity<Dimension<>>;          // число без размерности
using LengthQ   = Quantity<Dimension<1>>;          // метры
using MassQ     = Quantity<Dimension<0, 1>>;       // килограммы
using TimeQ     = Quantity<Dimension<0, 0, 1>>;    // секунды
using VelocityQ = Quantity<Dimension<1, 0, -1>>;   // метры в секунду
using AccelQ    = Quantity<Dimension<1, 0, -2>>;   // ускорение, метры в секунду в квадрате
using ForceQ    = Quantity<Dimension<1, 1, -2>>;   // сила в ньютонах
//...

// реализация класса Quantity
template<typename IList>
class Quantity {

	double value_;
public:
	using type_of_dimension = IList;
	double value() const noexcept {
		return value_;
	}

	Quantity() {}
	explicit Quantity(double val) : value_(val) {}

	Quantity& operator=(const Quantity&) = default;
	Quantity(const Quantity&) = default;
};

namespace meta_functions {
	// бинарная метафункция
	template<int a, int b>
	struct Plus
	{
		static int const value = a + b;
	};
	template<int a, int b>
	struct Minus
	{
		static int const value = a - b;
	};
}

// operator +
template<typename IL>
Quantity<IL> operator+(const Quantity<IL>& left, const Quantity<IL>& right)
{
	return Quantity<IL>(left.value() + right.value());
}

Quantity<Dimension<>> operator+(const Quantity<Dimension<>>& left, double right) {
	return Quantity<Dimension<>>(left.value() + right);
}

Quantity<Dimension<>> operator+(double left, const Quantity<Dimension<>>& right) {
	return Quantity<Dimension<>>(left + right.value());
}

// operator -
template<typename IL>
Quantity<IL> operator-(const Quantity<IL>& left, const Quantity<IL>& right)
{
	return Quantity<IL> (left.value() - right.value());
}

Quantity<Dimension<>> operator-(const Quantity<Dimension<>>& left, double right) {
	return Quantity<Dimension<>>(left.value() - right);
}

Quantity<Dimension<>> operator-(double left, const Quantity<Dimension<>>& right) {
	return Quantity<Dimension<>>(left - right.value());
}


template<typename IL1, typename IL2>
using return_type_operator_multiply = 
	Quantity<typename Zip<IL1, IL2, meta_functions::Plus>::type>;

template<typename IL1, typename IL2>
using return_type_operator_division = 
	Quantity<typename Zip<IL1, IL2, meta_functions::Minus>::type>;

// operator *
template<typename IL1, typename IL2>
return_type_operator_multiply<IL1, IL2> 
	operator*(const Quantity<IL1>& left, const Quantity<IL2>& right)
{
	return return_type_operator_multiply<IL1, IL2>(left.value() * right.value());
}
template<typename IL>
Quantity<IL> operator*(const Quantity<IL>& left, double right) {
	return Quantity<IL>(left.value() * right);
}
template<typename IL>
Quantity<IL> operator*(double left, const Quantity<IL>& right) {
	return Quantity<IL>(left * right.value());
}

// operator /
template<typename IL1, typename IL2>
return_type_operator_division<IL1, IL2> 
	operator/(const Quantity<IL1>& left, const Quantity<IL2>& right)
{
	return return_type_operator_division<IL1, IL2>(left.value() / right.value());
}
template<typename IL>
Quantity<IL> operator/(const Quantity<IL>& left, double right) {
	return Quantity<IL>(left.value() / right);
}
template<typename IL>
return_type_operator_division<Dimension<>, IL> operator/(double left, const Quantity<IL>& right) {
	return return_type_operator_division<Dimension<>, IL>(left / right.value());
}
