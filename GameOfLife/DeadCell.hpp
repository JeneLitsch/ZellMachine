#pragma once
#include "ConwayCell.hpp"

class DeadCell : public ConwayCell {
public:
	DeadCell();
	~DeadCell();
	virtual std::shared_ptr<Cell> updated(unsigned ownX, unsigned ownY, GetCellFX getCell) override;
};