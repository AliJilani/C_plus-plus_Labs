#include <iostream>

using namespace std;

int main()
{
	int score = 0, score2 = 0;
	char answer;
	int attempt = 0;

	char q1 = 'B'; //Answers to the questions from 1 to 6
	char q2('D'), q3('B'), q4('A'), q5('B'), q6('B');
	bool repeat = true;
	char tryAgain;

	while (repeat)
	{
		attempt++;
		cout << "Attempt " << attempt << ":" << endl;
		//Ask question and get response from user
		cout << "Multiple Choice: Which of the following is not an operation system? \n A. Windows 8 \n B. iPhone \n C. Linux \n D. Android \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q1 == toupper(answer)) //change user response to upper case in order to compare with the question's answer
		{
			score++; // If the user input the correct answer increase 'score' by 1
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q1 << endl << endl; //If the user inputs the wrong answer display the correct answer

		cout << "Multiple Choice: What year was WESTERN founded? \n A. 1950 \n B. 1905 \n C. 1867 \n D. 1878 \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q2 == toupper(answer))
		{
			score++;
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q2 << endl << endl;


		cout << "What is the last name of Western's current president? \n A. Brock \n B. Chakma \n C. Truman \n D. Plank \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q3 == toupper(answer))
		{
			score++;
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q3 << endl << endl;

		cout << "How many bits does a char type variable get in the memory? \n A. 8 \n B. 16 \n C. 32 \n D. 64 \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q4 == toupper(answer))
		{
			score++;
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q4 << endl << endl;

		cout << "What is the only even prime number? \n A. 8 \n B. 2 \n C. 4 \n D. 6 \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q5 == toupper(answer))
		{
			score++;
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q5 << endl << endl;

		cout << "What is the solutions of x^3 -64 = 0 ? \n A. 8 \n B. 4 \n C. 5 \n D. 3 \n" << endl;
		cout << "Response: ";
		cin >> answer;

		if (q6 == toupper(answer))
		{
			score++;
			cout << "Correct!" << endl << endl;
		}

		else
			cout << "Sorry, the correct response was: " << q6 << endl << endl;

		//Select the correct statement based on what the user's score was
		if (score >= 6)
		{
			cout << "Excellent! You answered " << score << " questions correctly." << endl;
		}

		else if (score >= 4 && score < 6)
		{
			cout << "Good! You answered " << score << " questions correctly." << endl;
		}

		else if (score >= 2 && score < 4)
		{
			cout << "Not bad! You answered " << score << " questions correctly." << endl;
		}

		else
			cout << "Nice try but better luck next time!" << score << " questions correctly." << endl;
		if (attempt > 1)
		{
			cout << endl <<"Number of correct answers in last attempt: " << score2 << endl;
		}
		score2 = score;
		repeat = false;
		score = 0;
		
		cout << "Would you like to try again ? (y / Y to continue)  ";
		cin >> tryAgain;
		
		
		if (tryAgain == 'y' || tryAgain == 'Y')
		{
			repeat = true;
		}

		cout << endl;
	}

	cout << "Good bye!" << endl;
}