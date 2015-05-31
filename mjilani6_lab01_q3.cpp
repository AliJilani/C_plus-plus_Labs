#include <iostream>
#include <cmath> // import cmath due to use of some advanced math functions

using namespace std;

int main()
{
	const double e = 2.71828182846; // establish the constant e
	double x1, x2, x3, y1, y2; // declare the variables to be used later in the code
	
	//input the designated x values from the user
	cout << "Input the value for x1:" << endl;
	cin >> x1;

	cout << "Input the value for x2:" << endl;
	cin >> x2;

	cout << "Input the value for x3:" << endl;
	cin >> x3;

	y1 = pow((pow(e, x1)*sin(2 * x2)), 5.0) + abs((sin(x3) / x1)); // calculate for y1
	y2 = pow(e, tan(x2)) + (log10(e) / log10(3)); // calculate for y2 note: use the propertiesof Logarithms to achieve Log base 3 ^ e 

	//display results
	cout << "y1 = " << y1 << endl;
	cout << "y2 = " << y2 << endl;
	
}