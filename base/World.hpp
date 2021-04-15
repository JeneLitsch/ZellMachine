#pragma once

#include "Cell.hpp"
#include "SFML/Graphics.hpp"
#include <memory>

class World {
public:
	World(const std::vector<std::shared_ptr<Cell>> & cells, const sf::Vector2u & size);
	~World();

	void update();

	sf::Image render() const;

	std::shared_ptr<Cell> getCell(unsigned int x, unsigned int y) const;

private:
	std::vector<std::shared_ptr<Cell>> cells;
	sf::Vector2u size;
};