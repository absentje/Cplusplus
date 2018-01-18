// собирать в динамической библиотеке (не в статической!)
// dll

struct Singleton
{
	static Singleton & instance()
	{
		static Singleton s;
		return s;
	}
	Singleton(Singleton const &) = delete;
	Singleton & operator =(Singleton const &) = delete;
private:
	Singleton() {}
};
