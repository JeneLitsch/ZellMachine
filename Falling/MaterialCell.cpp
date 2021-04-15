#include "MaterialCell.hpp"
#include "AirCell.hpp"

MaterialCell::MaterialCell(){
	// color = sf::Color(60,60,60);
	color = sf::Color::Black;
	this->properties.push_back("material");
}
MaterialCell::~MaterialCell(){

}
std::shared_ptr<Cell> MaterialCell::updated(unsigned ownX, unsigned ownY, GetCellFX getCell) {
	if(auto cell = getCell(ownX, ownY + 1)){
		if(cell->hasProperty("air")){
			return std::make_shared<AirCell>();
		}
	}
	return nullptr;
}