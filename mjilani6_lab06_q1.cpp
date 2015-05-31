#include <iostream>
#include <string>

using namespace std;
void myHeader(string name, int lab, string date, int question); // print Header
void filterStatus();

int main()
{
	char userInput;
	bool repeat = false;
	myHeader("Ali Jilani", 4, "March 2nd 2015", 3);

	do
	{
		cout << "enter Y/y if you want to fill up your bottle ";
		cin >> userInput;
		userInput = toupper(userInput);

		if (userInput == 'Y')
		{
			filterStatus();
			repeat = true;
		}
		
		else
		{
			repeat = false;
		}
	} while (repeat);

}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

void filterStatus()
{
	static int filterCount = 0;
	char userInput;
	filterCount++;

	if (filterCount == 10)
	{
		cout << "You should change the filter in the fountain within the next 5 uses!" << endl << "Would you like to change the water filter? ";
		cin >> userInput;
		 
		userInput = toupper(userInput);
		if (userInput == 'Y')
		{
			filterCount = 0;
		}
	}

	if (filterCount == 15)
	{
		cout << "The water fountain should no longer be used! Please change the filter." << endl << "To use the fountain again you must change the filter first!" << endl;
		cout << "Would you like to change the water filter? ";
		cin >> userInput;
		userInput = toupper(userInput);

		while (userInput != 'Y')
		{
			cout << "You can't proceed without a new filter, would you like to change the filter now? ";
			cin >> userInput;
			userInput = toupper(userInput);
		}

		filterCount = 0;
		cout << "Changing filter ... Water filter has been changed! Fountain ready to be used again!" << endl;
	}
}