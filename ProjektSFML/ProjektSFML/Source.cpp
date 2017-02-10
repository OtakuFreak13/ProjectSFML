#include <SFML/Graphics.hpp>



int main() {

	//sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	//sf::CircleShape shape;
	//shape.setRadius(40.f);
	//shape.setPosition(100.f, 100.f);
	//shape.setFillColor(sf::Color::Cyan);

	//while (window.isOpen()) {

	//	sf::Event event;
	//	while (window.pollEvent(event)) {

	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	window.clear();
	//	window.draw(shape);
	//	window.display();
	//}




	sf::RenderWindow renderWindow(sf::VideoMode(200, 200), "SFML Demo");
	sf::Event event;
	sf::CircleShape shape;
	shape.setRadius(50.f);
	shape.setPosition(50.f, 50.f);
	shape.setFillColor(sf::Color::Magenta);

	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}
		}
		renderWindow.clear();
		renderWindow.draw(shape);
		renderWindow.display();
	}

}