#include "SFML/Graphics.hpp"

#include "../base/ZellMachine.hpp"

#include "DeadCell.hpp"
#include "LivingCell.hpp"
int main(){
	sf::RenderWindow window;
	window.create(sf::VideoMode(100,100), "GameOfLive");
	window.setView(sf::View({0.5,0.5},{1,1}));
	window.setVerticalSyncEnabled(true);

	std::vector<std::shared_ptr<Cell>> cells;
	srand(time(NULL));
	for(int i = 0; i< 10000; i++){
		if(rand() % 2 == 0){
			cells.push_back(std::make_shared<LivingCell>());
		}
		else{
			cells.push_back(std::make_shared<DeadCell>());
		}
	}
	sf::VertexArray square;
	square.append(sf::Vertex(sf::Vector2f(0,0),sf::Vector2f(0,0)));
	square.append(sf::Vertex(sf::Vector2f(1,0),sf::Vector2f(100,0)));
	square.append(sf::Vertex(sf::Vector2f(1,1),sf::Vector2f(100,100)));
	square.append(sf::Vertex(sf::Vector2f(0,1),sf::Vector2f(0,100)));
	square.setPrimitiveType(sf::PrimitiveType::Quads);

	World world(cells, {100,100});
	sf::Clock clock;

	while(window.isOpen()){
		sf::Event evt;
		while(window.pollEvent(evt)){
			if(evt.type == sf::Event::Closed){
				window.close();
			}
		}
		if(clock.getElapsedTime().asSeconds() >= 0.5){
			world.update();
			clock.restart();
		}
		window.clear(sf::Color::Red);
		sf::Texture tex;
		tex.loadFromImage(world.render());
		window.draw(square, &tex);
		window.display();
	}

	return 0;
}