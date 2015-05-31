#include <iostream>
#include <string>

using namespace std;
bool roverPositionUpdate(int roverNum, int x, int y, char direction, int grid);

int main()
{
	int gridSize;
	int nRovers;
	int x;
	int y;
	char direction;
	bool move = false;
	string position;

	cout << "What is the size of the grid on which the rover(s) are travelling? ";
	cin >> gridSize;

	cout << "How many rovers are you controlling? ";
	cin >> nRovers;

	while (nRovers < 1 || nRovers >(gridSize / 2))
	{
		cout << "Incompatible number of rovers, please try again." << endl;
		cout << "How many rovers are you controlling? ";
		cin >> nRovers;
	}

	for (int i = 0; i < nRovers; i++)
	{ 
		cout << "Enter position and orientation information: ";
		cin >> x >> y >> direction;
		direction = toupper(direction);
		move = roverPositionUpdate(i, x, y, direction, gridSize);

		while (move == false)
		{
			cout << "Invalid move, please try again." << endl;
			cout << "Enter position and orientation information: ";
			cin >> x >> y >> direction;
			//cin >> x;
			//cin >> y;
			//cin >> direction;
			direction = toupper(direction);
			move = roverPositionUpdate(i, x, y, direction, gridSize);
		}

		cout << "Motion command for rover " << i << " successful!" << endl;
	}
}

bool roverPositionUpdate(int roverNum, int x, int y, char direction, int grid)
{
	string command;
	string waste;
	char orient = direction;
	int xPos = x;
	int yPos = y;
	int length;

	getline(cin,waste);
	cout << "For rover " << roverNum+1 << " enter motion command: ";
	getline(cin, command);

	length = command.length();
	//Capitalize the string of commands
	for (int i = 0; i < length; i++)
	{
		command[i] = toupper(command[i]);
	}

	
	for (int i = 0; i < length; i++)
	{
		if (command[i] == 'L')
		{
			if (orient == 'N')
			{
				orient = 'W';
			}
			else if (orient == 'W')
			{
				orient = 'S';
			}
			else if (orient == 'S')
			{
				orient = 'E';
			}
			else if (orient == 'E')
			{
				orient = 'N';
			}
			else
			{
				cout << "ERROR 1!!!" << endl;
			}
		}

		else if (command[i] == 'R')
		{
			if (orient == 'N')
			{
				orient = 'E';
			}
			else if (orient == 'W')
			{
				orient = 'N';
			}
			else if (orient == 'S')
			{
				orient = 'W';
			}
			else if (orient == 'E')
			{
				orient = 'S';
			}
			else
			{
				cout << "ERROR 2!!!" << endl;
			}
		}
		
		else if (command[i] == 'F')
		{
			if (orient == 'N')
			{
				yPos--;
			}
			else if (orient == 'S')
			{
				yPos++;
			}
			else if (orient == 'W')
			{
				xPos--;
			}
			else if (orient == 'E')
			{
				xPos++;
			}
		}
	}

	if (xPos > grid || yPos > grid || xPos < 0 || yPos < 0)
	{
		return false;
	}

	else
	{
		cout << "Current position of rover is " << xPos << " " << yPos << " " << orient << endl << endl;
		return true;
	}

}