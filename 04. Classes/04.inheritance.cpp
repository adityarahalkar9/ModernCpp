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



// SINGLE INHERITANCE
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



// MULTIPLE INHERITANCE
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



// MULTILEVEL INHERITANCE
/*
	 A class inherits from a class that itself inherits from another class. 
	 The chain: Base -> Intermediate -> Derived. Each derived class gets all 
	 members of its parent(s) plus its own
*/
// Base class Person
namespace multilevel{
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
			std::cout << "Hello, I'm " << name << " and I'm " << age << " years old" << std::endl;
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
}
int multilevelInheritance(){
	multilevel::GraduateStudent grad{
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



// HIERARCHICAL INHERITANCE
/*
	Multiple classes inherit from the same base class. Each derived class gets all members of Base class
	plus its own specific members.
*/
namespace hierarchical{

	// Base class Animal
	class Animal{
	protected:
		std::string name{};
		int age{};
	public:
		Animal(std::string n, int a) : name{n}, age{a}{
			std::cout << "[Hierarchical::Animal] created: " << name << ", " << age << " years old" << std::endl;
		}
		void eat() const{
			std::cout << name << " is eating" << std::endl;
		}
		void sleep() const{
			std::cout << name << " is sleeping" << std::endl;
		}
		void displayInfo() const{
			std::cout << "Name is: " << name << ", Age: " << age << std::endl;
		}
	};
	// Derived class 1
	class Dog : public Animal{
	private:
		std::string breed{};
		bool isTrained{};
	public:
		Dog(std::string n, int a, std::string b, bool trained) : Animal{n, a}, breed{b}, isTrained{trained}{
			std::cout << "[Hierarchical::Dog Created: Breed = " 
					  << breed<< ", Trained = " << (isTrained ? "Yes" : "No") << std::endl;
		}
		void bark() const{
			std::cout << name << " says: Woof! Woof!" << std::endl;
		}
		void fetch() const{
			std::cout << name << " is fetching the stick." << std::endl;
		}
		void displayDogInfo() const{
			displayInfo();
			std::cout << ", Breed: " << breed << ", Trained: " 
					  << (isTrained ? "Yes" : "No") << std::endl;
		}
	};
	// Derived class 2
	class Cat : public Animal{
	private:
		std::string furColor{};
		bool isIndoor{};
	public:
		Cat(std::string n, int a, std::string color, bool indoor) : Animal{n, a}, furColor{color}, isIndoor{indoor}{
			std::cout << "[hierarchical::Cat] Created: Fur = " << furColor
					  << ", Indoor = " << (isIndoor ? "Yes" : "No") << "\n";
		}
		void meow() const{
			std::cout << name << " says: Meow! Meow!" << std::endl;
		}
		void scratch() const{
			std::cout << name << " is scratching the furniture" << std::endl;
		}
		void displayCatInfo() const{
			displayInfo();
			std::cout << ", Fur Color: " << furColor << ", Indoor Cat: "
					  << (isIndoor ? "Yes" : "No") << std::endl;
		}
	};
	// Derived class 3
	class Bird : public Animal{
	private:
		std::string species{};
		double wingspan{};
	public:
		Bird(std::string n, int a, std::string sp, double ws) : Animal{n, a}, species{sp}, wingspan{ws}{
			std::cout << "[hierarchical::Bird] Created: Species = " << species
					  << ", Wingspan = " << wingspan << " cm\n";
		}
		void chirp() const{
			std::cout << name << " chirps: Tweet! Tweet!" << std::endl;
		}
		void fly() const{
			std::cout << name << " is flying with a wingspan of " << wingspan << std::endl;
		}
		void displayBirdInfo() const{
			displayInfo();
			std::cout << ", Species: " << species << ", Wingspan: " << wingspan << std::endl;
		}
	};
}
int hierarchicalInheritance(){
	std::cout << "=== Hierarchical Inheritance (using hierarchical:: prefix) ===\n\n";

	// Create objects using explicit namespace qualification
	std::cout << "--- Creating a Dog ---\n";
	hierarchical::Dog myDog{"Buddy", 3, "Golden Retriever", true};

	std::cout << "\n--- Creating a Cat ---\n";
	hierarchical::Cat myCat{"Whiskers", 2, "Orange Tabby", true};

	std::cout << "\n--- Creating a Bird ---\n";
	hierarchical::Bird myBird{"Tweety", 1, "Canary", 20.5};

	std::cout << "\n========== DOG ACTIONS ==========\n";
	myDog.eat();
	myDog.sleep();
	myDog.bark();
	myDog.fetch();
	myDog.displayDogInfo();

	std::cout << "\n========== CAT ACTIONS ==========\n";
	myCat.eat();
	myCat.sleep();
	myCat.meow();
	myCat.scratch();
	myCat.displayCatInfo();

	std::cout << "\n========== BIRD ACTIONS ==========\n";
	myBird.eat();
	myBird.sleep();
	myBird.chirp();
	myBird.fly();
	myBird.displayBirdInfo();

	std::cout << "\n--- Common base class interface (works for all) ---\n";
	myDog.displayInfo();
	std::cout << "\n";
	myCat.displayInfo();
	std::cout << "\n";
	myBird.displayInfo();
	std::cout << "\n";

	return 0;
}



// HYBRID INHERITANCE
/*
	 Hybrid inheritance combines two or more types of inheritance.
*/
namespace hybrid{
	// Base class: Person
	class Person {
	protected:
		std::string name{};
		int age{};
	public:
		Person(std::string n, int a) : name{n}, age{a}{
			std::cout << "[hybrid::Person] Created: " << name << ", " << age << " years old" << std::endl;
		}
		void introduce() const{
			std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
		}
		std::string getName() const{
			return name;
		}
		int getAge() const{
			return age;
		}
	};
	// Derived class 1: Student
	class Student : public Person {
	protected:
		std::string school{};
		int gradeLevel{};
	public:
		Student(std::string n, int a, std::string sch, int grade) : Person{n, a}, school{sch}, gradeLevel{grade}{
			std::cout << "[hybrid::Student] Created: School = " << school << ", Grade = " << gradeLevel << std::endl;
		}
		void study() const{
			std::cout << name << " is studying at " << school << " (Grade " << gradeLevel << ")." << std::endl;
		}
	};
	// Derived class 2: Employee
	class Employee : public Person {
	protected:
		std::string company{};
		double salary{};
	public:
		Employee(std::string n, int a, std::string comp, double sal) : Person{n, a}, company{comp}, salary{sal}{
			std::cout << "[hybrid::Employee] Created: Company = " << company << ", Salary = $" << salary << std::endl;
		}
		void work() const{
			std::cout << name << " works at " << company << " earning $" << salary << " per year." << std::endl;
		}
	};
	// Most derived class
	class WorkingStudent : public Student, public Employee{
	private:
		int hoursPerWeek{};
	public:
		WorkingStudent(std::string n, int a, std::string sch, int grade, std::string comp, double sal, int hours)
			: Student{n, a, sch, grade}, Employee{n, a, comp, sal}, hoursPerWeek{hours}{
			std::cout << "[hybrid::WorkingStudent] Created: Works " << hoursPerWeek<< " hours per week" << std::endl;
		}
		void workAndStudy() const{
			// Explicitly scoping to Student branch to resolve the 'name' ambiguity
			std::cout << Student::name << " is a working student." << std::endl;
			std::cout << "Studies at " << school << " and works at " << company << "." << std::endl;
			std::cout << "Works " << hoursPerWeek << " hours per week." << std::endl;
		}
		void displayFullProfile() const{
			std::cout << "\n========== WORKING STUDENT FULL PROFILE ==========\n";
			// Resolving ambiguity for 'name' and 'age'
			std::cout << "Name:         " << Student::name << " (via Student branch)\n";
			std::cout << "Age:          " << Student::age << " (via Student branch)\n";
			std::cout << "School:       " << school << " (from Student)\n";
			std::cout << "Grade:        " << gradeLevel << " (from Student)\n";
			std::cout << "Company:      " << company << " (from Employee)\n";
			std::cout << "Salary:       $" << salary << " (from Employee)\n";
			std::cout << "Hours/week:   " << hoursPerWeek << " (from WorkingStudent)\n";
			std::cout << "==================================================" << std::endl;
		}
	};
}
int hybridInheritance(){
	std::cout << "=== Hybrid Inheritance (Diamond without virtual) ===\n" << std::endl;

	hybrid::WorkingStudent ws{
		"Alex Johnson", 22,
		"State University", 16,
		"TechCorp Inc.", 35000.0, 20
	};

	std::cout << "\n--- Ambiguity Resolution ---" << std::endl;
	// Calling the base method via a specific path
	ws.Student::introduce();

	ws.study();
	ws.work();
	ws.displayFullProfile();

	std::cout << "\n--- Object Memory Layout ---" << std::endl;
	std::cout << "Size of Person:         " << sizeof(hybrid::Person) << " bytes" << std::endl;
	std::cout << "Size of Student:        " << sizeof(hybrid::Student) << " bytes" << std::endl;
	std::cout << "Size of Employee:       " << sizeof(hybrid::Employee) << " bytes" << std::endl;
	std::cout << "Size of WorkingStudent: " << sizeof(hybrid::WorkingStudent) << " bytes" << std::endl;

	return 0;
}