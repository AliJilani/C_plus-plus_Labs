#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

void myHeader(string name, int lab, string date, int question);
void printMenu();
void matrixClear(double C[3][3]);
void matrixInput(double A[3][3]);
void matrixAdd(double A[3][3], double B[3][3], double C[3][3]);
void matrixSubtract(double A[3][3], double B[3][3], double C[3][3]);
void matrixMultiply(double A[3][3], double B[3][3], double C[3][3]);
void matrixMove(double A[3][3], double C[3][3]);
void printMatrix(double A[3][3], double B[3][3], double C[3][3]);

int main()
{
	myHeader("Ali Jilani", 7, "March 2nd 2015", 2);

	//Initialize all the arrays 
	double a[3][3];
	double b[3][3];
	double r[3][3];
	int uInput;
	char mSelect;

	srand((unsigned int)time(NULL));

	//Fill matrix A
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = rand() % 10;
		}
	}

	//Fill matrix B
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = rand() % 10;
		}
	}

	//Fill the result matrix
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r[i][j] = rand() % 10;
		}
	}

	cout << endl << "<<<<<<<<<<<<<<< Matrix Calculator >>>>>>>>>>>>>>>" << endl;

	//print the A matrix
	cout << "A = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << a[i][j];
		}
		cout << endl;
	}

	//print the B matrix
	cout << "B = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << b[i][j];
		}
		cout << endl;
	}

	//print the Result matrix
	cout << "Result = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << r[i][j];
		}
		cout << endl;
	}

	do
	{
		//Activate Menu
		cout << endl;
		printMenu();
		cout << "Please make a valid selection: ";
		cin >> uInput;
		cout << endl;

		switch (uInput) //Preform actions based on user input
		{
			case 1: // Clear Matrix Function
				cout << "You have chosen to clear a matrix!" << endl;
				cout << "Which Matrix would you like to clear (A or B)? ";
				cin >> mSelect;
				mSelect = toupper(mSelect);
				if (mSelect == 'A')
				{
					matrixClear(a);
				}
				else if (mSelect == 'B')
				{
					matrixClear(b);
				}
				break;

			case 2: //Input Matrix Function
				cout << "You have chosen to input a matrix" << endl;
				cout << "Which Matrix would you like to change (A or B)? ";
				cin >> mSelect;
				mSelect = toupper(mSelect);
				if (mSelect == 'A')
				{
					matrixInput(a);
				}
				else if (mSelect == 'B')
				{
					matrixInput(b);
				}
				break;

			case 3: // Adding matrix function
				cout << "You have chosen to Add A and B" << endl;
				matrixAdd(a, b, r);
				break;

			case 4: //Subtracting matrix function
				cout << "You have chosen to Subtract A and B" << endl;
				matrixSubtract(a, b, r);
				break;

			case 5: // Multiplying matix function
				cout << "You have chosen to Multiply A and B" << endl;
				matrixMultiply(a, b, r);
				break;

			case 6: // Moving Matrices
				cout << "You have chosen to move Result into A or B" << endl;
				cout << "Which matrix would you like to move (A or B)? ";
				cin >> mSelect;
				mSelect = toupper(mSelect);
				if (mSelect == 'A')
				{
					matrixMove(a, r);
				}
				else if (mSelect == 'B')
				{
					matrixMove(b, r);
				}
				break;

			case 7: // Print the Matrices
				cout << "You have chosen to print the matrices" << endl;
				cout << endl;
				printMatrix(a, b, r);
				break;

			case 8: // Terminate program
				cout << "Goodbye" << endl;
				break;

			default:
				break;
		}

		// If user did not terminate the program output the newly modified Arrays
		if (uInput == 1 || uInput == 2 || uInput == 3 || uInput == 4 || uInput == 5 || uInput == 6 || uInput == 7)
		{
			//print the A matrix
			cout << "A = " << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << "	" << a[i][j];
				}
				cout << endl;
			}

			//print the B matrix
			cout << "B = " << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << "	" << b[i][j];
				}
				cout << endl;
			}

			//print the Result matrix
			cout << "Result = " << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << "	" << r[i][j];
				}
				cout << endl;
			}
		}
	} while (uInput == 1 || uInput == 2 || uInput == 3 || uInput == 4 || uInput == 5 || uInput == 6 || uInput == 7); // continue to loop as long as the user has not chosen to terminate the program

}

//Header function
void myHeader(string name, int lab, string date, int question)
{
	cout << "************************************" << endl;
	cout << "Name : " << name << endl;
	cout << "Lab #" << lab << ", " << date << ", Question #" << question << endl;
	cout << "************************************" << endl << endl;
}

//function to print menu
void printMenu()
{
	int uInput;
	cout << "1. Clear Matrix A or B" << endl;
	cout << "2. Input Matrix A or B" << endl;
	cout << "3. Add ( Result = A + B )" << endl;
	cout << "4. Subtract ( Result = A - B )" << endl;
	cout << "5. Multiply (Result = A * B)" << endl;
	cout << "6. Move matrix Result into A or B" << endl;
	cout << "7. Print" << endl;
	cout << "8. Exit" << endl;
}

//funtion to clear a matrix
void matrixClear(double C[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
		}
	}

}

//fuction to input a matrix
void matrixInput(double A[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Please enter element [" << i << "] [" << j << "] : ";
			cin >> A[i][j];
		}
	}
}

//function for matrix addition
void matrixAdd(double A[3][3], double B[3][3], double C[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

}

//fuction for matrix subtraction
void matrixSubtract(double A[3][3], double B[3][3], double C[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}

}

//fucntion for matrix multiplication
void matrixMultiply(double A[3][3], double B[3][3], double C[3][3])
{
	//Clear the Resultant Array
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 0;
		}
	}

	// R = A*B
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

}

//matrix transfer
void matrixMove(double A[3][3], double B[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[i][j] = B[i][j];
		}
	}

}

//prints matrix
void printMatrix(double A[3][3], double B[3][3], double C[3][3])
{
	//print matrix A
	cout << "A = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << A[i][j];
		}
		cout << endl;
	}

	//print matrix B
	cout << "B = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << B[i][j];
		}
		cout << endl;
	}

	//print matrix R
	cout << "R = " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "	" << C[i][j];
		}
		cout << endl;
	}
}