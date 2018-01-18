//  1. При изменении BookImpl нужно перекомпилировать
//    только реализацию класса Book.
//  2. Можно скрыть реализацию BookImpl: передать библиотеку
//    с классами Book и BookImpl и заголовочный файл
//  public.h.
//  3. При раздельной компиляции можно поддерживать
//    бинарную совместимость, если зафиксировать класс Book.

/* public .h */
struct Book {
	Book();
	~Book();
	void print();
private:
	struct BookImpl * p_;
};

/* private .h */
# include " public .h "
# include <iostream>
struct BookImpl {
	void print();
private:
	std::string contents_;
	std::string title_;
}
