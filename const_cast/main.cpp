//  использование const_cast<dataType>(val)
//	структура A нужна для корректного вывода
//	если использовать встроенный тип, компилятор оптимизацией кода
//	приведет к неопределенному поведению программы
//	(например, если вместо A указать int, output будет: 5 5)
#include <iostream>
using namespace std;

struct A {
	int a;
	A(int b) :a(b) {}
};

void f(const A& var) {
	A* ptr = const_cast<A*>(&var);
	ptr->a = 0;

}

int main() {
	A var(5);
	cout << var.a << endl;
	f(var);
	cout << var.a << endl;
	return 0;
}

// Output:
// 5
// 0
