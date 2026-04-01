import <iostream>;
#include "memory_header.h"

// A pointer is a variable that stores the address of another variable
int pointer(){
	int num{45};
	int* n_ptr = &num;

	std::cout << "num is: " << num << std::endl;
	std::cout << "&num is: " << &num << std::endl;
	std::cout << "n_ptr is: " << n_ptr << std::endl;
	std::cout << "&n_ptr is: " << &n_ptr << std::endl;

	// Dereferencing the pointer n_ptr
	std::cout << "*n_ptr is: " << *n_ptr << std::endl;

	// &num = n_ptr as n_ptr pointer stores memory address of variable num
	// *n_ptr = num = 45 as the dereferenced pointer *n_ptr holds value of num
	
	return 0;
}



int pointerManipulation(){
	int a{90};
	int* a_ptr = &a;

	*a_ptr += 4;
	std::cout << "a is: " << a << std::endl;

	*a_ptr = 150;
	std::cout << "a is: " << std::endl;

	return 0;
}