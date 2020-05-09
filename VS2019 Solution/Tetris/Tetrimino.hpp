#ifndef TETRIMINO_HPP
#define TETRIMINO_HPP

#include "SFML/Graphics.hpp"

#include <vector>
#include <array>
#include <random>

// REMOVE LATER
#include <iostream>

class Tetrimino
{
	private:
		typedef std::array<std::array<int, 4>, 4> grid;

		grid current_shape;

		int current_type;
		int current_rotation = 0;

		std::vector<std::vector<grid>> possible_shapes;

		void clear_tetrimino();
		void lock_tetrimino(int (&board)[10][20]);

		sf::Clock fall_clock;

		enum colors { LIGHT_BLUE, DARK_BLUE, ORANGE, YELLOW, GREEN, RED, PURPLE, EMPTY };

		sf::IntRect get_current_shape_bounds();

		bool is_out_of_bounds();
		
		void shift_board_down(int (&board)[10][20], std::vector<int> lines);
		void check_for_completed_lines(int (&board)[10][20]);

	public:
		sf::Color get_tile_color(int tile_type);

		bool quick_fall = false;
		bool game_over = false;

		int lines_completed = 0;

		sf::Vector2i position;

		void initialise();
		void select_random_tetrimino(int (&board)[10][20]);
		void rotate(int (&board)[10][20], int direction);
		void move(int (&board)[10][20], int amount);
		void update(int (&board)[10][20]);
		void render(sf::RenderWindow& window, int (&board)[10][20], sf::RectangleShape& border);
};

#endif