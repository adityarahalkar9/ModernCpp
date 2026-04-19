import std;

/*
	Polymorphism
	The word means "many forms". In C++, it allows a single interface (function name, operator, 
	or base pointer) to behave differently depending on the type of object it operates on. C++
	has two orthogonal axes of polymorphism:
	-> Static (Compile-time)  --->  Resolved at Compile time  --->  Mechanism (Overloading, Templates)\
	-> Dynamic (Runtime)      --->  Resolved at Runtime       --->  Mechanism (Virtual functions)
*/



// ============>
// 1. Compile-Time Polymorphism
// 1a: Function Overloading
namespace fOverloading{
	// Same name, different parameter types.
	// Compiler picks the correct version at compile time via overload resolution.
	void print(int x){
		std::cout << "int: " << x << std::endl;
	}
	void print(double x){
		std::cout << "double: " << x << std::endl;
	}
	void print(const char* s){
		std::cout << "string: " << s << std::endl;
	}
}
int pFunctionOverloading(){
	fOverloading::print(42);	   // Calls print(int)
	fOverloading::print(3.14);	   // Calls print(double)
	fOverloading::print("hello");  // Calls print(const char*)

	return 0;
}

// 1b: Operator Overloading
namespace OpOverload{
	struct Vec2{
		float x{};
		float y{};

		// Member operator: left operand is *this.
		// Compiler rewrites  a + b  as  a.operator+(b).
		Vec2 operator+(const Vec2& rhs) const{
			return Vec2{x + rhs.x, y + rhs.y};
		}

		// Friend free function: needed so std::ostream is the left operand.
		// std::ostream cannot be *this (it's not our class to modify).
		friend std::ostream& operator<<(std::ostream& os, const Vec2& v){
			return os << '(' << v.x << ", " << v.y << ')';
		}
	};
}
int operatorOverload(){
	OpOverload::Vec2 a{1.0f, 2.0f};
	OpOverload::Vec2 b{3.0f, 4.0f};
	std::cout << (a + b) << std::endl;	// prints (4,6)

	return 0;
}

// 1c: Template (Parametric) Polymorphism
namespace Templates{
	// Compiler stamps out a separate concrete function for every T used.
	// This is called "template instantiation".
	// Fully resolved at compile time — zero runtime overhead.
	template<typename T>
	T maxOf(T a, T b){
		return (a > b) ? a : b;
	}
}
int templatePolymorphism(){
	std::cout << Templates::maxOf(3, 7) << std::endl;		// T = int
	std::cout << Templates::maxOf(2.5, 1.1) << std::endl;	// T = double
	std::cout << Templates::maxOf('a', 'z') << std::endl;	// T = char

	return 0;
}