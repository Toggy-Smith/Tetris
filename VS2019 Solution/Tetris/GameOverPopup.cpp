#include "GameOverPopup.hpp"

void GameOverPopup::initialise(sf::RectangleShape& border)
{
	background.setSize(sf::Vector2f(border.getSize().x, 252));
	background.setPosition(sf::Vector2f(border.getPosition().x, border.getPosition().y));
	background.setFillColor(sf::Color(sf::Color(253, 255, 247)));
	background.setOutlineColor(sf::Color(211, 210, 199));
	background.setOutlineThickness(6);

	font.loadFromFile("assets/FredokaOne-Regular.ttf");

	const int character_size = 30;
	const sf::Color text_color = sf::Color(211, 210, 190);

	game_over_text.setFont(font);
	game_over_text.setFillColor(text_color);
	game_over_text.setString("Game over!");
	game_over_text.setCharacterSize(character_size);
	game_over_text.setPosition(sf::Vector2f(background.getPosition().x + background.getSize().x / 2 - game_over_text.getGlobalBounds().left - game_over_text.getGlobalBounds().width / 2, background.getPosition().y + background.getSize().y / 3 - game_over_text.getGlobalBounds().top - game_over_text.getGlobalBounds().height / 2));

	press_restart_text.setFont(font);
	press_restart_text.setFillColor(text_color);
	press_restart_text.setString("Press R to restart");
	press_restart_text.setCharacterSize(character_size);
	press_restart_text.setPosition(sf::Vector2f(background.getPosition().x + background.getSize().x / 2 - press_restart_text.getGlobalBounds().left - press_restart_text.getGlobalBounds().width / 2, background.getPosition().y + background.getSize().y / 3 * 2 - press_restart_text.getGlobalBounds().top - press_restart_text.getGlobalBounds().height / 2));

}

void GameOverPopup::render(sf::RenderWindow& window)
{
	window.draw(background);

	window.draw(game_over_text);
	window.draw(press_restart_text);
}