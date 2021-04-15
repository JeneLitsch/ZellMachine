#include "World.hpp"
World::World(const std::vector<std::shared_ptr<Cell>> & cells, const sf::Vector2u & size){
	this->cells = cells;
	this->size = size;
}

World::~World(){

}

std::shared_ptr<Cell> World::getCell(unsigned int x, unsigned int y) const{
	if(x < this->size.x && y < this->size.y){
		return this->cells[y * size.x + x];
	}
	else{
		return nullptr;
	}
}

void World::update(){
	std::vector<std::shared_ptr<Cell>> newWorld;
	unsigned i = 0;
	for (const std::shared_ptr<Cell> & cell : this->cells){
		unsigned x = i % this->size.x;
		unsigned y = i / this->size.x;		
		i++;
		std::function getFX = [this](unsigned x, unsigned y) -> const std::shared_ptr<Cell> {return this->getCell(x,y);};
		std::shared_ptr<Cell> newCell = cell->updated(x,y, getFX);
		if (newCell.get()){
			newWorld.push_back(newCell);
		}
		else{
			newWorld.push_back(cell);
		}
	}
	this->cells = newWorld;
}

sf::Image World::render() const{
	sf::Image img;
	img.create(this->size.x, this->size.y);
	for(unsigned int x = 0; x < this->size.x; x++){
		for(unsigned int y = 0; y < this->size.y; y++){
			sf::Color color = (x+y)%2 ? getCell(x,y)->getColor() : getCell(x,y)->getColor() * sf::Color(200,200,200);
			img.setPixel(x,y, color);
		}
	}
	return img;
}
