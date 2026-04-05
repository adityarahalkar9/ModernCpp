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