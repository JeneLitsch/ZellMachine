#include "ConwayCell.hpp"
#include <iostream>
ConwayCell::ConwayCell(){
}
ConwayCell::~ConwayCell(){

}
unsigned int ConwayCell::countAliveNeightbors(unsigned ownX, unsigned ownY, GetCellFX getCell) const{
	unsigned int aliveNeighbors = 0;
	aliveNeighbors += int(isNeightborAlive(ownX - 1, ownY - 1, getCell));
	aliveNeighbors += int(isNeightborAlive(ownX + 0, ownY - 1, getCell));
	aliveNeighbors += int(isNeightborAlive(ownX + 1, ownY - 1, getCell));

	aliveNeighbors += int(isNeightborAlive(ownX - 1, ownY + 0, getCell));
	aliveNeighbors += int(isNeightborAlive(ownX + 1, ownY + 0, getCell));

	aliveNeighbors += int(isNeightborAlive(ownX - 1, ownY + 1, getCell));
	aliveNeighbors += int(isNeightborAlive(ownX + 0, ownY + 1, getCell));
	aliveNeighbors += int(isNeightborAlive(ownX + 1, ownY + 1, getCell));
	return aliveNeighbors;
}
bool ConwayCell::isNeightborAlive(unsigned x, unsigned y, GetCellFX getCell) const{
	if(auto cell = getCell(x, y)){
		if(cell->hasProperty("alive")){
			return true;
		}
	}
	return false;
}