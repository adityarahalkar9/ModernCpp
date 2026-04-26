import <iostream>;
#include "basic_header.h"

/*
	-> A function is a block of code which only runs when it is called.
	-> You can pass data. known as parameters, into a function.
	-> Functions are used to perform certain actions, and they are important for
	   reusing code. Define the code once, and use it many times.
*/



// Function add() takes 2 parameters and returns a+b
int add(int a, int b){
	return a + b;
}
// Function subtract() also takes 2 parameters and prints value a-b
int subtract(int a, int b){
	std::cout << a - b << std::endl;

	return 0;
}
// Both the above functions are called here
int function(){
	std::cout << add(2, 3) << std::endl;
	subtract(3, 1);

	return 0;
}


// Function with return value
int multiply(int a, int b){
	return a * b;
}
void multiplyAndPrint(int a, int b){
	int product = multiply(a, b);
	std::cout << "Product is: " << product << "\n";
}
void mAndP(){
	multiplyAndPrint(4,5);
}


// Functions with Parameters(pass by value)
void printDoubleValue(int number){
	std::cout << "Double of " << number << " is " << number * 2 << "\n";
}
void printDoubleAndOrignal(int num){
	printDoubleValue(num);
	std::cout << "Orignal value remains: " << num << "\n";
}
int printV(){
	int value{7};
	printDoubleAndOrignal(value);
	return 0;
}


/*
	Functions with default arguments.
	You can use functions that have default arguments when you do not enter any particular parameter
*/
void displayItemCount(std::string itemname, int count = 1){
	std::cout << itemname << " count: " << count << "\n";
}
void defaultArguments(){
	displayItemCount("purse");			 // Uses defualt count = 1
	displayItemCount("Chocolate", 23);   // Overrides default argument count
}

// Lambda function Syntax
/*
	[capture list](parameters) -> return type{
		std::cout << std::endl;
		}
*/

void lambdaFunctions(){
	// Calling lambda function #2
	auto func = [](){
		std::cout << "World" << std::endl;
		};
	func();

	// Calling lambda function directly after definition
	[](){
		std::cout << "Hello" << std::endl;
		}();

	// Lambda functions that take parameters
	[](double a, double b){
		std::cout << "a + b : " << (a + b) << std::endl;
		}(12.34, 56.78);

	// Lambda function that returns something
	auto result1 = [](double a, double b){
		return (a + b);
		};

	// Printing result directly
	std::cout << "Result_2: " << [](double a, double b){
		return (a + b);
		}(12.13, 5.78) << std::endl;

	// Specify return type explicitly
	auto result3 = [](double a, double b) -> double{
		return (a + b);
		}(15.54, 14.47);
	std::cout << "Result_3: " << result3 << std::endl;
}