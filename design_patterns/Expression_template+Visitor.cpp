
//  Expression_template
string a(" Computer "), b(" Science "), c(" Center ");
string res = a + " " + b + " " + c; // не стоит использовать auto
template < class O1, class O2 >
struct string_expr {
	size_t size() const; // суммарная длина всех строк
	operator string () const; // склейка всех строк в одну
private:
	O1 & o1;
	O2 & o2;
};
string_expr < string, string >
operator +(string const & a, string const & b);
template < class O1, class O2 >
string_expr < string, string_expr <O1, O2 > >
operator +(string const & a, string_expr <O1, O2 > const & b);

// +Visitor

struct SizeVisitor {
	void visit(char const * s) { res_ += strlen(s); }
	void visit(string const & s) { res_ += s.size(); }
	template < class T >
	void visit(T const & t) { t.visit(*this); }
	size_t value() const { return res_; }
private:
	size_t res_ = 0;
};

struct string_expr {
	// ... то же описание, что и ранее
	template < class Visitor >
	void visit(Visitor & v) {
		v.visit(o1);
		v.visit(o2);
	}
public:
	size_t size() const {
		SizeVisitor v;
		visit(v);
		return v.value();
	}
}
