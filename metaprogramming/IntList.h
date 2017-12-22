// IntList - список целых чисел (int) времени компиляции

// Определение списка целых чисел времени компиляции IntList
template<int... Ints>
struct IntList;

template<int H, int... Ints>
struct IntList<H, Ints...> {
	static int const Head = H;
	using Tail = IntList<Ints...>;
};

template<>
struct IntList<> {};

// Определение метафункции Length для вычисления длины списка
template<typename IL>
struct Length;

template<int... Ints>
struct Length<IntList<Ints...>> {
	static int const value = sizeof...(Ints);
};

template<>
struct Length<IntList<> > {
	static int const value = 0;
};


// реализация метафункции IntCons
// IntCons позволяет увеличить список на один элемент — он добавляется в начало списка.
template <int H, typename IL>
struct IntCons;

template <int H, int... Ints>
struct IntCons<H, IntList<Ints...>> {
	using type = IntList<H, Ints...>;
};
// реализация метафункции IntPostCons
// IntPostCons позволяет увеличить список на один элемент — он добавляется в конец списка.
template <int H, typename IL>
struct IntPostCons;

template <int H, int... Ints>
struct IntPostCons<H, IntList<Ints...>> {
	using type = IntList<Ints..., H>;
};

// реализация метафункции Generate
// Generate позволяет сгенерировать список длины N с числами от 0 до N - 1.
template<size_t N>
struct Generate {
	using type = typename IntPostCons< N - 1, typename Generate<N - 1>::type >::type;
};

template<>
struct Generate<1> {
	using type = IntList<0>;
};
template<>
struct Generate<0> {
	using type = IntList<>;
};
