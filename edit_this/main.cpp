// меняем значение (A *const) this внутри метода класса
// т.е. наглядно показываем, что this - локальный объект, определенный неявно, внутри каждого метода класса

#include <iostream>
using namespace std;

class A {
public:
	int a;
	A* method(int* a);
	A* method();
};

A* A::method(int* a) {
	if (a)
		*a = 0;
	cout << this << endl;
	return this;
}
A* A::method() {
	return this;
}
int* f() {
	int s = 0;
	return &s;
}


int main() {
	int *p = 0;
	A q;
	p = f();
	cout << q.method(p);
	cout << endl;
	cout << q.method();
	return 0;
}
