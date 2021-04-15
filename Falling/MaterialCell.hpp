#pragma once
#include "../base/ZellMachine.hpp"

class MaterialCell : public Cell {
public:
	MaterialCell();
	~MaterialCell();
	virtual std::shared_ptr<Cell> updated(unsigned ownX, unsigned ownY, GetCellFX getCell) override;

};