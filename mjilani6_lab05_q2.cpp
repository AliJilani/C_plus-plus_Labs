#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>

using namespace std;

void myHeader(string name, int lab, string date, int question); // print Header
int getUserNum();
int calcWinnings(int n);
int numOfDig(int num);

int main()
{
	int guess = 0;
	int winnings = 0;
	bool repeat = false;
	char again;

	myHeader("Ali Jilani", 4, "March 2nd 2015", 3);
	
	do
	{
		guess = getUserNum();
		winnings = calcWinnings(guess);

		cout << "*** You Win: $" << winnings << "!! ***" << endl << endl;

		cout << "Would you like to calculate again? (Y/y): ";
		cin >> again;
		cout << endl;

		if (again == 'y' || again == 'Y')
		{
			repeat = true;
		}
		else
		{
			repeat = false;
		}

	} while (repeat);



}

//Function to determine the number of digits
int numOfDig(int num)
{
	int length = 1;

	if (num > 0)
	{
		for (length = 0; num > 0; length++)
		{
			num = num / 10;
		}
	}

	return length;
}

int getUserNum()
{
	int guess;

	cout << "Please enter three digit lottery number: ";
	cin >> guess;

	while (guess > 0 && numOfDig(guess) != 3)
	{
		cout << "Invalid Guess! Try again!" << endl;
		cout << "Please enter three digit lottery number: ";
		cin >> guess;
	}

	return guess;
}

//Calculate winnings
int calcWinnings(int guess)
{
	int dig1, dig2, dig3;
	int lotNum[3];
	int lotNumComplete;
	int prize;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		lotNum[i] = 1 + rand() % (9 - 1 + 1);
	}

	cout << "The winning numbers are......" << endl << endl;
	cout << " " << lotNum[0] << " " << lotNum[1] << " " << lotNum[2] << endl << endl;
	lotNumComplete = (lotNum[0] * 100) + (lotNum[1] * 10) + (lotNum[2]);

	if (guess == lotNumComplete)
	{
		prize = 10000;
		return prize;
	}

	dig1 = guess / 100;
	dig2 = (guess % 100) / 10;
	dig3 = ((guess % 100) % 10);

	if (((lotNum[0] == dig1) || (lotNum[0] == dig2) || (lotNum[0] == dig3)) && ((lotNum[1] == dig1) || (lotNum[1] == dig2) || (lotNum[1] == dig3)) && ((lotNum[2] == dig1) || (lotNum[2] == dig2) || (lotNum[2] == dig3)))
	{
		prize = 3000;
	}
	else if ((lotNum[0] == dig1) || (lotNum[1] == dig2) || (lotNum[2] == dig3))
	{
		prize = 1000;
	}
	else if (((lotNum[0] == dig1) || (lotNum[0] == dig2) || (lotNum[0] == dig3)) || ((lotNum[1] == dig1) || (lotNum[1] == dig2) || (lotNum[1] == dig3)) || ((lotNum[2] == dig1) || (lotNum[2] == dig2) || (lotNum[2] == dig3)))
	{
		prize = 100;
	}
	else
	{
		prize = 0;
	}

	return prize;
}

void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}