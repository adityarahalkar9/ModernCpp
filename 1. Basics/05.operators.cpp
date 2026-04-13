import <iostream>;
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

int operators(){
	basicInfo();
	precedenceOfMultiplicationOverAddition();
	associativityOfSubtraction();

	return 0;
}