#include "SideArea.hpp"

void SideArea::initialise(sf::RenderWindow& window)
{
	border.setPosition(sf::Vector2f(25, 25));
	border.setSize(sf::Vector2f(window.getSize().x / 3 + 78, window.getSize().y - 56));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(sf::Color(211, 210, 199));
	border.setOutlineThickness(6);

	font.loadFromFile("assets/FredokaOne-Regular.ttf");

	const int character_size = 30;
	const sf::Color text_color = sf::Color(211, 210, 190);
	const int offset = 20;

	restart_text.setFont(font);
	restart_text.setFillColor(text_color);
	restart_text.setString("Restart (R)");
	restart_text.setCharacterSize(character_size);
	restart_text.setPosition(sf::Vector2f(border.getPosition().x + offset - restart_text.getGlobalBounds().left, border.getPosition().y + offset - restart_text.getGlobalBounds().top));

	pause_text.setFont(font);
	pause_text.setFillColor(text_color);
	pause_text.setString("Pause (P)");
	pause_text.setCharacterSize(character_size);
	pause_text.setPosition(sf::Vector2f(border.getPosition().x + offset - pause_text.getGlobalBounds().left, border.getPosition().y + offset - pause_text.getGlobalBounds().top + restart_text.getGlobalBounds().height + 10));


	lines_text.setFont(font);
	lines_text.setFillColor(text_color);
	lines_text.setCharacterSize(character_size);
	lines_text.setPosition(sf::Vector2f(border.getPosition().x + offset, pause_text.getGlobalBounds().top + pause_text.getGlobalBounds().height + 100));
}

void SideArea::update(sf::RenderWindow& window, const float elapsedTime, const int lines_completed)
{
	const int offset = 20;

	lines_text.setString("Lines: " + std::to_string(lines_completed));
}

void SideArea::render(sf::RenderWindow& window)
{
	window.draw(border);

	window.draw(restart_text);
	window.draw(pause_text);

	window.draw(lines_text);
}