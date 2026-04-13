import <iostream>;
#include "basic_header.h"

void ifElse(){
	int age{23};
	if(age < 18){
		std::cout << "Not an adult" << std::endl;
	}
	else if(age >= 18){
		std::cout << "Adult" << std::endl;
	}
	else{
		std::cout << "Invalid input" << std::endl;
	}
}

void switchStatement(){
	int day = 4;	// Assume 1 = Mon, 2 = Tue, ..., 7 = Sun

	switch(day){
	case1:
		std::cout << "Monday\n";
		break;
	case 2:
		std::cout << "Tuesday\n";
		break;
	case 3:
		std::cout << "Wednesday\n";
		break;
	case 4:
		std::cout << "Thursday\n";
		break;
	case 5:
		std::cout << "Friday\n";
		break;
	case 6:
		std::cout << "Saturday\n";
		break;
	case 7:
		std::cout << "Sunday\n";
		break;
	default:
		std::cout << "Invalid day\n";
		break;
	}
}
