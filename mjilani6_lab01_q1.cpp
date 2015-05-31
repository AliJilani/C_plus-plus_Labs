/*
Ali Jilani
Lab01 Question 1
Find the Surface area and volume of a cylinder
*/
#include <iostream>
using namespace std;

int main()
{
	const double PI = 3.1416; //Declare Pi as a constant because it doesn't change
	double radius, height, volume, surfaceArea; //Declaring variables that will be used later on

	cout << "This program was designed to calculate the Surface area and volume of a Cylinder";
	cout << "*Note: the radius and height must be in the same units" << endl;

	cout << "Input the radius of the cylinder: ";
	cin >> radius; //recieve the radius value from the user
	cout << endl;

	cout << "Input the height of the cylinder: ";
	cin >> height; //recieve the height value from the user
	cout << endl;

	surfaceArea = (2 * PI*radius*height) + (2 * PI*(radius*radius)); //calculate the surface area and save it in variable 'surfaceArea'
	volume = PI*(radius*radius)*height; //calculate the volume and save it in the variable called 'volume'

	//display result
	cout << "The surface area of the cylinder is " << surfaceArea << " and the volume is " << volume << endl;

	return 0;
}