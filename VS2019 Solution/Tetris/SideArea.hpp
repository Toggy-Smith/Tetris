#ifndef SIDE_AREA_HPP
#define SIDE_AREA_HPP

#include "SFML/Graphics.hpp"

class SideArea
{
	private:
		sf::Font font;

		sf::Text restart_text;
		sf::Text pause_text;
		
		sf::Text lines_text;

	public:
		void initialise(sf::RenderWindow& window);
		void update(sf::RenderWindow& window, const float elapsedTime, const int lines_completed);
		void render(sf::RenderWindow& window);

		sf::RectangleShape border;
};

#endif