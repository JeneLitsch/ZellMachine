#pragma once
#include "../base/ZellMachine.hpp"

class AirCell : public Cell {
public:
	AirCell();
	~AirCell();
	virtual std::shared_ptr<Cell> updated(unsigned ownX, unsigned ownY, GetCellFX getCell) override;

};