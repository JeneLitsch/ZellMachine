#pragma once

#include <vector>
#include <string>
#include <memory>
#include <functional>

#include "SFML/Graphics.hpp"

class Cell;

typedef const std::function<const std::shared_ptr<Cell> (unsigned x, unsigned y)> & GetCellFX;

class Cell {
public:
	Cell();
	virtual ~Cell();

	virtual std::shared_ptr<Cell> updated(unsigned ownX, unsigned ownY, GetCellFX getCell) = 0;

	virtual const sf::Color & getColor() const;
	virtual bool hasProperty(const std::string & property) const;

protected:
	std::vector<std::string> properties;
	sf::Color color;

	

};

