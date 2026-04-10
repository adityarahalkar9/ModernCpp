import std;
#include "class_header.h"

/*
	Inheritance is a fundamental concept in OOP (Object Oriented Programming). It is the
	mechanism by which one class is allowed to inherit the features (fields and methods)
	of another class. Inheritance means creating new classes based on existing ones. A
	class that inherits from another class can reuse the methods and fields of that class.

	When a class inherits another class, it gets all the accessible members of the parent class,
	and the child class can also redefine (override) or add new functionality to them.
*/
class Animal{		// Animal is a base class
public:
	void sound(){
		std::cout << "Animal makes a sound" << std::endl;
	}
};
class Dog : public Animal{		// Dog is a derived/sub class
public:
	void sound(){
		std::cout << "Dog barks" << std::endl;
	}
};
class Cat : public Animal{
public:
	void sound(){
		std::cout << "Cat meows" << std::endl;
	}
};
class Cow : public Animal{
public:
	void sound(){
		std::cout << "Cow moos" << std::endl;
	}
};
int basicInheritance(){
	Dog d;
	d.sound();

	Cat c;
	c.sound();

	return 0;
}



/*
	Types of Inheritance in C++
	1. Single Inheritance
	2. Multiple Inheritance
	3. Multilevel Inheritance
	4. Hierarchical Inheritance
	5. Hybrid inheritance

*/



// Single INheritance
/*
	In single inheritance, a sub-class is derived from only one super class. It inherits
	the properties and behavior of a single-parent class. Sometimes, it is also known as
	simple inheritance.
*/
class Vehicle{		// Base class
protected:
	std::string brand{};
	int year{};
public:
	Vehicle(std::string b, int y) : brand(b), year(y){}
	void displayInfo(){
		std::cout << "Brand is: " << brand << ", year " << year << std::endl;
	}
};
class Car : public Vehicle{
private:
	std::string model{};
	int doors{};
public:
	Car(std::string b, int y, std::string m, int d) : Vehicle(b, y), model(m), doors(d){}
	void displayCarInfo(){
		displayInfo();
		std::cout << "Model: " << model << ", Doors: " << doors << std::endl;
	}
};
int singleInheritance(){
	Car myCar("Toyota", 2023, "Camry", 4);
	myCar.displayCarInfo();

	return 0;
}
/*
	- Vehicle is the base class with attributes brand and year, and a method displayInfo().
	- Car is the derived class that inherits from Vehicle using public inheritance.
	- Car adds its own attributes (model, doors) and a method displayCarInfo() that uses the base
	  class's displayInfo() method.
	- The protected access specifier allows the derived class to access the base class's members.
	In singleInheritance(), a Car object is created and its details are displayed.
*/



// Multiple Inheritance
/*
	In Multiple inheritance, one class can have more than one superclass and inherit features
	from all parent classes.
*/
// Base class 1
class LandVehicle{
protected:
	std::string brand{};
	int maxLandSpeed{};
public:
	LandVehicle(std::string b, int speed) : brand(b), maxLandSpeed(speed){}
	void displayLandInfo(){
		std::cout << "Brand: " << brand << ", Max Land speed: " << maxLandSpeed << std::endl;
	}
};
// Base class 2
class WaterVehicle{
protected:
	std::string model{};
	int maxWaterSpeed{};
public:
	WaterVehicle(std::string m, int speed) : model(m), maxWaterSpeed(speed){}
	void displayWaterInfo(){
		std::cout << "Model: " << model << ", Max water speed: " << maxWaterSpeed << std::endl;
	}
};
// Derived class from both LandVehicle and WaterVehicle
class AmphibiousVehicle : public WaterVehicle, public LandVehicle{
private:
	std::string vehicleName{};
public:
	AmphibiousVehicle(std::string b, int landSpeed, std::string m, int waterSpeed, std::string name) :
		LandVehicle(b, landSpeed), WaterVehicle(m, waterSpeed), vehicleName(name){}
	void displayInfo(){
		std::cout << "Amphibious Vehicle Display" << std::endl;
		displayLandInfo();
		displayWaterInfo();
	}
};
int multipleInheritance(){
	AmphibiousVehicle amp("KSI Technologies", 135, "A12", 45, "Galvatron");
	amp.displayInfo();

	return 0;
}



// Multilevel inheritance
/*
	 A class inherits from a class that itself inherits from another class. 
	 The chain: Base -> Intermediate -> Derived. Each derived class gets all 
	 members of its parent(s) plus its own
*/
// Base class Person
class Person{
protected:
	// Protected members can be accessed by derived classes
	std::string name{};
	int age{};
public:
	Person(std::string n, int a) : name(n), age(a){
		std::cout << "[Person] created: " << name << ", age: " << age << std::endl;
	}
	void introduce() const{
		std::cout << "Hello, I'm " << name << " and I'm " << age << " years old" <<std::endl;
	}
};
// derived class 1
class Student : public Person{
protected:
	std::string school{};
	int gradeLevel{};
public:
	Student(std::string n1, int a1, std::string sch, int grade) : Person{n1, a1}, school{sch}, gradeLevel{grade}{
		std::cout << "[Student] Created: School = " << school << ", Grade " << gradeLevel << std::endl;;
	}
	void study() const{
		std::cout << name << " is studying at " << school << " (Grade " << gradeLevel << ")." << std::endl;
	}
};
// Derived class 2
class GraduateStudent : public Student{
private:
	std::string thesisTopic{};
	std::string advisor{};
public:
	GraduateStudent(std::string n, int a, std::string sch, int grade, std::string topic, std::string adv) : 
		Student{n, a, sch, grade}, thesisTopic{topic}, advisor{adv}{
		std::cout << "[GraduateStudent] Created: Thesis = \"" << thesisTopic << "\", Advisor = " << advisor << std::endl;
	}
	void research() const{
		std::cout << name << " is researching \"" << thesisTopic << "\" under advisor " << advisor << std::endl;
	}
	// Show everything accumulated from all three levels
	void displayFullProfile() const {
		std::cout << "\n========== FULL PROFILE ==========\n";
		std::cout << "Name:        " << name << "  (from Person)\n";
		std::cout << "Age:         " << age << "  (from Person)\n";
		std::cout << "School:      " << school << "  (from Student)\n";
		std::cout << "Grade Level: " << gradeLevel << "  (from Student)\n";
		std::cout << "Thesis:      " << thesisTopic << "  (from GraduateStudent)\n";
		std::cout << "Advisor:     " << advisor << "  (from GraduateStudent)\n";
		std::cout << "===================================\n";
	}
};
int multilevelInheritance(){
	GraduateStudent grad{
		"Alice Smith",          // name
		24,                     // age
		"MIT",                  // school
		5,                      // grade level (PhD student)
		"Quantum Algorithms",   // thesis topic
		"Dr. Robert Chen"       // advisor
	};
	std::cout << "\n--- Calling methods from different levels ---\n";
	grad.introduce();			// From Person
	grad.study();				// From Student
	grad.research();			// From GraduateStudent
	grad.displayFullProfile();	// Combines all levels

	return 0;

}