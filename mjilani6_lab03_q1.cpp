#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numStudents(1),ApCounter(0),ACounter(0),BpCounter(0),BCounter(0),CCounter(0),FCounter(0),HighScore(0),LowScore(100);
	double avgScore(0);

	cout << "How many students (up to a max of 100)? ";
	cin >> numStudents;

	while (numStudents <= 0 || numStudents > 100)
	{
		cout << "Invalid Number! enter a positive number less the 100: ";
		cin >> numStudents;
	}

	cout << endl;

	int student[100];

	cout << "Enter score for " << numStudents << " students:" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student " << i + 1 << " score: ";
		cin >> student[i];
	}

	cout << endl;

	//Collect number of each grade
	for (int i = 0; i < numStudents; i++)
	{
		if (student[i] >= 95)
		{
			ApCounter++;
		}
		
		else if (student[i] >= 90)
		{
			ACounter++;
		}

		else if (student[i] >= 85)
		{
			BpCounter++;
		}

		else if (student[i] >= 80)
		{
			BCounter++;
		}

		else if (student[i] >= 70)
		{
			CCounter++;
		}

		else
		{
			FCounter++;
		}
	}

	for (int i = 0; i < numStudents; i++)
	{
		if (student[i] > HighScore)
		{
			HighScore = student[i];
		}

		if (student[i] < LowScore)
		{
			LowScore = student[i];
		}

		avgScore = avgScore + student[i];
	}

	avgScore = avgScore / (double)numStudents;

	cout << "The class result follows:" << endl << "-----------------------------" << endl;
	cout << "A+: " << ApCounter << setprecision(1) << fixed << " (" << ((double)ApCounter/numStudents * 100) << "% of the students recieved this score)" <<endl;
	cout << "A: " << ACounter << setprecision(1) << fixed << " (" << ((double)ACounter / numStudents * 100) << "% of the students recieved this score)" << endl;
	cout << "B+: " << BpCounter << setprecision(1) << fixed << " (" << ((double)BpCounter / numStudents * 100) << "% of the students recieved this score)" << endl;
	cout << "B: " << BCounter << setprecision(1) << fixed << " (" << ((double)BCounter / numStudents * 100) << "% of the students recieved this score)" << endl;
	cout << "C: " << CCounter << setprecision(1) << fixed << " (" << ((double)CCounter / numStudents * 100) << "% of the students recieved this score)" << endl;
	cout << "F: " << FCounter << setprecision(1) << fixed << " (" << ((double)FCounter / numStudents * 100) << "% of the students recieved this score)" << endl;
	cout << "Highest Score: " << HighScore << endl;
	cout << "Lowest Score: " << LowScore << endl;
	cout << "The class average: " << avgScore << endl;

}
