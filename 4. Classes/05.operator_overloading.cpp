import std;
#include "class_header.h"

/*
	Which operators can be overloaded? Almost all, EXCEPT:
	-> . (member access)
	-> .* (pointer‑to‑member access)
	-> :: (scope resolution)
	-> ?: (ternary conditional)
	-> sizeof, typeid, alignof
	-> casting operators (e.g., static_cast) – these are special and not overloaded

	Rules:
	-> You cannot change the precedence or associativity of an operator.
	-> You cannot change the arity (number of operands) of an operator.
	-> You cannot invent new operators (e.g., ** for exponentiation).
	-> At least one operand must be a user‑defined type (to avoid changing built‑in behavior).
	-> Some operators must be overloaded as member functions: =, [], (), ->, and type 
	   conversion operators.
	-> Most binary operators can be overloaded either as member functions or as non‑member 
	   functions (often friends).
*/



/*
	This class demonstrates arithmetic, compound assignment, unary, increment/decrement, 
	subscript, function call, comparison, and stream operators
*/
class Complex{
private:
	double m_real{};
	double m_imag{};
public:
	// Constructor with default arguments – can be called with zero, one, or two arguments.
	Complex(double real = 0.0, double imag = 0.0) : m_real{real}, m_imag{imag}{}

	// Accessors(getters) – useful for non‑member functions that need the values.
	double real() const{
		return m_real;
	}
	double imag() const{
		return m_imag;
	}

	// MEMBER OPERATOR OVERLOADS

	// Binary addition (member version)
	// Returns a new Complex object. Marked const because it does not modify *this.
	Complex operator+(const Complex& rhs) const{
		return Complex{m_real + rhs.m_real, m_imag + rhs.m_imag};
	}
	// Binary subtraction (member version)
	Complex operator-(const Complex& rhs) const{
		return Complex{m_real - rhs.m_real, m_imag - rhs.m_imag};
	}
	// Binary multiplication (member version)
	Complex operator*(const Complex& rhs) const{
		return Complex{
			m_real * rhs.m_real - m_imag * rhs.m_imag,
			m_real * rhs.m_imag + m_imag * rhs.m_real
		};
	}
	// Binary division(member version)
	Complex operator/(const Complex& rhs) const{
		double denominator = rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag;
		return Complex{
			(m_real * rhs.m_real + m_imag * rhs.m_imag) / denominator,
			(m_imag * rhs.m_real - m_real * rhs.m_imag) / denominator
		};
	}

	// Compound addition (+=)
	// Modifies *this, so returns a reference to allow chaining (e.g., a += b += c).
	Complex& operator+=(const Complex& rhs){
		m_real += rhs.m_real;
		m_imag += rhs.m_imag;
		return *this;	// return reference to the modified object
	}
	// Compound subtraction (-+)
	Complex& operator-=(const Complex& rhs){
		m_real -= rhs.m_real;
		m_imag -= rhs.m_imag;
		return *this;
	}
	// Compound multiplication (*=)
	Complex& operator*=(const Complex& rhs){
		// Reuse the multiplication operator to avoid code duplication.
		*this = *this * rhs;
		return *this;
	}
	// Compound division (/=)
	Complex& operator/=(const Complex& rhs) {
		*this = *this / rhs;
		return *this;
	}

	// Assignment operator (=)
	/*
		The compiler generates a default version that does memberwise copy,
		but we show an explicit one with self‑assignment check.
	*/
	Complex& operator=(const Complex& rhs){
		// Guard against self assignment
		if(this != &rhs){
			m_real = rhs.m_real;
			m_imag = rhs.m_imag;
		}
		return *this;
	}
	// Unary minus
	Complex operator-() const {
		return Complex{-m_real, -m_imag};
	}
	// Unary plus (rarely used, but possible)
	Complex operator+() const {
		return *this;   // just return a copy
	}

	// Prefix increment (++c)
	// Returns a reference to the modified object.
	Complex& operator++() {
		++m_real;
		return *this;
	}
	// Postfix increment (c++)
	// The dummy int parameter distinguishes postfix from prefix.
	// Returns a copy of the object before increment.
	Complex operator++(int) {
		Complex temp{*this};   // save current state
		++m_real;              // increment
		return temp;           // return old state
	}
	// Prefix decrement (--c)
	Complex& operator--() {
		--m_real;
		return *this;
	}
	// Postfix decrement (c--)
	Complex operator--(int) {
		Complex temp{*this};
		--m_real;
		return temp;
	}

	// Subscript operator [] – allows array‑like access to real/imag parts.
	// Non‑const version: returns a reference so the caller can modify the component.
	double& operator[](size_t index) {
		if(index == 0)      return m_real;
		else if(index == 1) return m_imag;
		else throw std::out_of_range{"Complex index must be 0 or 1"};
	}

	// Const version for read‑only access when the object is const.
	const double& operator[](size_t index) const {
		if(index == 0)      return m_real;
		else if(index == 1) return m_imag;
		else throw std::out_of_range{"Complex index must be 0 or 1"};
	}

	// Function call operator () – makes the object callable like a function.
	// Version with no arguments: returns the magnitude (absolute value).
	double operator()() const {
		return std::sqrt(m_real * m_real + m_imag * m_imag);
	}

	// Overloaded () that takes a bool: returns the phase angle.
	// If degrees == true, returns degrees; otherwise radians.
	double operator()(bool degrees) const {
		double pi = std::numbers::pi;
		double radians = std::atan2(m_imag, m_real);
		if(degrees) {
			return radians * 180.0 / pi;   // M_PI may need _USE_MATH_DEFINES on Windows
		}
		else {
			return radians;
		}
	}

	// FRIEND NON‑MEMBER OPERATORS
	// Friends have access to private members.

	// Stream insertion (<<)
	// Must be a non‑member because the left operand is std::ostream, not Complex.
	friend std::ostream& operator<<(std::ostream& os, const Complex& c){
		os << c.m_real;
		if(c.m_imag >= 0.0){
			os << " + " << c.m_imag << "i";
		}
		else{
			os << " - " << -c.m_imag << "i";
		}
		return os;
	}
	// Stream extraction (>>)
	// Reads two doubles separated by whitespace.
	friend std::istream& operator>>(std::istream& is, Complex& c) {
		is >> c.m_real >> c.m_imag;
		return is;
	}
	// Equality comparison (==)
	friend bool operator==(const Complex& lhs, const Complex& rhs) {
		return lhs.m_real == rhs.m_real && lhs.m_imag == rhs.m_imag;
	}
	// Inequality comparison (!=) – implemented in terms of ==
	friend bool operator!=(const Complex& lhs, const Complex& rhs) {
		return !(lhs == rhs);
	}
	// Less‑than comparison (<) – useful for ordering (e.g., in std::set)
	friend bool operator<(const Complex& lhs, const Complex& rhs) {
		// Compare real parts first, then imaginary parts.
		if(lhs.m_real < rhs.m_real) return true;
		if(lhs.m_real > rhs.m_real) return false;
		return lhs.m_imag < rhs.m_imag;
	}
};
// NON‑MEMBER ARITHMETIC OPERATORS (for mixed‑type expressions)
// These allow expressions like 2.5 + complex_obj.
Complex operator+(double lhs, const Complex& rhs) {
	return Complex{lhs} + rhs;   // convert double to Complex, then use member +
}
Complex operator-(double lhs, const Complex& rhs) {
	return Complex{lhs} - rhs;
}
Complex operator*(double lhs, const Complex& rhs) {
	return Complex{lhs} * rhs;
}
Complex operator/(double lhs, const Complex& rhs) {
	return Complex{lhs} / rhs;
}
int complexOverload(){
	// Create Complex objects
	Complex c1{3.0, 4.0};
	Complex c2{1.0, -2.0};
	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	// Arithmetic
	Complex sum = c1 + c2;
	Complex diff = c1 - c2;
	Complex prod = c1 * c2;
	Complex quot = c1 / c2;
	std::cout << "c1 + c2 = " << sum << std::endl;
	std::cout << "c1 - c2 = " << diff << std::endl;
	std::cout << "c1 * c2 = " << prod << std::endl;
	std::cout << "c1 / c2 = " << quot << std::endl;

	// Mixed‑type expressions (uses non‑member operators)
	Complex mix1 = 2.5 + c1;
	Complex mix2 = c1 * 3.0;
	std::cout << "2.5 + c1 = " << mix1 << std::endl;
	std::cout << "c1 * 3.0 = " << mix2 << std::endl;

	// Compound assignment
	c1 += c2;
	std::cout << "After c1 += c2: " << c1 << std::endl;
	c1 *= 2.0;
	std::cout << "After c1 *= 2.0: " << c1 << std::endl;

	// Unary and increment/decrement
	std::cout << "-c1 = " << -c1 << std::endl;
	Complex c3{5.0, 0.0};
	std::cout << "c3 = " << c3 << std::endl;
	std::cout << "c3++ = " << c3++ << " (now c3 = " << c3 << ")" << std::endl;
	std::cout << "++c3 = " << ++c3 << " (now c3 = " << c3 << ")" << std::endl;

	// Subscript operator
	c1[0] = 100.0;   // modify real part via non‑const []
	c1[1] = 200.0;   // modify imaginary part
	std::cout << "After subscript assignment: " << c1 << std::endl;

	// Function call operator
	std::cout << "Magnitude of c1: " << c1() << std::endl;
	std::cout << "Phase (radians): " << c1(false) << std::endl;
	std::cout << "Phase (degrees): " << c1(true) << std::endl;

	// Comparison
	Complex c4{100.0, 200.0};
	std::cout << std::boolalpha;   // print "true"/"false" instead of 1/0
	std::cout << "c1 == c4? " << (c1 == c4) << std::endl;
	std::cout << "c1 < c2? " << (c1 < c2) << std::endl;

	// Stream extraction (input)
	Complex c5;
	std::cout << "Enter a complex number (real imag): ";
	std::cin >> c5;
	std::cout << "You entered: " << c5 << std::endl;

	return 0;
}



// Smart Pointer – Overloading *, ->, and bool