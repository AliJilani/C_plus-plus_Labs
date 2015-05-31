#include <iostream>
#include <string>

using namespace std;
void myHeader(string name, int lab, string date, int question); // print Header
bool isValid(int n);
double statisticalData(int n);

int main()
{
	int n;
	double avg;
	bool initValid = true;
	do
	{
		cout << "Enter an Integer greater than 4: ";
		cin >> n;
		initValid = isValid(n);
	} while (initValid == false);

	avg = statisticalData(n);
	cout << "Average of all the entered numbers: " << avg << endl << "Good bye!" << endl;

}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

//Interger Validation Function
bool isValid(int n)
{
	if (n > 4)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//Data Analysis Function
double statisticalData(int n)
{
	int tempNumber;
	int maxEven(0), maxOdd(0), minEven(0), minOdd(0),evenCounter(0),oddCounter(0);
	double avgEven(0), avgOdd(0), avgAll(0);
	bool eInit = false, oInit = false;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> tempNumber;

		if (tempNumber % 2 == 0)
		{
			evenCounter++;

			if (eInit == false)
			{
				maxEven = tempNumber;
				minEven = tempNumber;
				eInit = true;
			}

			if (tempNumber > maxEven)
			{
				maxEven = tempNumber;
			}

			if (tempNumber < minEven)
			{
				minEven = tempNumber;
			}

			avgEven += tempNumber;
		}

		else
		{
			oddCounter++;

			if (oInit == false)
			{
				maxOdd = tempNumber;
				minOdd = tempNumber;
				oInit = true;
			}

			if (tempNumber > maxOdd)
			{
				maxOdd = tempNumber;
			}

			if (tempNumber < minOdd)
			{
				minOdd = tempNumber;
			}

			avgOdd += tempNumber;
		}

		avgAll += tempNumber;
	}

	avgEven = avgEven / (double)evenCounter;
	avgOdd = avgOdd / (double)oddCounter;
	avgAll = avgAll / (double)n;

	cout << endl;
	if (evenCounter != 0)
	{
		cout << "Highest entered even number: " << maxEven << endl;
		cout << "Lowest entered even number: " << minEven << endl;
	}

	if (oddCounter != 0)
	{
		cout << "Highest entered odd number: " << maxOdd << endl;
		cout << "Lowest entered odd number: " << minOdd << endl;
	}

	if (evenCounter == 0)
	{
		cout << "No even number was entered" << endl;
	}
	else
	{
		cout << "Total even numbers entered: " << evenCounter << endl;
	}

	if (oddCounter == 0)
	{
		cout << "No odd number was entered" << endl;
	}
	else
	{
		cout << "Total odd numbers entered: " << oddCounter << endl;
	}

	if (evenCounter != 0)
	{
		cout << "Average of the even numbers: " << avgEven << endl;
	}

	if (oddCounter != 0)
	{
		cout << "Average of odd numbers: " << avgOdd << endl;
	}

	return avgAll;
}