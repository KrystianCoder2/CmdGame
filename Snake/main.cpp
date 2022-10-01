#include "MainMenu.h"
#include <memory>

using namespace std;

int main()
{
	/* For debug only! */
	//for (int j = 0; j < 99; j++)
	//{
	//	for (int i = 0; i < 21; i++)
	//	{
	//		if (game->map[i][j] == '*')
	//		{
	//			cout << "It's on, X: " << i << " Y: " << j << endl;
	//		}
	//	}
	//}

	/*
	Smart pointers are like normal pointers
	but smart pointers get deleted when program exits
	( So we dont need to worry about memory leaks ) 
	*/

	// Creates smart pointer of MainMenu class, and calls Menu()
	unique_ptr<MainMenu> mainMenu = make_unique<MainMenu>();
	mainMenu->Menu();
}
