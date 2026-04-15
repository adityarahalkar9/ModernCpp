import <iostream>;
import <iomanip>;	// for std::boolalpha
import <cmath>;;	// for std::pow
#include "basic_header.h"

/*
	An operator is a symbol that tells the compiler to perform a specific mathematical, 
	logical, or other operation. The values the operator acts upon are called operands.
*/
int basicInfo(){
	int a{5};
	int b{6};
	int sum = a + b;	// '+' is the operator; 'a' and 'b' are operands

	return 0;
}
/*
	Operators can be classified by the number of operands they require:
	-> Unary: one operand (e.g., -x, ++i)
	-> Binary: two operands (e.g., x + y, a = b)
	-> Ternary: three operands (only ?:)
*/



// Precedence and Associativity – How Expressions Are Grouped
/*
	When an expression contains multiple operators, precedence determines the order in 
	which operators are grouped with their operands. Higher precedence operators are grouped first.
	If adjacent operators have the same precedence, associativity determines the grouping direction:
	-> Left-to-right (L→R): (a op b) op c
	-> Right-to-left (R→L): a op (b op c)
*/
// Precedence of Multiplication over Addition
void precedenceOfMultiplicationOverAddition(){
	int result = 4 + 2 * 3;		// Multiplication has higher precedence than addition.
	// Equivalent to: 4 + (2 * 3) → 10
}
void associativityOfSubtraction(){
	int result = 7 - 4 - 1;		// Subtraction is left-to-right associative.
	// Equivalent to: (7 - 4) - 1 → 2
	// Not 7 - (4 - 1) → 4
}



// Operator precedence table
/*
	|===============================================================================
	|  C++ Operator Precedence and Associativity (Simplified Reference)
	|===============================================================================
	|Prec | Assoc | Operators                                      | Description
	|-----|-------|------------------------------------------------|----------------------------
	|  1  | L->R  | ::                                             | Scope resolution
	|  2  | L->R  | () [] . -> ++ -- (postfix) typeid const_cast   | Function call, subscript,
	|	  |       | dynamic_cast reinterpret_cast static_cast      | member access, postfix inc/dec,
	|	  |       |                                                | casts, type identification
	|  3  | R->L  | + - ++ -- (prefix) ! ~ (type) sizeof & *       | Unary plus/minus, prefix inc/dec,
	|	  |       | new new[] delete delete[]                      | logical NOT, bitwise NOT, C-style cast,
	|	  |       |                                                | size-of, address-of, dereference,
	|	  |       |                                                | dynamic memory management
	|  4  | L->R  | .* ->*                                         | Pointer-to-member operators
	|  5  | L->R  | * / %                                          | Multiplication, division, remainder
	|  6  | L->R  | + -                                            | Addition, subtraction
	|  7  | L->R  | << >>                                          | Bitwise shift left/right
	|  8  | L->R  | <=>                                            | Three-way comparison (C++20)
	|  9  | L->R  | < <= > >=                                      | Relational comparisons
	| 10  | L->R  | == !=                                          | Equality and inequality
	| 11  | L->R  | &                                              | Bitwise AND
	| 12  | L->R  | ^                                              | Bitwise XOR
	| 13  | L->R  | |                                              | Bitwise OR
	| 14  | L->R  | &&                                             | Logical AND
	| 15  | L->R  | ||                                             | Logical OR
	| 16  | R->L  | ?: = += -= *= /= %= <<= >>= &= |= ^= throw     | Ternary conditional, assignment,
	|	  |       |                                                | compound assignment, throw
	| 17  | L->R  | ,                                              | Comma operator
	 ===============================================================================
	 Note: Precedence 1 is highest. Operators on the same line share precedence.
*/
/*
	Understanding the Table:
	-> Prec: Lower number means higher precedence.
	-> Assoc: Grouping direction.
	-> Operators: Symbols used in expressions.
	-> Description: Brief explanation of each operator group.
*/



// std::pow
int stdMathFunction(){
	double power = std::pow(2.0, 8.0);
	std::cout << "Power is: " << power << std::endl;

	return 0;
}



// Arithmetic Operators (+, -, *, /, %)
int arithmeticOperators(){
	int x{10}, y{3};
	std::cout << "x + y = " << x + y << std::endl;	// 13
	std::cout << "x - y = " << x - y << std::endl;	// 7
	std::cout << "x * y = " << x * y << std::endl;	// 30
	std::cout << "x / y = " << x / y << std::endl;	// 3(integer division truncates)
	std::cout << "x % y = " << x % y << std::endl;	// 1(remainder, integer only)

	double a{10.0}, b{3.0};
	std::cout << "a / b = " << a / b << std::endl;	// 3.3333(Floating point division)
	
	return 0;
}



// Assignment Operators (=, +=, -=, *=, /=, %=)
int assignmentOperators(){
	int value{5};
	value += 3;   // equivalent to: value = value + 3
	std::cout << value << std::endl;  // 8

	value *= 2;   // value = value * 2
	std::cout << value << std::endl;  // 16

	// Chained assignment (right-to-left associativity)
	int a{}, b{};
	a = b = 10;   // b = 10; then a = b;
	std::cout << a << ' ' << b << '\n';  // 10 10

	return 0;
}



// Increment and Decrement (++, --)
/*
	-> Prefix (++i) increments and returns the new value.
	-> Postfix (i++) returns the old value and then increments.
*/
int incrementDecrementOperator(){
	int i{5};
	int a{i++};		// a = 5, i becomes 6
	std::cout << "a = " << a << ", i = " << i << std::endl;

	int b{++i};		// i becomes 7, b = 7
	std::cout << "b = " << b << ", i = " << i << std::endl;

	return 0;
}



// Relational and Equality Operators (<, <=, >, >=, ==, !=)
int equalityOperators(){
	int x{5}, y{7};
	bool result{};

	result = (x == y);	std::cout << std::boolalpha << result << std::endl;		// false
	result = (x != y);  std::cout << result << std::endl;						// true
	result = (x < y);   std::cout << std::noboolalpha << result << std::endl;	// 1
	result = (x >= y);  std::cout << result << std::endl;						// 0

	return 0;
}
/*
	Think of std::cout as a printer. std::boolalpha is like pressing a button on the 
	printer that says "Print words instead of numbers."
	If you wanted the second line to print as a number again, you would have to explicitly reset it:

	std::cout << std::boolalpha << true << std::endl;   // Prints: true
	std::cout << std::noboolalpha << true << std::endl; // Prints: 1
*/



// Logical Operators(&&, || , !)
int logicalOperator(){
	bool a{true}, b{false};
	std::cout << std::boolalpha;
}


int operators(){
	// basicInfo();
	// precedenceOfMultiplicationOverAddition();
	// associativityOfSubtraction();
	// arithmeticOperators();
	// stdMathFunction();
	// assignmentOperators();
	// incrementDecrementOperator();
	// equalityOperators();

	return 0;
}