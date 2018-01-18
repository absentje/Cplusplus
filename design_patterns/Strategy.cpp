// Раскладывая классы на ортогональные стратегии(независящие друг от друга)
// мы предоставляем гибкость использования данных классов
// изменять код можно извне, не прибегая к изменению кода основного класса
// - можно изменить лишь саму стратегию(написав свою), и написав соответствующий
// typedef (или же используя using, с C++11)

template < class T >
struct NewCreator {
	static T* create() { return new T(); }
	static void destroy(T * t) { delete t; }
};
template < class T >
struct MallocCreator {
	static T* create() {
		void * buff = malloc(sizeof(T));
		if (buff == 0) return 0;
		return new (buff) T();
	}
	static void destroy(T * t) { t - >~T(); free(t); }
};
template < template <class T > CreationPolicy >
struct WidgetManager : protected CreationPolicy < Widget >
{
	...
};


using WidgetManaget_withNewCreator = WidgetManager<NewCreator>;
using WidgetManaget_withMallocCreator = WidgetManager<MallocCreator>;
