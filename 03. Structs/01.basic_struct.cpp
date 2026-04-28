import <iostream>;
#include "struct_header.h"

/*
	A structure is a user-defined data type that groups together variable of different data
	types under a single name
*/



// Creating a structure
struct Point{
	int x{};
	int y{};
};
int runBasicStruct(){
	// Creating a Point instance 'p1' and initialising it's variables
	Point p1{10,20};
	
	// Creating a Point instance 'p2
	Point p2{};		// Initialise members to their default values(0)
	
	// Creating a Point instance with designated inititalisers
	Point p3{};					// Dummy instance
	Point p4{.x = 5, .y = 15};	// Designated initialisers
	
	std::cout << "Point p1: x = " << p1.x << ", y = " << p1.y << std::endl;
	std::cout << "Point p2: x = " << p2.x << ", y = " << p2.y << std::endl;
	std::cout << "Point p4: x = " << p4.x << ", y = " << p4.y << std::endl;
	
	return 0;
}



// Accessing struct members
struct Rectangle{
	int width{};
	int height{};
};
int accessStruct(){
	Rectangle rect1{5,10};

	// Accessing and printing the width and height members
	std::cout << "Rectangle width: " << rect1.width << std::endl;
	std::cout << "Rectangle height: " << rect1.height << std::endl;

	// Modifying a member's value
	rect1.width = 8;
	std::cout << "Updated Rectangle width: " << rect1.width << std::endl;

	return 0;
}



// Passing strcutures to functions (By value)
struct Circle{
	double radius{};
};
void printCircleInfo(Circle c){
	std::cout << "Circle radius: " << c.radius << std::endl;
}
int passingStructByValue(){
	Circle myCircle{5};
	printCircleInfo(myCircle);

	return 0;
}



// Passing structures to functions(By reference)
struct Color{
	int red{};
	int green{};
	int blue{};
};
void brightenColor(Color& c){
	c.red = 120;
	c.green = 170;
	c.blue = 220;
}
int passingStructByReference(){
	Color myColor(100, 150, 200);
	std::cout << "Orignal red: " << myColor.red << "\nOrignal green: " << myColor.green
			  << "\nOrignal blue: " << myColor.blue << std::endl;
	std::cout << "Brightened colour red: " << myColor.red << "\nBrightened colour green: " << myColor.green
	   		  << "\nBrightened colour blue: " << myColor.blue << std::endl;

	return 0;
}



// Returning structures from functions
struct Vector2D{
	double x{};
	double y{};
};
Vector2D addVectors(Vector2D v1, Vector2D v2){
	return {v1.x + v2.x, v1.y + v2.y};
}
int structuresFromFunctions(){
	Vector2D vec1{1.5, 2.5};
	Vector2D vec2{3.5, 4.5};
	Vector2D sum = addVectors(vec1, vec2);
	std::cout << "Sum of vecrors x = " << sum.x << "\nSum of vectors y = " << sum.y << std::endl;

	return 0;
}
/*
	Functions can return structure variables. The addVectors() function takes 2 Vector2D structures
	as input and returns a new Vector2D structure whose x and y members are the sums of the corresponding
	members of the input vectors. 
*/
