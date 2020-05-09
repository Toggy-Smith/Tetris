#include "SFML/Graphics.hpp"

#include "PlayArea.hpp"
#include "SideArea.hpp"

void initialise(sf::RenderWindow& window, PlayArea& play_area, SideArea& side_area)
{
	side_area.initialise(window);
	play_area.initialise(window, side_area);
}

void handleEvents(sf::RenderWindow& window, PlayArea& play_area, SideArea& side_area)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (!play_area.tetrimino.game_over)
		{
			play_area.handleEvents(window, event);
		}

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::R)
			{
				play_area.tetrimino.lines_completed = 0;
				play_area.tetrimino.position = sf::Vector2i(3, 0);
				play_area.tetrimino.select_random_tetrimino(play_area.board);

				for (int x = 0; x < 10; x++)
				{
					for (int y = 0; y < 20; y++)
					{
						play_area.board[x][y] = play_area.EMPTY;
					}
				}

				play_area.tetrimino.quick_fall = false;
				play_area.tetrimino.game_over = false;
			}
		}
	}
}

void update(sf::RenderWindow& window, PlayArea& play_area, SideArea& side_area)
{
	static sf::Clock updateClock;

	float elapsedTime = updateClock.getElapsedTime().asSeconds();

	if (!play_area.tetrimino.game_over)
	{
		play_area.update(window, elapsedTime);
	}

	side_area.update(window, elapsedTime, play_area.tetrimino.lines_completed);

	updateClock.restart();
}

void render(sf::RenderWindow& window, PlayArea& play_area, SideArea& side_area)
{
	window.clear(sf::Color(253, 255, 247));

	play_area.render(window);
	side_area.render(window);

	window.display();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris", sf::Style::Close);

	PlayArea play_area;
	SideArea side_area;

	initialise(window, play_area, side_area);

	while (window.isOpen())
	{
		handleEvents(window, play_area, side_area);

		update(window, play_area, side_area);

		render(window, play_area, side_area);
	}
}