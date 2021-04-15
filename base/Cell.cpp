#include "Cell.hpp"

Cell::Cell(/* args */){
}

Cell::~Cell(){
}

const sf::Color & Cell::getColor() const{
	return this->color;
}

bool Cell::hasProperty(const std::string & property) const{
	for (const std::string & ownProperty : this->properties){
		if (ownProperty == property){
			return true;
		}
	}
	return false;
}