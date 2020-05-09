#include "PausePopup.hpp"

void PausePopup::initialise(sf::RectangleShape& border)
{
	background.setSize(sf::Vector2f(border.getSize().x, 252));
	background.setPosition(sf::Vector2f(border.getPosition().x, border.getPosition().y));
	background.setFillColor(sf::Color(sf::Color(253, 255, 247)));
	background.setOutlineColor(sf::Color(211, 210, 199));
	background.setOutlineThickness(6);

	font.loadFromFile("assets/FredokaOne-Regular.ttf");

	const int character_size = 30;
	const sf::Color text_color = sf::Color(211, 210, 190);

	paused_text.setFont(font);
	paused_text.setFillColor(text_color);
	paused_text.setString("Game paused");
	paused_text.setCharacterSize(character_size);
	paused_text.setPosition(sf::Vector2f(background.getPosition().x + background.getSize().x / 2 - paused_text.getGlobalBounds().left - paused_text.getGlobalBounds().width / 2, background.getPosition().y + background.getSize().y / 3 - paused_text.getGlobalBounds().top - paused_text.getGlobalBounds().height / 2));

	press_pause_text.setFont(font);
	press_pause_text.setFillColor(text_color);
	press_pause_text.setString("Press P to unpause");
	press_pause_text.setCharacterSize(character_size);
	press_pause_text.setPosition(sf::Vector2f(background.getPosition().x + background.getSize().x / 2 - press_pause_text.getGlobalBounds().left - press_pause_text.getGlobalBounds().width / 2, background.getPosition().y + background.getSize().y / 3 * 2 - press_pause_text.getGlobalBounds().top - press_pause_text.getGlobalBounds().height / 2));

}

void PausePopup::render(sf::RenderWindow& window)
{
	window.draw(background);

	window.draw(paused_text);
	window.draw(press_pause_text);
}