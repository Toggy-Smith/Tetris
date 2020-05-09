#include "Tetrimino.hpp"

void Tetrimino::clear_tetrimino()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			current_shape[y][x] = EMPTY;
		}
	}
}

sf::Color Tetrimino::get_tile_color(int tile_type)
{
	switch (tile_type)
	{
		default:
			return sf::Color::Black;
		case LIGHT_BLUE:
			return sf::Color(89, 230, 255);
		case DARK_BLUE:
			return sf::Color(89, 169, 255);
		case ORANGE:
			return sf::Color(255, 150, 80);
		case YELLOW:
			return sf::Color(255, 237, 101);
		case GREEN:
			return sf::Color(89, 255, 160);
		case RED:
			return sf::Color(255, 89, 89);
		case PURPLE:
			return sf::Color(141, 89, 255);
		case EMPTY:
			return sf::Color(248, 249, 242);
	}
}

void Tetrimino::initialise()
{
	position = sf::Vector2i(3, 0);

	// Light blue
	std::vector<grid> rotation_positions_for_light_blue;

	{
		grid position1 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{LIGHT_BLUE, LIGHT_BLUE, LIGHT_BLUE, LIGHT_BLUE},
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, LIGHT_BLUE, EMPTY, EMPTY},
				{EMPTY, LIGHT_BLUE, EMPTY, EMPTY},
				{EMPTY, LIGHT_BLUE, EMPTY, EMPTY},
				{EMPTY, LIGHT_BLUE, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_light_blue.push_back(position1);
		rotation_positions_for_light_blue.push_back(position2);
	}


	// Dark blue
	std::vector<grid> rotation_positions_for_dark_blue;

	{
		grid position1 =
		{
			{
				{DARK_BLUE, EMPTY, EMPTY, EMPTY},
				{DARK_BLUE, DARK_BLUE, DARK_BLUE, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, DARK_BLUE, DARK_BLUE, EMPTY},
				{EMPTY, DARK_BLUE, EMPTY, EMPTY},
				{EMPTY, DARK_BLUE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position3 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{DARK_BLUE, DARK_BLUE, DARK_BLUE, EMPTY},
				{EMPTY, EMPTY, DARK_BLUE, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position4 =
		{
			{
				{EMPTY, DARK_BLUE, EMPTY, EMPTY},
				{EMPTY, DARK_BLUE, EMPTY, EMPTY},
				{DARK_BLUE, DARK_BLUE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_dark_blue.push_back(position1);
		rotation_positions_for_dark_blue.push_back(position2);
		rotation_positions_for_dark_blue.push_back(position3);
		rotation_positions_for_dark_blue.push_back(position4);
	}



	// Orange
	std::vector<grid> rotation_positions_for_orange;

	{
		grid position1 =
		{
			{
				{EMPTY, EMPTY, EMPTY, ORANGE},
				{EMPTY, ORANGE, ORANGE, ORANGE},
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, EMPTY, ORANGE, EMPTY},
				{EMPTY, EMPTY, ORANGE, EMPTY},
				{EMPTY, EMPTY, ORANGE, ORANGE},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position3 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, ORANGE, ORANGE, ORANGE},
				{EMPTY, ORANGE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position4 =
		{
			{
				{EMPTY, ORANGE, ORANGE, EMPTY},
				{EMPTY, EMPTY, ORANGE, EMPTY},
				{EMPTY, EMPTY, ORANGE, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_orange.push_back(position1);
		rotation_positions_for_orange.push_back(position2);
		rotation_positions_for_orange.push_back(position3);
		rotation_positions_for_orange.push_back(position4);
	}



	// Yellow
	std::vector<grid> rotation_positions_for_yellow;

	{
		grid position1 =
		{
			{
				{EMPTY, YELLOW, YELLOW, EMPTY},
				{EMPTY, YELLOW, YELLOW, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_yellow.push_back(position1);
	}

	// Green
	std::vector<grid> rotation_positions_for_green;

	{
		grid position1 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, GREEN, GREEN, EMPTY},
				{GREEN, GREEN, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, GREEN, EMPTY, EMPTY},
				{EMPTY, GREEN, GREEN, EMPTY},
				{EMPTY, EMPTY, GREEN, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_green.push_back(position1);
		rotation_positions_for_green.push_back(position2);
	}

	// Red
	std::vector<grid> rotation_positions_for_red;

	{
		grid position1 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{RED, RED, EMPTY, EMPTY},
				{EMPTY, RED, RED, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, EMPTY, RED, EMPTY},
				{EMPTY, RED, RED, EMPTY},
				{EMPTY, RED, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_red.push_back(position1);
		rotation_positions_for_red.push_back(position2);
	}

	// Purple
	std::vector<grid> rotation_positions_for_purple;

	{
		grid position1 =
		{
			{
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{PURPLE, PURPLE, PURPLE, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position2 =
		{
			{
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{EMPTY, PURPLE, PURPLE, EMPTY},
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position3 =
		{
			{
				{EMPTY, EMPTY, EMPTY, EMPTY},
				{PURPLE, PURPLE, PURPLE, EMPTY},
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		grid position4 =
		{
			{
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{PURPLE, PURPLE, EMPTY, EMPTY},
				{EMPTY, PURPLE, EMPTY, EMPTY},
				{EMPTY, EMPTY, EMPTY, EMPTY}
			}
		};

		rotation_positions_for_purple.push_back(position1);
		rotation_positions_for_purple.push_back(position2);
		rotation_positions_for_purple.push_back(position3);
		rotation_positions_for_purple.push_back(position4);
	}

	possible_shapes.push_back(rotation_positions_for_light_blue);
	possible_shapes.push_back(rotation_positions_for_dark_blue);
	possible_shapes.push_back(rotation_positions_for_orange);
	possible_shapes.push_back(rotation_positions_for_yellow);
	possible_shapes.push_back(rotation_positions_for_green);
	possible_shapes.push_back(rotation_positions_for_red);
	possible_shapes.push_back(rotation_positions_for_purple);
}

void Tetrimino::select_random_tetrimino(int (&board)[10][20])
{
	// Create the random tetrinimo
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 6);

	int type = dist(mt);

	current_shape = possible_shapes[type][0];

	current_type = type;

	current_rotation = 0;
	
	// Check to make sure the tetrinimo isn't overlapping any existing tiles
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] == EMPTY)
			{
				continue;
			}

			if (board[position.x + x][position.y + y] != EMPTY)
			{
				game_over = true;
			}
		}
	}
}

sf::IntRect Tetrimino::get_current_shape_bounds()
{
	int left = 999;
	int top = 999;

	int right = -999;
	int bottom = -999;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] != EMPTY)
			{
				if (x < left)
				{
					left = x;
				}

				if (y < top)
				{
					top = y;
				}

				if (x > right)
				{
					right = x;
				}

				if (y > bottom)
				{
					bottom = y;
				}
			}
		}
	}

	return sf::IntRect(left, top, right + 1 - left, bottom + 1- top);
}

bool Tetrimino::is_out_of_bounds()
{
	bool is_out_of_bounds = false;

	if (position.x < -get_current_shape_bounds().left)
	{
		is_out_of_bounds = true;
	}
	else if (position.x > 10 - get_current_shape_bounds().left - get_current_shape_bounds().width)
	{
		is_out_of_bounds = true;
	}
	else if (position.y > 20 - get_current_shape_bounds().top - get_current_shape_bounds().height)
	{
		is_out_of_bounds = true;
	}

	return is_out_of_bounds;
}

void Tetrimino::rotate(int (&board)[10][20], int direction)
{
	int previous_rotation = current_rotation;

	current_rotation += direction;
	
	if (current_rotation > (int) possible_shapes[current_type].size() - 1)
	{
		current_rotation = 0;
	}
	else if (current_rotation < 0)
	{
		current_rotation = possible_shapes[current_type].size() - 1;
	}

	current_shape = possible_shapes[current_type][current_rotation];

	if (is_out_of_bounds())
	{
		current_rotation = previous_rotation;

		current_shape = possible_shapes[current_type][current_rotation];
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] == EMPTY)
			{
				continue;
			}

			if (board[position.x + x][position.y + y] != EMPTY)
			{
				current_rotation = previous_rotation;

				current_shape = possible_shapes[current_type][current_rotation];
			}
		}
	}
}

void Tetrimino::move(int (&board)[10][20], int amount)
{
	position.x += amount;

	if (position.x < -get_current_shape_bounds().left)
	{
		position.x = -get_current_shape_bounds().left;
	}
	else if (position.x > 10 - get_current_shape_bounds().left - get_current_shape_bounds().width)
	{
		position.x = 10 - get_current_shape_bounds().left - get_current_shape_bounds().width;
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] == EMPTY)
			{
				continue;
			}

			if (board[position.x + x][position.y + y] != EMPTY)
			{
				position.x -= amount;
			}
		}
	}
}

void Tetrimino::shift_board_down(int (&board)[10][20], std::vector<int> lines)
{
	for (int i = 0; i < lines.size(); i++)
	{
		for (int y = lines[i]; y > 0; y--)
		{
			for (int x = 0; x < 10; x++)
			{
				board[x][y] = board[x][y - 1];
			}
		}
	}
}

void Tetrimino::check_for_completed_lines(int (&board)[10][20])
{
	std::vector<int> lines;

	for (int y = 19; y > 0; y--)
	{
		bool completed = true;

		for (int x = 0; x < 10; x++)
		{
			if (board[x][y] == EMPTY)
			{
				completed = false;
			}
		}

		if (completed)
		{
			lines_completed++;

			lines.push_back(y);
		}
	}

	shift_board_down(board, lines);

	if (lines.size() >= 1)
	{
		check_for_completed_lines(board);
	}
}

void Tetrimino::lock_tetrimino(int (&board)[10][20])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] == EMPTY)
			{
				continue;
			}

			board[position.x + x][position.y + y] = current_shape[y][x];
		}
	}

	position = sf::Vector2i(3, 0);

	select_random_tetrimino(board);

	check_for_completed_lines(board);
}

void Tetrimino::update(int (&board)[10][20])
{
	if (fall_clock.getElapsedTime().asSeconds() >= 0.5 || (quick_fall && fall_clock.getElapsedTime().asSeconds() >= 0.05))
	{
		position.y++;

		if (position.y > 20 - get_current_shape_bounds().top - get_current_shape_bounds().height)
		{
			position.y = 20 - get_current_shape_bounds().top - get_current_shape_bounds().height;

			lock_tetrimino(board);
		}
		else
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (current_shape[y][x] == EMPTY)
					{
						continue;
					}

					if (board[position.x + x][position.y + y] != EMPTY)
					{
						position.y--;

						lock_tetrimino(board);
					}
				}
			}
		}

		fall_clock.restart();
	}
}

void Tetrimino::render(sf::RenderWindow& window, int (&board)[10][20], sf::RectangleShape& border)
{
	float square_size = 5 * 6.14754098;
	float space_between_squares = 1 * 6.14754098;

	sf::RectangleShape tile;

	int original_y = position.y;

	while (true)
	{
		position.y++;

		if (position.y > 20 - get_current_shape_bounds().top - get_current_shape_bounds().height)
		{
			position.y = 20 - get_current_shape_bounds().top - get_current_shape_bounds().height;

			break;
		}
		else
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (current_shape[y][x] == EMPTY)
					{
						continue;
					}

					if (board[position.x + x][position.y + y] != EMPTY)
					{
						position.y--;

						goto breakout;
					}
				}
			}
		}
	}

	breakout:

	int shadow_tetrinomo_y = position.y;

	position.y = original_y;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] != EMPTY)
			{
				int actual_x = x + position.x;
				int actual_y = y + shadow_tetrinomo_y;

				tile.setSize(sf::Vector2f(square_size, square_size));
				tile.setOrigin(sf::Vector2f(square_size / 2, square_size / 2));
				tile.setPosition(sf::Vector2f(border.getPosition().x + square_size / 2 + space_between_squares + (square_size + space_between_squares) * actual_x, border.getPosition().y + square_size / 2 + space_between_squares + (square_size + space_between_squares) * actual_y));

				tile.setFillColor(sf::Color(120, 120, 120));

				window.draw(tile);
			}
		}
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (current_shape[y][x] != EMPTY)
			{
				int actual_x = x + position.x;
				int actual_y = y + position.y;

				tile.setSize(sf::Vector2f(square_size, square_size));
				tile.setOrigin(sf::Vector2f(square_size / 2, square_size / 2));
				tile.setPosition(sf::Vector2f(border.getPosition().x + square_size / 2 + space_between_squares + (square_size + space_between_squares) * actual_x, border.getPosition().y + square_size / 2 + space_between_squares + (square_size + space_between_squares) * actual_y));

				tile.setFillColor(get_tile_color(current_shape[y][x]));

				window.draw(tile);
			}
		}
	}
}