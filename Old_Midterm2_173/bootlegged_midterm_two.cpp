


#include <vector>
#include <cmath>

#include "Ball.h"
#include "Player.h"

#include "graphics.h"



const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int DELAY = 33;

void phase_one(Player& player);

bool ball_collision(Ball left_ball, Ball right_ball);

void phase_two(Player& player);

void phase_three(Player& player);

int main()
{
	initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	Player some_guy = Player(0, WINDOW_HEIGHT - 100, 100);
	phase_one(some_guy);
	phase_two(some_guy);
	phase_three(some_guy);

	return 0;
}

bool ball_collision(Ball left_ball, Ball right_ball)
{
	double x_2 = pow(left_ball.getXPos() - right_ball.getXPos(), 2);
	double y_2 = pow(left_ball.getYPos() - right_ball.getYPos(), 2);

	double d = sqrt(x_2 + y_2);

	int collision_d = left_ball.getRadius() + right_ball.getRadius();

	if (d <= collision_d)
	{
		return true;
	}
	else 
		return false;
}


void phase_one(Player& player)
{
	Ball ball(WINDOW_WIDTH / 2, 50, 10, 10, 50, 4);

	std::vector<Ball> player_shots;

	bool done = false;
	char key_input = 0;

	while (!done)
	{
		while (kbhit())
		{
			key_input = getch();
		}

		switch (key_input)
		{
		case 27:
			done = true;
			break;
		case 32:
			player_shots.push_back(Ball(player.getXPos() + player.getSize() / 2, player.getYPos(), 0, -20, 15, 9));
			break;
		case 75:
			player.moveLeft(WINDOW_WIDTH);
			break;
		case 77:
			player.moveRight(WINDOW_WIDTH);
			break;
		}
		key_input = 0;

		ball.draw();
		ball.move_ball();
		ball.border_coliision(WINDOW_WIDTH, WINDOW_HEIGHT / 2);
		player.draw();

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].draw();
		}

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].move_ball();
		}
		for (int i = 0; i < player_shots.size(); i++)
		{
			if (player_shots[i].isOffScreen(WINDOW_WIDTH, WINDOW_HEIGHT))
			{
				player_shots.erase(player_shots.begin() + i);
			}
		}

		for (int i = 0; i < player_shots.size(); i++)
		{
			if (ball_collision(ball, player_shots[i]))
			{
				done = true;
				break;
			}
		}

		delay(DELAY);
		cleardevice();
	}

}


void phase_two(Player& player)
{
	std::vector<Ball> game_balls;

	std::vector<Ball> player_shots;

	game_balls.push_back(Ball(350, 50, -10, 10, 50, 14));
	game_balls.push_back(Ball(450, 50, 10, 10, 50, 14));

	bool done = false;
	char key_input = 0;
	while (!done)
	{
		while (kbhit())
		{
			key_input = getch();
		}

		switch (key_input)
		{
		case 27:
			done = true;
			break;
		case 32:
			player_shots.push_back(Ball(player.getXPos() + player.getSize() / 2, player.getYPos(), 0, -20, 15, 9));
			break;
		case 75:
			player.moveLeft(WINDOW_WIDTH);
			break;
		case 77:
			player.moveRight(WINDOW_WIDTH);
			break;
		}
		key_input = 0;

		for (int i = 0; i < game_balls.size(); i++)
		{
			game_balls[i].draw();
			game_balls[i].move_ball();
			game_balls[i].border_coliision(WINDOW_WIDTH, WINDOW_HEIGHT / 2);
		}
		player.draw();

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].draw();
		}

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].move_ball();
		}
		for (int i = 0; i < player_shots.size(); i++)
		{
			if (player_shots[i].isOffScreen(WINDOW_WIDTH, WINDOW_HEIGHT))
			{
				player_shots.erase(player_shots.begin() + i);
			}
		}

		for (int i = 0; i < game_balls.size(); i++)
		{
			for (int j = 0; j < player_shots.size(); j++)
			{
				if (ball_collision(game_balls[i], player_shots[j]))
				{
					game_balls.erase(game_balls.begin() + i);
					player_shots.erase(player_shots.begin() + j);
					break;
				}
			}
		}

		if (game_balls.empty())
		{
			done = true;
		}

		delay(DELAY);
		cleardevice();
	}

}

void phase_three(Player& player)
{
	std::vector<Ball> game_balls;

	std::vector<Ball> player_shots;

	game_balls.push_back(Ball(350, 50, -10, 10, 50, 11));
	game_balls.push_back(Ball(250, 50, -10, 10, 50, 11));
	game_balls.push_back(Ball(550, 50, 10, 10, 50, 11));
	game_balls.push_back(Ball(450, 50, 10, 10, 50, 11));

	bool done = false;
	char key_input = 0;

	while (!done)
	{
		while (kbhit())
		{
			key_input = getch();
		}

		switch (key_input)
		{
		case 27:
			done = true;
			break;
		case 32:
			player_shots.push_back(Ball(player.getXPos() + player.getSize() / 2, player.getYPos(), 0, -20, 15, 9));
			break;
		case 75:
			player.moveLeft(WINDOW_WIDTH);
			break;
		case 77:
			player.moveRight(WINDOW_WIDTH);
			break;
		}
		key_input = 0;

		for (int i = 0; i < game_balls.size(); i++)
		{
			game_balls[i].draw();
			game_balls[i].move_ball();
			game_balls[i].border_coliision(WINDOW_WIDTH, WINDOW_HEIGHT / 2);
		}
		player.draw();

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].draw();
		}

		for (int i = 0; i < player_shots.size(); i++)
		{
			player_shots[i].move_ball();
		}
		for (int i = 0; i < player_shots.size(); i++)
		{
			if (player_shots[i].isOffScreen(WINDOW_WIDTH, WINDOW_HEIGHT))
			{
				player_shots.erase(player_shots.begin() + i);
			}
		}

		for (int i = 0; i < game_balls.size(); i++)
		{
			for (int j = 0; j < player_shots.size(); j++)
			{
				if (ball_collision(game_balls[i], player_shots[j]))
				{
					game_balls.erase(game_balls.begin() + i);
					player_shots.erase(player_shots.begin() + j);
					break;  
				}
			}
		}

		if (game_balls.empty())
		{
			done = true;
		}

		delay(DELAY);
		cleardevice();
	}

}

