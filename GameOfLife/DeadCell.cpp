#include "DeadCell.hpp"
#include "LivingCell.hpp"
DeadCell::DeadCell(){
	color = sf::Color::Black;
}
DeadCell::~DeadCell(){

}
std::shared_ptr<Cell> DeadCell::updated(unsigned ownX, unsigned ownY, GetCellFX getCell) {
	unsigned aliveNeightbors = this->countAliveNeightbors(ownX, ownY, getCell);
	if(aliveNeightbors == 3){
		return std::make_shared<LivingCell>();
	}
	else{
		return nullptr;
	}
}