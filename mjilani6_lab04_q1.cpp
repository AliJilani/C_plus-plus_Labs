#include <iostream>

using namespace std;

//Function Prototypes
double fact(double num);
double myPow(double base, double exp);
double sinRad(double xDeg);

int main()
{
	const double PI = 3.14159;
	bool repeat = true;
	char menuInput;
	double tempNumber,tempNumber2;
	//double sin1, sin2, sinX, x;

	while (repeat) //While loop to repeat the menu
	{
		cout << "Conversion Menu" << endl << "A. Celsius to Fahrenheit" << endl << "B. Fahrenheit to Celsius" << endl
			<< "C. Inches to Centimeters" << endl << "D. Centimeters to Inches" << endl << "E. Meters to Feet" << endl
			<< "F. Feet to Meters" << endl << "G. Km/H to M/S" << endl << "H. M/S to Km/H" << endl << "I. Sine" << endl
			<< "J. Power" << endl << "K. Factorial" << endl << "L. Exit" << endl;
		
		cout << "Enter in menu choice(A - L) : ";
		cin >> menuInput;
		menuInput = toupper(menuInput);

		//Validate input
		while (menuInput != 'A' && menuInput != 'B' && menuInput != 'C' && menuInput != 'D' && menuInput != 'E' && menuInput != 'F' && menuInput != 'G' && menuInput != 'H' && menuInput != 'I' && menuInput != 'J' && menuInput != 'K' && menuInput != 'L')
		{
			cout << "Invalid menu choice! Enter in menu (A - L) : ";
			cin >> menuInput;
			menuInput = toupper(menuInput);
		}

		//Menu options
		switch (menuInput)
		{
			case 'A':
					cout << "You have chosen to convert Celsius to Fahrenheit! Please enter in a value for Celcius : ";
					cin >> tempNumber;
					cout << tempNumber << " Celcius converts to " << ((9.0 / 5.0) * tempNumber) + 32 << " Farenheit" << endl << endl;
					break;

			case 'B':
					cout << "You have chosen to convert Fahrenheit to Celsius! Please enter in a value for Fahrenheit : ";
					cin >> tempNumber;
					cout << tempNumber << " Fahrenheit converts to " << (5.0 / 9.0) * (tempNumber - 32) << " Celsius" << endl << endl;
					break;

			case 'C':
					cout << "You have chosen to convert Inches to Centimeters! Please enter in a value for Inches : ";
					cin >> tempNumber;
					cout << tempNumber << " Inches converts to " << 2.54*tempNumber << " Centimeters" << endl << endl;
					break;

			case 'D':
					cout << "You have chosen to convert Centimeters to Inches! Please enter in a value for Centimeters : ";
					cin >> tempNumber;
					cout << tempNumber << " Centimeters converts to " << 0.39*tempNumber << " Inches" << endl << endl;
					break;

			case 'E':
					cout << "You have chosen to convert Meters to Feet! Please enter in a value for Meters : ";
					cin >> tempNumber;
					cout << tempNumber << " Meters converts to " << 3.28*tempNumber << " Feet" << endl << endl;
					break;

			case 'F':
					cout << "You have chosen to convert Feet to Meters! Please enter in a value for Feet : ";
					cin >> tempNumber;
					cout << tempNumber << " Feet converts to " << 0.3*tempNumber << " Meters" << endl << endl;
					break;

			case 'G':
					cout << "You have chosen to convert Km/h to m/s! Please enter in a value for Km/h : ";
					cin >> tempNumber;
					cout << tempNumber << " Km/h converts to " << 0.277*tempNumber << " m/s" << endl << endl;
					break;

			case 'H':
					cout << "You have chosen to convert m/s to Km/h! Please enter in a value for m/s : ";
					cin >> tempNumber;
					cout << tempNumber << " m/s converts to " << 3.6*tempNumber << " Km/h" << endl << endl;
					break;

			case 'I':
					cout << "You have chosen to calculate Sin x! Please enter in a value for x in degrees:";
					cin >> tempNumber;
					cout << "The value of Sin " << tempNumber << " is ";
					tempNumber = sinRad(tempNumber); //using the custom sin function
					cout << tempNumber << endl << endl;
					break;

			case 'J':
					cout << "You have chosen to calculate Power! Please enter in a value for the base: ";
					cin >> tempNumber;
					cout << " and exponent ";
					cin >> tempNumber2;
					cout <<"The value of " << tempNumber << "^" << tempNumber2 << " = " << myPow(tempNumber, tempNumber2) << endl <<endl; // using the custom power function
					break;
			
			case 'K':
				cout << "You have chosen to calculate factorial! Please enter in a value for the base: ";
				cin >> tempNumber;
				cout << "The value of " << tempNumber << "!" << " = " << fact(tempNumber) << endl << endl; //using the custom factorial function
				break;

			case 'L':
				cout << "Good Bye" << endl << endl;
				repeat = false; //ending the loop
				break;
		}
	}

}

//The Factorial Function
double fact(double num)
{
	double nfact;

	for (nfact = 1; num > 0; num--)
	{
		nfact = nfact*num;
	}	return nfact;
}

//The sin function which uses a nested function that is also custom
double sinRad(double xDeg)
{
	const double PI = 3.14159;
	double sin1, sin2, sinX, x;

	x = (xDeg * (PI / 180.0));
	sinX = x;

	for (int i = 1; i < 20; i++)
	{
		sin1 = myPow((-1), i) * myPow(x, ((2 * i) + 1));
		sin2 = fact(((2 * i) + 1));
		sinX = sinX + sin1 / sin2;
	}

	return sinX;
}

//Power function that is also used as a nested function inside sinRad
double myPow(double base, double exp)
{
	double result = 1;
	for (int i = 0; i < exp; i++)
	{
		result = result * base;
	}

	return result;
}
