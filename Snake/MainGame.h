#include <iostream>
#include <Windows.h>

class MainGame
{
private:
	int x = 1;
	int y = 1;

	int xFruit = 0;
	int yFruit = 0;
	int fruitCount = 0;

public:
	char map[21][99] = {
		"##################################################################################################",
		"#@                                                                                               #",
		"#                                                                                                #",
		"#                                                                                                #",
		"#                                                                                                #",
		"#                                                                                                #",
		"#                                                                                                #",
		"#                                  ## ##### ###                                                  #",
		"#                                  #      #  !#            ######*######                         #",
		"#                                  #      #####            #           #                         #",
		"#                                  #          #            #  ! ! ! !  #                         #",
		"#                                  ############            #           #                         #",
		"#                                                          #############                         #",
		"#                                                                                                #",
		"#                                                                                                #",
		"#                                      # ##########                                              #",
		"#                                      #    #######                                              #",
		"#                                      # !   ######                                              #",
		"#                                      #     $ ####                                              #",
		"#                                      ############                                              #",
		"##################################################################################################"
	};
	int fruitCollected = 0;

	void Move(int H, int V)
	{
		int x2 = x + H;
		int y2 = y + V;

		if (map[y][x2] == ' ')
		{
			map[y][x] = ' ';
			x += H;
			map[y][x] = '@';
		}
		if (map[y2][x] == ' ')
		{
			map[y][x] = ' ';
			y += V;
			map[y][x] = '@';
		}

		// Fruits
		if (map[y2][x] == '%')
		{
			map[y][x] = ' ';
			fruitCount--;
			y += V;
			fruitCollected++;
			map[y][x] = '@';
		}
		if (map[y][x2] == '%')
		{
			map[y][x] = ' ';
			fruitCount--;
			x += H;
			fruitCollected++;
			map[y][x] = '@';
		}

		// Treasures
		if (map[y2][x] == '!')
		{
			map[y][x] = ' ';
			y += V;
			fruitCollected += 10;
			map[y][x] = '@';
		}
		if (map[y][x2] == '!')
		{
			map[y][x] = ' ';
			x += H;
			fruitCollected += 10;
			map[y][x] = '@';
		}

		// Buttons
		if (map[y2][x] == '$')
		{
			map[8][65] = ' ';
			map[y][x] = ' ';
			y += V;
			map[y][x] = '@';
		}
		if (map[y][x2] == '$')
		{
			map[8][65] = ' ';
			map[y][x] = ' ';
			x += H;
			map[y][x] = '@';
		}
	}

	void SpawnFruit()
	{
		xFruit = (rand() % 99) + 1;
		yFruit = (rand() % 21) + 1;

		if (map[xFruit][yFruit] == ' ' && fruitCount < 3)
		{
			fruitCount++;
			map[xFruit][yFruit] = '%';
		}
	}
};
