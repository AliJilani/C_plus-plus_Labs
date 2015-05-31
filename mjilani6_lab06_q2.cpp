#include <iostream>

using namespace std;

double avgArray(int list[], int arraySize);
void highArray(int list[], int arraySize);
void lowArray(int list[], int arraySize);

int main()
{
	int A[10];
	double avg;

	cout << "Please enter ten integers to be entered into the array A:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter A[" << i << "] : ";
		cin >> A[i];
	}

	cout << "Contents of A = [";
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << "]" << endl;

	lowArray(A, 10);
	cout << "Sorted contents of A in ascending order = [";
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << "]" << endl;

	highArray(A, 10);
	cout << "Sorted contents of A in descending order = [";
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << "]" << endl << endl;
	
	avg = avgArray(A, 10);
	cout << "The average of the elements in array" << endl << "A is " << avg << endl;

}

double avgArray(int list[], int arraySize)
{
	double avg = 0;

	for (int i = 0; i < arraySize; i++)
	{
		avg += list[i];
	}

	avg = avg / arraySize;

	return avg;
}
void highArray(int list[], int arraySize)
{
	int temp = 0;
	for (int j = 0; j < arraySize; j++)
	{
		for (int i = 0; i < arraySize - 1; i++)
		{
			if (list[i] < list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				temp = 0;
			}
		}
	}
}

void lowArray(int list[], int arraySize)
{
	int temp = 0;
	for (int j = 0; j < arraySize; j++)
	{
		for (int i = 0; i < arraySize - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				temp = 0;
			}
		}
	}
}
