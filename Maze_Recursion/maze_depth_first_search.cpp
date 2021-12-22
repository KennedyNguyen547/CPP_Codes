




#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>

/* this will work on windows or any C++ compiler with <Windows.h>
*/

const int CONSOLE_WIDTH = 80;
const int CONSOLE_HEIGHT = 25;


enum Position {EMPTY, BEEN_THERE, NOT_EMPTY};


void put_char(const int& x_pos, const int& y_pos, std::string character, int color);

void initialize_maze(Position maze[][CONSOLE_HEIGHT]);

void draw_maze(const int& start_x_pos, const int& start_y_pos, const int& goal_x_pos, const int& goal_y_pos, const double& obstruction_ratio, Position maze[][CONSOLE_HEIGHT]);

bool find_goal_position(int x_pos, int y_pos, int goal_x_pos, int goal_y_pos, Position maze[][CONSOLE_HEIGHT]);


int main()
{
	bool success;

	int just_an_int;

	srand(GetTickCount());

	Position maze[CONSOLE_WIDTH][CONSOLE_HEIGHT];

	initialize_maze(maze);

	int start_x, start_y, end_x, end_y;

	double obstacle_ratio;

	std::cout << "\nThis is a bootlegged depth first search maze solver.\n" << "Enter a positive integer less than 81 for the starting x position >> ";
	std::cin >> start_x;
	std::cout << "Now enter a positive integer less than 26 for the starting y position >> ";
	std::cin >> start_y;
	std::cout << "Now enter a positive integer less than 81 for the ending x position >> ";
	std::cin >> end_x;
	std::cout << "Now enter a positive integer less than 26 for the ending y position >> ";
	std::cin >> end_y;
	std::cout << "Now enter an obstacle ratio between 0 and 1 >> ";
	std::cin >> obstacle_ratio;

	std::cout << "Press any key to continue...";

	just_an_int = _getch();
	system("cls");
	draw_maze(start_x, start_y, end_x, end_y, obstacle_ratio, maze);

	just_an_int = _getch();
	success = find_goal_position(start_x, start_y, end_x, end_y, maze);

	just_an_int = _getch();

	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);


	if (success)
	{
		SetConsoleTextAttribute(console_handle, 10);
		std::cout << "The DFS solver found the goal! \n";
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		std::cout << "The DFS solver couldn't find the goal!\n";
	}

	while (!_kbhit());

	return 0;

}


void put_char(const int& x_pos, const int& y_pos, std::string character, int color)
{
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_handle, color);
	COORD position;

	position.X = x_pos;
	position.Y = y_pos;

	SetConsoleCursorPosition(console_handle, position);
	WriteConsole(console_handle, character.c_str(), 1, NULL, NULL);
}

void initialize_maze(Position maze[][CONSOLE_HEIGHT])
{
	for (int x = 0; x < CONSOLE_WIDTH; x++)
	{
		for (int y = 0; y < CONSOLE_HEIGHT; y++)
		{
			maze[x][y] = EMPTY;
		}
	}
}

void draw_maze(const int& start_x_pos, const int& start_y_pos, const int& goal_x_pos, const int& goal_y_pos, const double& obstruction_ratio, Position maze[][CONSOLE_HEIGHT])
{
	int number_of_obstacles = static_cast<int>(CONSOLE_WIDTH * CONSOLE_HEIGHT * obstruction_ratio);
	int x_pos, y_pos;

	for (int i = 0; i < number_of_obstacles; i++)
	{
		x_pos = rand() % CONSOLE_WIDTH;
		y_pos = rand() % CONSOLE_HEIGHT;
		put_char(x_pos, y_pos, "X", 15);
		maze[x_pos][y_pos] = NOT_EMPTY;
	}

	put_char(start_x_pos, start_y_pos, "S", FOREGROUND_GREEN);
	maze[start_x_pos][start_y_pos] = EMPTY;
	put_char(goal_x_pos, goal_y_pos, "G", FOREGROUND_GREEN);
	maze[goal_x_pos][goal_y_pos] = EMPTY;
}


bool find_goal_position(int x_pos, int y_pos, int goal_x_pos, int goal_y_pos, Position maze[][CONSOLE_HEIGHT])
{
	if (x_pos == goal_x_pos && y_pos == goal_y_pos)
	{
		return true;
	}
	put_char(x_pos, y_pos, "T", FOREGROUND_GREEN);
	maze[x_pos][y_pos] = BEEN_THERE;
	Sleep(50);

	// check right of current position
	if (maze[x_pos + 1][y_pos] == EMPTY && x_pos + 1 < CONSOLE_WIDTH)
	{
		if (find_goal_position(x_pos + 1, y_pos, goal_x_pos, goal_y_pos, maze))
		{
			return true;
		}
	}
	// check bottom of current position
	if (maze[x_pos][y_pos + 1] == EMPTY && y_pos + 1 < CONSOLE_HEIGHT)
	{
		if (find_goal_position(x_pos, y_pos + 1, goal_x_pos, goal_y_pos, maze))
		{
			return true;
		}
	}
	// check left of current position
	if (maze[x_pos - 1][y_pos] == EMPTY && x_pos - 1 >= 0)
	{
		if (find_goal_position(x_pos - 1, y_pos, goal_x_pos, goal_y_pos, maze))
		{
			return true;
		}
	}

	//check above of current position
	if (maze[x_pos][y_pos - 1] == EMPTY && y_pos - 1 >= 0)
	{
		if (find_goal_position(x_pos, y_pos - 1, goal_x_pos, goal_y_pos, maze))
		{
			return true;
		}
	}
	return false;
}



