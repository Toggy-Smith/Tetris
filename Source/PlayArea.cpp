#include "PlayArea.hpp"

void PlayArea::initialise(sf::RenderWindow& window, SideArea& side_area)
{
	border.setPosition(sf::Vector2f(side_area.border.getPosition().x + side_area.border.getSize().x + 25 + 6, 25));
	border.setSize(sf::Vector2f(window.getSize().x - border.getPosition().x - border.getSize().x - 25, window.getSize().y - 56));
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(sf::Color(211, 210, 199));
	border.setOutlineThickness(6);

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			board[x][y] = EMPTY;
		}
	}

	tetrimino.initialise();
	tetrimino.select_random_tetrimino(board);

	game_over_popup.initialise(border);
	pause_popup.initialise(border);
}

void PlayArea::handleEvents(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Down)
		{
			tetrimino.quick_fall = true;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			tetrimino.move(board, -1);
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			tetrimino.move(board, 1);
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			tetrimino.rotate(board, 1);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			tetrimino.quick_fall = false;
		}
		else if (event.key.code == sf::Keyboard::P)
		{
			game_paused = !game_paused;
		}
	}
}

void PlayArea::update(sf::RenderWindow& window, const float elapsedTime)
{
	if (!game_paused)
	{
		tetrimino.update(board);
	}
}

void PlayArea::render(sf::RenderWindow& window)
{
	window.draw(border);

	// Draw the locked tetriminos
	float square_size = 5 * 6.14754098;
	float space_between_squares = 1 * 6.14754098;

	sf::RectangleShape tile;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			tile.setSize(sf::Vector2f(square_size, square_size));
			tile.setOrigin(sf::Vector2f(square_size / 2, square_size / 2));
			tile.setPosition(sf::Vector2f(border.getPosition().x + square_size / 2 + space_between_squares + (square_size + space_between_squares) * x, border.getPosition().y + square_size / 2 + space_between_squares + (square_size + space_between_squares) * y));

			tile.setFillColor(tetrimino.get_tile_color(board[x][y]));

			window.draw(tile);
		}
	}

	// Draw the falling tetrimino
	tetrimino.render(window, board, border);

	// Draw game over popup
	if (tetrimino.game_over)
	{
		game_over_popup.render(window);
	}

	// Draw pause popup
	if (game_paused)
	{
		pause_popup.render(window);
	}
}