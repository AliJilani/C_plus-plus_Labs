#include <iostream>
#include <cmath>

using namespace std;

double fact(double num)
{
	double nfact;

	for (nfact = 1; num > 0; num--)
	{
		nfact = nfact*num;
	}	return nfact;
}

int main()
{
	const double PI = 3.14159;
	double xDeg(0), x(0);
	double cos1, cos2, cosX(1), sin1, sin2, sinX, exp1, exp2, expX(1);
	bool repeat = true;
	char tryAgain;

	cout << "This Program will calculate sin x, cos x and e^x!" << endl;
	
	while (repeat)
	{
		cout << "Please enter a value for x in degrees: ";
		cin >> xDeg;

		while (xDeg < 1)
		{
			cout << "Invalid Entry! enter a positive number: ";
			cin >> xDeg;
		}

		x = (xDeg * (PI / 180.0));

		sinX = x;

		for (int i = 1; i < 20; i++)
		{
			cos1 = pow((-1), i) * pow(x, (2 * i));
			cos2 = fact((2 * i));
			cosX = cosX + cos1 / cos2;

			sin1 = pow((-1), i) * pow(x, ((2 * i) + 1));
			sin2 = fact(((2 * i) + 1));
			sinX = sinX + sin1 / sin2;

			exp1 = pow(xDeg, i);
			exp2 = fact(i);
			expX = expX + (exp1 / exp2);
		}

		cout << endl << "cos(x) = " << cosX << endl << "sin(x) = " << sinX << endl << "exp(x) = " << expX << endl;

		repeat = false;

		cout << "Would you like to try again ? (y / Y to continue)  ";
		cin >> tryAgain;


		if (tryAgain == 'y' || tryAgain == 'Y')
		{
			repeat = true;
			cosX = 1;
			expX = 1;
		}
	}

	cout << endl << "Good bye!" << endl;

}