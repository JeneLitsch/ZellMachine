#pragma once
#include "ConwayCell.hpp"

class LivingCell : public ConwayCell {
public:
	LivingCell();
	~LivingCell();
	virtual std::shared_ptr<Cell> updated(unsigned ownX, unsigned ownY, GetCellFX getCell) override;

};