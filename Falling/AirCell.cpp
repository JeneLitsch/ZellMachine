#include "MaterialCell.hpp"
#include "AirCell.hpp"

AirCell::AirCell(){
	this->properties.push_back("air");
	color = sf::Color::Cyan;
}
AirCell::~AirCell(){

}
std::shared_ptr<Cell> AirCell::updated(unsigned ownX, unsigned ownY, GetCellFX getCell) {
	if(auto cell = getCell(ownX, ownY - 1)){
		if(cell->hasProperty("material")){
			return std::make_shared<MaterialCell>();
		}
	}

	return nullptr;
}