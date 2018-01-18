//  Attorney-Client pattern позволяет предоставить ограниченный доступ требуемому классу,
//  в отличие от обычного использования friend(который дает полный доступ)

// Without Attorney-Client pattern
class Foo {
	void A(int a);
	void B(float b);
	void C(double c);
	friend class Bar;
};
// Needs access to Foo::A and Foo::B only
struct Bar { };


// With Attorney-Client pattern
class Client {
	void A(int a);
	void B(float b);
	void C(double c);
	friend struct Attorney;
};
class Attorney {
	static void callA(Client & c, int a) { c.A(a); }
	static void callB(Client & c, float b) { c.B(b); }
	friend struct Bar;
};
// Bar now has access to only Client::A and Client::B through the Attorney.
struct Bar { };
