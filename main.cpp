#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "map.h"
#include "player.h"
#include "renderer.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Raycaster", sf::Style::Close | sf::Style::Titlebar);

	std::vector<std::vector<int>> grid = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	Map map(48.0f, grid);

	Player player;
	player.position = sf::Vector2f(50, 50);

	Renderer renderer;

	sf::Clock gameclock;
	while (window.isOpen()) {
		float deltaTime = gameclock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		player.update(deltaTime);

		window.clear();
		renderer.draw3dView(window, player, map);
		window.display();
	}
}