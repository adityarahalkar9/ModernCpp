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