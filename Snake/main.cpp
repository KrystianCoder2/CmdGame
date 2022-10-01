#include "MainMenu.h"
#include <memory>

using namespace std;

int main()
{
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

	unique_ptr<MainMenu> mainMenu = make_unique<MainMenu>();
	mainMenu->Menu();
}
