#ifndef PLAY_AREA_HPP
#define PLAY_AREA_HPP

#include "SFML/Graphics.hpp"

#include "SideArea.hpp"
#include "Tetrimino.hpp"
#include "GameOverPopup.hpp"
#include "PausePopup.hpp"

class PlayArea
{
	private:
		sf::RectangleShape border;

		GameOverPopup game_over_popup;
		PausePopup pause_popup;

		bool game_paused = true;

	public:
		void initialise(sf::RenderWindow& window, SideArea& side_area);
		void handleEvents(sf::RenderWindow& window, sf::Event& event);
		void update(sf::RenderWindow& window, const float elapsedTime);
		void render(sf::RenderWindow& window);

		Tetrimino tetrimino;

		enum colors { LIGHT_BLUE, DARK_BLUE, ORANGE, YELLOW, GREEN, RED, PURPLE, EMPTY };

		int board[10][20];
};

#endif