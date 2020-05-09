#ifndef PAUSE_POPUP_HPP
#define PAUSE_POPUP_HPP

#include "SFML/Graphics.hpp"

class PausePopup
{
	private:
		sf::RectangleShape background;

		sf::Font font;

		sf::Text paused_text;
		sf::Text press_pause_text;

	public:
		void initialise(sf::RectangleShape& border);
		void render(sf::RenderWindow& window);
};

#endif