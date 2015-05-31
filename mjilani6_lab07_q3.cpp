#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void myFunction(double *ptr); // double the value of real number
void myHeader(string name, int lab, string date, int question); // print Header

int main()
{
	string uInput;
	int decimalCounter = 0;
	double rNum;

	myHeader("Ali Jilani", 4, "March 2nd 2015", 3); // print header

	cout << "Enter a real number: ";
	getline(cin, uInput);

	for (int i = 0; i < uInput.size(); i++) //for loop to check every character
	{
		if (!((int)uInput[0] == 45 || (int)uInput[i] >= 48 && (int)uInput[i] <= 57) || (int)uInput[1] == 45) //Use Acsii code to verify every character
		{
			if ((int)uInput[i] == 46) // check for decimals
			{
				decimalCounter++;

				if (decimalCounter > 1)// check for too many decimals
				{
					decimalCounter = 0;
					cout << "Invalid entry! try again: ";
					getline(cin, uInput);
					i = -1;
				}
			}
			else
			{
				cout << "Invalid entry! try again: ";
				getline(cin, uInput);
				i = -1;
			}
		}
		else if ((int)uInput[0] == 45 && !((int)uInput[i] >= 48 && (int)uInput[i] <= 57)) //check strings that start with a negative sign
		{
			cout << "Invalid entry! try again: ";
			getline(cin, uInput);
			i = -1;
		}
	}
	rNum = atof(uInput.c_str()); //after the input is validated put it into the double variable
	cout << endl;
	cout << rNum << " is a valid entry! Let's go...." << endl << endl;
	
	double **PtrA;
	double *PtrB;

	PtrB = &rNum; //points at the verified variable
	PtrA = &PtrB;//points at the pointer

	//Print all relevant information
	cout << "Doubling the entered value..." << endl << endl;
	myFunction(PtrB);
	cout << "*PtrB =      " << *PtrB << endl;
	cout << "**PtrA =      " << **PtrA << endl;
	cout << endl;
	cout << "Address		Variable Name	Value" << endl;
	cout << &PtrB << "	PtrB		" << PtrB << endl;
	cout << &PtrA << "	PtrA		" << PtrA << endl;
	cout << &rNum << "	x		" << rNum << endl;
}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

void myFunction(double *ptr)
{
	*ptr = *ptr * 2; //multiply the value the pointer is pointing at by 2
}