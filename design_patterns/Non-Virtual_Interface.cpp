// Non-virtual interface
// при изменении виртуальных методов в наследниках
// позволяет избежать дублирование кода
// (в отличие от случая, где виртуальный метод был бы публичным,
// в виртуальном публичном методе пришлось бы дублировать неполиморфный код)

struct Base {
	virtual ~Base() {}
	void show() { do_show(); }
	void load(std::string const & filename) {
		// Здесь можно проверить, существует ли файл
		do_load(filename);
		// Здесь можно проверить, валидны ли прочитанные данные
	}
	void save(std::string const & filename) {
		do_save(filename);
		// Здесь можно проверить, успешно ли прошла запись
	}
protected:
	virtual void do_show() = 0;
	virtual void do_load(std::string const & filename) = 0;
	virtual void do_save(std::string const & filename) = 0;
};
int main() {
	Base * b = new Derived();
	b->load(" ~/ Schema . xml ");
	b->show();
	b->save(" ~/ Schema . xml ");
}
