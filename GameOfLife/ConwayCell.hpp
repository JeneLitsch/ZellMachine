#pragma once

#include "../base/Cell.hpp"

class ConwayCell : public Cell {
public:
	ConwayCell();
	~ConwayCell();

protected:
	unsigned int countAliveNeightbors(unsigned ownX, unsigned ownY, GetCellFX getCell) const;
	bool isNeightborAlive(unsigned x, unsigned y, GetCellFX getCell) const;	
};