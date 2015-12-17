//<Lab 9> - - Creating BattleShip
//CSIS 111-02

//include statements
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std; 

ifstream myinfile;

const int gameBoardWidth = 25;
const int gameBoardHeight = 25;

void Fire(const int gameBoardWidth, const int gameBoardHeight, int X, int Y, char gameBoard[][25]);
void FleetSunk(const int gameBoardWidth, const int gameBoardHeight, int X, int Y, char gameBoard[][25], bool &GameOver);

int main()
{
	cout << "Titus Dyck -- Lab 9 (BattleShip)" << endl << endl;
	myinfile.open("Board.txt");

	// variables 
	char gameBoard[gameBoardWidth][gameBoardHeight];
	int X;
	int Y; 
	bool GameOver;

	for (int i = 0; i < 25;  i++)
	{
		for (int j = 0; j < 25; j++)
			myinfile >> gameBoard[i][j];
	}

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
			myinfile >> gameBoard[i][j];
			
	}





	GameOver = false;
	while (!GameOver)
	{
		cout << endl <<  "Please enter a X cordinate from 0 to 24 for your Attack" << endl << endl;
		cin >> X;
		cout << endl;
		cout << "Please enter a Y cordinate from 0 to 24 for your Attack" << endl << endl;
		cin >> Y;
		cout << endl;

		Fire(gameBoardHeight, gameBoardWidth, X, Y,gameBoard);
		FleetSunk(gameBoardHeight, gameBoardWidth, X, Y,gameBoard, GameOver);
		
	}

	


	//closing program statements
	myinfile.close();
	system("pause");
	return 0; 
}

// function declarations 
void Fire(const int gameBoardWidth, const int gameBoardHeight, int X, int Y, char gameBoard[][25])
{
	if (gameBoard[X][Y] == '#')
	{
		cout << "HIT" << endl;
		gameBoard[X][Y] = 'H';
		
	}

	else if (gameBoard[X][Y] == 'H')
	{
		cout << "HIT AGAIN" << endl;
	}

	else
	{
		cout << "MISS" << endl;
	}

}

void FleetSunk(const int gameBoardWidth, const int gameBoardHeight, int X, int Y, char gameBoard[][25], bool &GameOver)
{
	bool NoPound;
	NoPound = false;

	for (int i = 0; i < 25; i++)
	 {
		 for (int j = 0; j < 25; j++)
			 
			 if (gameBoard[i][j] == '~' || gameBoard[i][j] == 'H')
				 NoPound = true;

			 else
			 {
				 NoPound = false;
				 break;
			 }
			 if (NoPound == false)
			 break;
	 }


	

	 if (NoPound == true)
	 {
		 GameOver = true;
		 cout << "The Entire Enemey Fleet has been destroyed, well done Admiral!" << endl << endl;
		 cout << " Game Over" << endl << endl;
		 
	 }
}