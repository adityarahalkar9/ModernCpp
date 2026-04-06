import <iostream>;
import <string>;
#include "struct_header.h"

// Array structures
struct Student{
	std::string name{};
	int age{};
	double gpa{};
};
int arrayStructure(){
	Student students[3]{
		{"Aditya", 26, 7.31},
		{"Bob", 27, 6.78},
		{"Charlie, 28, 9.85"}
	};
	for(int i = 0; i < 3; ++i){
		std::cout << "Name: " << students[i].name << ", Age: " << students[i].age
				  << ", gpa: " << students[i].gpa << std::endl;
	}
	
	return 0;
}
/*
	This code demonstrates how to create an array where each element is a student structure. We declare
	an array of structs named students of size 3 and initialise each element using brace initialisation
	with the name, age and GPA of student. We can iterate through the array and print the information
	for each student.
*/



// Nested strcuture
struct Date{
	int year{};
	int month{};
	int date{};		
};
struct Employee{
	std::string name{};
	Date birthDate{};
};
int nestedStructure(){
	Employee emp1{"Adi",{2000, 1, 9}};
	std::cout << "Employee name: " << emp1.name << std::endl;
	std::cout << "Employee birthdate: " << emp1.birthDate.date << "-" << emp1.birthDate.month
			  << "-" << emp1.birthDate.year << std::endl;

	return 0;
}



// Pointers to structures
struct Book{
	std::string title{};
	std::string author{};
};
int pointerToStructure(){
	Book book1{"Hitchhiker's guide", "Douglas adams"};
	
	// Declaring a pointer to a book structure
	Book* bookptr = &book1;

	// Accessing members using arrow operator
	std::cout << "Book Title: " << bookptr -> title << std::endl;
	std::cout << "Book Author: " << bookptr->author << std::endl;

	// Dereferencing the pointer using dot operator
	std::cout << "Book title(dereferenced): " << (*bookptr).title << std::endl;
	std::cout << "Book Author(dereferenced): " << (*bookptr).author << std::endl;

	return 0;
}
/*
	This example shows how to work with pointers to structures.
	Book* bookptr = &book1; declares a pointer bookptr that stores the memory address of the book1
	structure. To access the members of the structure through the pointer, we use the arrow operator(->).
	The bookptr->title is equal to (*bookptr).title, where (*bookptr) dereferences the pointer to get
	the Book structure itself.
*/
