#include "class_header.h"
#include <iostream>

// Pure virtual functions

namespace Interface{
	class Entity{
	public:
		virtual std::string getName() = 0;
	};
	class Player : public Entity{
	private:
		std::string m_Name{};
	public:
		Player(const std::string& name) : m_Name(name){}
		std::string getName() override{
			return m_Name;
		}
	};
}
void printName(Interface::Entity* entity){
	std::cout << entity->getName() << std::endl;
}

int interfaces(){
	Interface::Entity* e = new Interface::Player("");

	return 0;
}