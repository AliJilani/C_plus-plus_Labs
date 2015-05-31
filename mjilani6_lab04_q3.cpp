#include <iostream>
#include <string>
using namespace std;

//Function prototype
void myHeader(string name, int lab, string date, int question); // print Header
char myChoiceFunction();// user selection
double myPowerFunction(double base, int exp); //power function
double myFactFunction(int number);//Calculate factorial
double mySinFunction(double angle);//Compute Sin function

int main()
{
	const double PI = 3.14159;
	bool repeat = true;
	char userInput;
	double tempNumber;
	string a;
	int k;

	myHeader("Ali Jilani", 4, "March 2nd 2015", 3);

	//Program loop
	while (repeat)
	{
		cout << "Menu:" << endl << "a.Sine" << endl << "b.Power" << endl << "c.Factorial" << endl << "d.Exit" << endl;
		userInput = myChoiceFunction();

		if (userInput == 'A')
		{
			cout << "You have chosen to calculate Sin x! Please enter in a value for x in radians (from -Pi to Pi): ";
			cin >> tempNumber;
			
			while (tempNumber < -PI || tempNumber > PI)
			{
				cout << "Invalid angle! Please enter in a value for x in radians (from -Pi to Pi): ";
				cin >> tempNumber;
			}

			cout << "The value of Sin " << tempNumber << " is ";
			tempNumber = mySinFunction(tempNumber); //using the custom sin function
			cout << tempNumber << endl << endl;
		}

		else if (userInput == 'B')
		{
			cout << "You have chosen to calculate Power! Please enter in a value for the base: ";
			cin >> tempNumber;
			cout << " and exponent (must be an integer + or -): ";
			
			//validate integer for exponent
			cin >> a;
			for (unsigned int i = 0; i<a.size(); i++)
			{
				if (!((int)a[i] == 45 || ((int)a[i] >= 48 && (int)a[i] <= 57)))
				{
					cout << "Invalid entry! try again: ";
					cin >> a;
					i = -1;
				}
			}
			k = atoi(a.c_str());//valid integer
			cout << "The value of " << tempNumber << "^" << k << " = " << myPowerFunction(tempNumber, k) << endl << endl; //using the custom power function
		}
		
		else if (userInput == 'C')
		{
			do //loop for input must be a positive number
			{
				cout << "You have chosen to calculate factorial! Please enter in a value for the base (must be a positive number): ";

				//validate integer
				cin >> a;
				for (unsigned int i = 0; i < a.size(); i++)
				{
					if (!((int)a[i] == 45 || ((int)a[i] >= 48 && (int)a[i] <= 57)))
					{
						cout << "Invalid entry! try again: ";
						cin >> a;
						i = -1;
					}
				}
				k = atoi(a.c_str()); //valid integer
			} while (k < 0);

			if (k == 0) //exception for 0!
			{
				cout << "The value of 0! = 1" << endl << endl; //using the custom factorial function
			}

			else
			{
				cout << "The value of " << k << "!" << " = " << myFactFunction(k) << endl << endl; //using the custom factorial function
			}
		}

		else if (userInput == 'D')
		{
			cout << "Good bye!" << endl;
			repeat = false;
		}
	}
}

char myChoiceFunction()
{
	char menuInput;
	cout << "Enter in menu choice (A - D) : ";
	cin >> menuInput;
	menuInput = toupper(menuInput);

	//Validate input
	while (menuInput != 'A' && menuInput != 'B' && menuInput != 'C' && menuInput != 'D')
	{
		cout << "Invalid menu choice! Enter in menu (A - D) : ";
		cin >> menuInput;
		menuInput = toupper(menuInput);
	}

	return menuInput;
}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

//The Factorial Function
double myFactFunction(int number)
{
	double nfact = 1;

	do
	{
		nfact = nfact*number;
		number--;
	}while (number > 0);	return nfact;
}

//The Power Function
double myPowerFunction(double base, int exp)
{
	int posExp;
	bool negExp = false;
	double result = 1;
	
	if (exp < 0) //checking if expoenent is negative
	{
		posExp = (-1)*exp;
		negExp = true;
	}
	else
	{
		posExp = exp;
	}

	for (int i = 0; i < posExp; i++)
	{
		result = result * base;
	}
	
	if (negExp)
	{
		return (1 / result);
	}

	else
	{
		return result;
	}

}

//The Sin Function
double mySinFunction(double angle)
{
	const double PI = 3.14159;
	double sin1, sin2, sinX;

	sinX = angle;

	for (int i = 1; i < 20; i++)
	{
		sin1 = myPowerFunction((-1), i) * myPowerFunction(angle, ((2 * i) + 1));
		sin2 = myFactFunction(((2 * i) + 1));
		sinX = sinX + sin1 / sin2;
	}

	return sinX;
}