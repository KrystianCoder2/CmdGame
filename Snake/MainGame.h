#include <iostream>
#include <Windows.h>

const char pMap[21][99] = {
	"##################################################################################################",
	"#@                                                                                               #",
	"#                                                #  #                                            #",
	"#                                         ########  #                                            #",
	"#                                         #         #                                            #",
	"#                                         # #########                                            #",
	"#                                         # #                                                    #",
	"#                                  ## ##### ###                                                  #",
	"#                                  #      #  !#            ######*######                         #",
	"#                                  #      #####            #           #                         #",
	"#                                  #         !#            #  ! ! ! !  #                         #",
	"#                                  ############            #           #                         #",
	"#                            # #                           #############                         #",
	"#                            # ##########                                                        #",
	"#                            #          #                                                        #",
	"#                            ########## ###########                                              #",
	"#                                     # #  !#######                                              #",
	"#                                  #### #    ######                                              #",
	"#                                  #         $ ####                                              #",
	"#                                  ################                                              #",
	"##################################################################################################"
};

class MainGame
{
public:
	// X and Y position of the player ( In characters )
	int x = 1;
	int y = 1;

	// X and Y position of fruit that randomly spawn ( Max 3 on map )
	int xFruit = 0;
	int yFruit = 0;
	int fruitCount = 0;

	// Map of the game
	char map[21][99] = {
		"##################################################################################################",
		"#@                                                                                               #",
		"#                                                #  #                                            #",
		"#                                         ########  #                                            #",
		"#                                         #         #                                            #",
		"#                                         # #########                                            #",
		"#                                         # #                                                    #",
		"#                                  ## ##### ###                                                  #",
		"#                                  #      #  !#            ######*######                         #",
		"#                                  #      #####            #           #                         #",
		"#                                  #         !#            #  ! ! ! !  #                         #",
		"#                                  ############            #           #                         #",
		"#                            # #                           #############                         #",
		"#                            # ##########                                                        #",
		"#                            #          #                                                        #",
		"#                            ########## ###########                                              #",
		"#                                     # #  !#######                                              #",
		"#                                  #### #    ######                                              #",
		"#                                  #         $ ####                                              #",
		"#                                  ################                                              #",
		"##################################################################################################"
	};
	int fruitCollected = 0;

	void Reset()
	{
		fruitCollected = 0;
		x = 1;
		y = 1;
		fruitCount = 0;
		xFruit = 0;
		yFruit = 0;
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 99; j++)
				map[i][j] = pMap[i][j];
	}

	// Move method of player
	void Move(int H, int V)
	{
		// If x = 1 and we press left button than we set H to 1 and x2 is x + H;
		// If y = 1 and we press down button than we set V to 1 and y2 is y + H;
		int x2 = x + H;
		int y2 = y + V;

		// Checks if next char is empty, if not == then player does not move
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
		// Random X position of fruit from 1 to 99
		xFruit = (rand() % 99) + 1;
		// Random Y position of fruit from 1 to 21
		yFruit = (rand() % 21) + 1;
		
		// Checks if xFruit and yFruit position on map is empty if yes than we spawn if not, do nothing
		if (map[yFruit][xFruit] == ' ' && fruitCount < 3)
		{
			fruitCount++;
			map[yFruit][xFruit] = '%';
		}
	}
};
