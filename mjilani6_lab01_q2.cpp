/*
Ali Jilani
Lab 01 Question 2
Find the BMI given weight in pounds and height in inches
*/
#include <iostream>
using namespace std;

int main()
{
	double weightPounds, heightInches, bmi, weightKGs, heightMeters; //Declare the variables to be used later on in the code
	
	cout << "This program was designed to calculate Body Mass Index" << endl;
	
	cout << "Please input weight in lbs :";
	cin >> weightPounds; //recieve the weight in pounds from the user and save it in variable weightPounds

	cout << "Please input the height in inches :";
	cin >> heightInches; //recieve the height in inches from the user and save it in variable heightInches
	cout << endl;

	weightKGs = 0.45359237*weightPounds; //Calculation for converting from pounds to kgs
	heightMeters = 0.0254*heightInches; // Calculation for converting from inches to meters

	bmi = weightKGs / (heightMeters*heightMeters); //calculate the Body mass index

	//display result
	cout << "The Body mass index is: " << bmi << endl;

	return 0;
}