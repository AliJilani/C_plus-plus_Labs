#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void myHeader(string name, int lab, string date, int question); // print Header
double getbasePay(double pay, double hours_worked, double non_ot_hours);
double getovertimePay(double hours_worked, double non_ot, double pay, double mult);

int main()
{
	double pay, hoursWorked, regHours, otMultiplier, basepay, overTimePay, totalPay;
	bool repeat = false;
	char again;

	myHeader("Ali Jilani", 4, "March 2nd 2015", 3);

	do
	{
		cout << "What is the hourly pay of Mr. Horton? ";
		cin >> pay;

		cout << "How many hours did you work? ";
		cin >> hoursWorked;
		cout << "What is maximum number of non-overtime hours? ";
		cin >> regHours;
		cout << "What is the multiplier for overtime hours? ";
		cin >> otMultiplier;

		basepay = getbasePay(pay, hoursWorked, regHours);
		overTimePay = getovertimePay(hoursWorked, regHours, pay, otMultiplier);
		totalPay = basepay + overTimePay;

		cout << "Base Pay: $" << setprecision(2) << fixed << basepay << endl;
		cout << "Overtime Pay: $" << setprecision(2) << fixed << overTimePay << endl;
		cout << "Totaly Pay: $" << setprecision(2) << fixed << totalPay << endl;

		cout << "Would you like to calculate again? (Y/y): ";
		cin >> again;
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

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

double getbasePay(double pay, double hours_worked, double non_ot_hours)
{
	double basepay;

	if (hours_worked <= non_ot_hours)
	{
		basepay = pay *(hours_worked);
	}
	
	else
	{
		basepay = pay * (non_ot_hours);
	}

	return basepay;
}

double getovertimePay(double hours_worked, double non_ot, double pay, double mult)
{
	double overTimePay;

	if (hours_worked <= non_ot)
	{
		return 0;
	}
	else
	{
		overTimePay = ((hours_worked - non_ot)*pay)*mult;
		return overTimePay;
	}
}