/*
Mohammed Ali Jilani
250791966
Feb 9 2015
*/

#include <iostream>
#include <iomanip> //imported for the setPrecision function allowing a specific number of numbers to be shown
#include <cmath> // imported for the sqrt function

using namespace std;

int main()
{
	double a, b, c, xPos, xNeg, det, real, imagine, x;

	cout << "This is a quadratic equation solver of the form ax^2 + bx + c." << endl;

	cout << "Input value for a: ";
	cin >> a;
	cout << "Input value for b: ";
	cin >> b;
	cout << "Input value for c: ";
	cin >> c;

	//Break the total code into 2 major sections 1. if a == 0 or not
	if (a == 0)
	{
		if (b != 0) // equation become bx + c = 0 ie. single root
		{
			x = (-1 * c) / b;
			cout << "The single root solution is " << setprecision(4) << fixed << x << endl;
		}

		else if (b == 0 && c == 0)
		{
			cout << "The solution is trivial." << endl;
		}

		else
			cout << "No solution exists" << endl;

	}

	else
	{
		// find the determinant as this helps figure out whether the solution is 2 real roots, 1 real root or imaginary
		det = (b*b) - (4 * a*c);

		if (det > 0) //2 real roots
		{
			xPos = ((-1 * b) + sqrt(det)) / (2 * a);
			xNeg = ((-1 * b) - sqrt(det)) / (2 * a);

			cout << " The solution has real roots: " << setprecision(4) << fixed << xPos << " and " << xNeg << endl;
		}

		else if (det == 0)//1 real root
		{
			xPos = ((-1 * b) + sqrt(det)) / (2 * a);
			cout << " The solution has a real root: " << setprecision(4) << fixed << xPos << endl;
		}

		else if (det < 0) // imaginary
		{
			real = (-1 * b) / (2 * a);
			imagine = sqrt(-det) / (2 * a);
			cout << "The solution has complex roots: " << setprecision(4) << fixed << real << " + " << imagine << "i and " << real << " - " << imagine << "i" << endl;

		}

	}
}