 /**
     *  Anna Danh
     *  Course: CMPS 2143 - OOP
     *
     *  Purpose: Testing sfml
     * 
     *  @version 1.1 10/1/2018
     *  @github repo: https://github.com/annadanh/2143-oop-danh
     */

#include <SFML/Graphics.hpp>
int main() {
  // creates window of size 200,200 to print on
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  // creates circle of size 100
	sf::CircleShape shape(100.f);
  // makes circle green
	shape.setFillColor(sf::Color::Green);
  // keeps program running while window is open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
