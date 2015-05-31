#include <iostream>
#include <string>

using namespace std;

void myHeader(string name, int lab, string date, int question); // print Header
void analyzeTheSentence(string x);

int main()
{
	bool repeat = false;
	string userInput;
	char answer;
	myHeader("Ali Jilani", 4, "March 2nd 2015", 3);

	//print ASCII letters from value 32 -> 126
	for (int i = 32; i < 127; i++)
	{
		cout << i << " = " << (char)i << " ";
	}

	do
	{
		cout << endl << endl << "Enter a sentence : ";
		getline(cin, userInput);
		analyzeTheSentence(userInput);

		//repeat instructions
		cout << "Continue? ";
		cin >> answer;
		cin.ignore();
		answer = toupper(answer);
		if (answer == 'Y')
		{
			repeat = true;
		}
		else
		{
			repeat = false;
		}
		// end of repeat instruction
	} while (repeat); // repeat if the user entered 'y'
}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

// Function to analyze sentence
void analyzeTheSentence(string x)
{
	int upperCase = 0;
	int lowerCase = 0;
	int dDig = 0;
	int spaces = 0;
	int oChars = 0;

	for (int i = 0; i < x.size(); i++)
	{
		//Check if letter 'i' is uppercase
		if ((int)x[i] > 64 && (int)x[i] < 91)
		{
			upperCase = upperCase + 1;
		}

		//Check if letter 'i' is lowercase
		else if ((int)x[i] > 96 && (int)x[i] < 123)
		{
			lowerCase = lowerCase + 1;
		}

		//Check if letter 'i' is decimal digit
		else if ((int)x[i] > 47 && (int)x[i] < 58)
		{
			dDig = dDig + 1;
		}

		//Check if letter 'i' is a space
		else if ((int)x[i] == 32)
		{
			spaces = spaces + 1;
		}

		//all other characters
		else
		{
			oChars = oChars + 1;
		}
	}

	cout << "Uppercase letters: " << upperCase << endl;
	cout << "Lowercase letters: " << lowerCase << endl;
	cout << "Decimal digits: " << dDig << endl;
	cout << "Spaces: " << spaces << endl;
	cout << "Other Characters: " << oChars << endl;
}