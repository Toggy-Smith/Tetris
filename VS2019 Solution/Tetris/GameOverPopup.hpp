#ifndef GAME_OVER_POPUP_HPP
#define GAME_OVER_POPUP_HPP

#include "SFML/Graphics.hpp"

class GameOverPopup
{
	private:
		sf::RectangleShape background;

		sf::Font font;

		sf::Text game_over_text;
		sf::Text press_restart_text;

	public:
		void initialise(sf::RectangleShape& border);
		void render(sf::RenderWindow& window);
};

#endif