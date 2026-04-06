import <iostream>;
#include "struct_header.h"

// Anonymous structs are structures without name
struct PointWithColor{
	int x{};
	int y{};
	// Anonymous structure for Color
	struct{
		unsigned char red{};
		unsigned char green{};
		unsigned char blue{};
	}color{};	// Initialise the anonymous structure member
};
int anonymousStruct(){
	PointWithColor p1{10,20,{255,0,0}};    // Initialise the anonymous structure member
	std::cout << "Point x: " << p1.x << ", y: " << p1.y << std::endl;
	std::cout << "color: red = " << static_cast<int>(p1.color.red) << " color: green = " << static_cast<int>(p1.color.green)
			  << " color: blue = " << static_cast<int>(p1.color.blue) << std::endl;
	
	return 0;
}