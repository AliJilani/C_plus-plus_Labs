#include <iostream>
#include <string>
using namespace std;

//Function prototype
void myHeader(string name, int lab, string date, int question);

int main()
{
	myHeader("Ali Jilani", 4, "March 2nd 2015", 2);
}

void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl;
}
