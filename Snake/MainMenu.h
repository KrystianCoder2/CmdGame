#pragma once

#include "MainGame.h"

// Pointer of MainGame class
MainGame* game = new MainGame();

class MainMenu
{
private:
	bool gamerunning;
public:
	~MainMenu()
	{
		// Deletes the pointer of MainGame when this class is destroyed
		delete game;
	}

	void Menu()
	{
		game->Reset();
		while (true)
		{
			// Main Menu
			system("cls");
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "|----------------------------------------|" << std::endl;
			std::cout << "|-1.-Start-the-game----------------------|" << std::endl;
			std::cout << "|-2.-Guide-------------------------------|" << std::endl;
			std::cout << "|-3.-Exit--------------------------------|" << std::endl;
			std::cout << "|----------------------------------------|" << std::endl;
			std::cout << "|----------------------------------------|" << std::endl;
			std::cout << "------------------------------------------" << std::endl;

			system("pause>nul");

			if (GetAsyncKeyState(0x31)) // Checks if 1 button is pressed on keyboard
			{
				gamerunning = true;
				Game();
			}
			if (GetAsyncKeyState(0x32)) // Checks if 2 button is pressed on keyboard
			{
				Guide();
			}
			if (GetAsyncKeyState(0x33)) // Checks if 3 button is pressed on keyboard
			{
				gamerunning = false;
				exit(1);
			}
		}
	}

	void Game()
	{
		while (gamerunning)
		{
			system("cls");

			// Get fruitsCollected int and print it to the top of the screen
			std::cout << "Fruits: " << game->fruitCollected << std::endl;
			std::cout << "<<You can press Escape to go back to menu [(Progress will not be saved)]>>" << std::endl;

			for (int i = 0; i < 21; i++)
			{
				std::cout << game->map[i] << std::endl;
			}

			system("pause>nul");

			game->SpawnFruit();

			// Checks for input
			if (GetAsyncKeyState(VK_UP))
				game->Move(0, -1);
			if (GetAsyncKeyState(VK_DOWN))
				game->Move(0, 1);
			if (GetAsyncKeyState(VK_RIGHT))
				game->Move(1, 0);
			if (GetAsyncKeyState(VK_LEFT))
				game->Move(-1, 0);
			if (GetAsyncKeyState(VK_ESCAPE))
				Menu();
		}
	}

	void Guide()
	{
		while (1)
		{
			system("cls");
			std::cout << "---------------------------------------------------------------------" << std::endl;
			std::cout << "|      <<GUIDE>>                                                    |" << std::endl;
			std::cout << "|-#->Is-a-Wall-(You-cant-walk-here)                                 |" << std::endl;
			std::cout << "|-@->Is-a-Player-(Press-|Up-Down-Left-Right|-Arrow-Keys-To-Walk)    |" << std::endl;
			std::cout << "|-%->Is-a-Fruit-(Walk-into-to-grab-it[+1])                          |" << std::endl;
			std::cout << "|-*->Is-a-Smart-Wall-(You-can-deactivate-by-walking-into-button)    |" << std::endl;
			std::cout << "|-$->Is-a-Button-You-can-walk-into-it-to-deactivate-Smart-Wall      |" << std::endl;
			std::cout << "|-!->Is-a-Treasure-(Walk-into-to-grab-it[+10])                      |" << std::endl;
			std::cout << "|-------------------------------------------------------------------|" << std::endl;
			std::cout << "|         <<Press Escape to go back to menu>>                       |" << std::endl;
			std::cout << "|-------------------------------------------------------------------|" << std::endl;
			std::cout << "---------------------------------------------------------------------" << std::endl;

			// If Escape is clicked then we exit to main menu
			if (GetAsyncKeyState(VK_ESCAPE))
				Menu();
		}
	}
};
