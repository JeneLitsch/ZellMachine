#include "LivingCell.hpp"
#include "DeadCell.hpp"
LivingCell::LivingCell(){
	color = sf::Color::White;
	this->properties.push_back("alive");
}
LivingCell::~LivingCell(){

}
std::shared_ptr<Cell> LivingCell::updated(unsigned ownX, unsigned ownY, GetCellFX getCell) {
	unsigned aliveNeightbors = this->countAliveNeightbors(ownX, ownY, getCell);
	if(aliveNeightbors < 2){
		return std::make_shared<DeadCell>();
	}
	else if (aliveNeightbors > 3) {
		return std::make_shared<DeadCell>();
	}
	else{
		return nullptr;
	}
}