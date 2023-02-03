// Data Structures Spring 2023
// CS 2413
// Preston Roesslet

#include <iostream>
#include <time.h> // for experiments

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Queries
int linearSearch(int *array, int arraySize, int value)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}
	return -1;
}
int binarySearch(int *array, int arraySize, int value)
{
	int low = 0;
	int high = arraySize - 1;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (array[mid] < value)
		{
			low = mid + 1;
		}
		else if (array[mid] == value)
		{
			return mid;
		}
		else
		{
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	return -1;
}
void find(int *values, int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int))
{
	int index;
	for (int i = 0; i < numValues; i++)
	{
		index = search(array, arraySize, values[i]);
		if (index == -1)
		{
			cout << "Element " << values[i] << " not found in " << arrayName << endl;
		}
		else
		{
			cout << "Element " << values[i] << " found at " << index << " in " << arrayName << endl;
		}
	}
	// print empty line
	cout << endl;
}

void sumPairs(int target, int *array, int arraySize)
{
	cout << target << endl;
	// find 2 numbers in array that add up to target
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (array[i] + array[j] == target)
			{
				cout << " = " << array[i] << " + " << array[j] << endl;
				return;
			}
		}
	}
}

// Operations
int remove(int values[], int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int))
{

	// find the index of the values in the array
	int index;
	int numRemoved = 0;
	for (int i = 0; i < numValues; i++)
	{
		index = search(array, arraySize, values[i]);
		if (index == -1)
		{
			cout << "Element " << values[i] << " not found in " << arrayName << endl;
		}
		else
		{
			cout << "Removing " << values[i] << " at " << index << " in " << arrayName << endl;
			// remove the value from the array
			for (int j = index; j < arraySize - 1; j++)
			{
				array[j] = array[j + 1];
				numRemoved += 1;
			}
			arraySize -= 1;
		}
	}

	cout << endl;
	return arraySize;
}

int insert(int values[], int numValues, int *array, int arraySize, string arrayName)
{
	// find the index of the values in the array
	int index;
	if (arrayName == "A")
	{

		for (int i = 0; i < numValues; i++)
		{
			index = arraySize;
			cout << "Inserting " << values[i] << " in " << arrayName << endl;
			// insert the value from the array
			array[index] = values[i];
			arraySize += 1;
		}
	}
	else
	{
		for (int i = 0; i < numValues; i++)
		{
			for (int j = 0; j < arraySize; j++)
			{
				if (values[i] < array[j])
				{
					index = j;
					break;
				}
				else
				{
					index = arraySize;
				}
			}
			cout << "Inserting " << values[i] << " in " << arrayName << endl;
			// insert the value from the array
			for (int j = arraySize; j > index; j--)
			{
				array[j] = array[j - 1];
			}
			array[index] = values[i];
			arraySize += 1;
		}
	}
	cout << endl;
	return arraySize;
}

int main()
{
	int maxValues;	   // max number of values to store / length of the arrays
	int currentValues; // as we add, the number of values in the arrays
	int tempVal;	   // variable used to read the number
	int numCommands;   // variable used to read the number of commands
	char command;	   // variable used to store the command
	int sizeOfA = 0;   // size of array A
	int sizeOfB = 0;   // size of array B

	cin >> maxValues; // read the maximum number of values from the redirected input file

	cout << "Length of the array: " << maxValues << endl;

	// create a dynamic array A of size maxValues
	int *A = new int[maxValues];

	// read in the number from the redirected input
	for (int i = 0; i < maxValues; i++)
	{
		cin >> tempVal;
		A[i] = tempVal;
		sizeOfA += 1;
	}

	// display the values in array A
	cout << "Array A: ";
	for (int i = 0; i < sizeOfA; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	// sort the array A and store it in B - any sorting algorithm can be used
	// Based by bubble sort algorithm on the online resource: https://www.geeksforgeeks.org/bubble-sort/
	int *B = new int[maxValues];
	for (int i = 0; i < maxValues; i++)
	{
		B[i] = A[i];
		sizeOfB += 1;
	}

	int i, j;
	for (i = 0; i < maxValues - 1; i++)
	{
		for (j = 0; j < maxValues - i - 1; j++)
		{
			if (B[j] > B[j + 1])
			{
				int temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}

	// display the values in array B
	cout << "Array B: ";
	for (int i = 0; i < sizeOfB; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	// TODO read the commands/options till the end of the file
	while (true)
	{

		// check if a valid command was read in
		if (!(cin >> command))
		{
			break;
		}
		// read number of values
		cin >> numCommands;
		// create a dynamic array to store the values
		int *tempValues = new int[numCommands];
		// read in the values
		for (int i = 0; i < numCommands; i++)
		{
			cin >> tempVal;
			tempValues[i] = tempVal;
		}
		switch (command)
		{
		case 'F':
			cout << "Find:" << endl;
			find(tempValues, numCommands, B, sizeOfB, "B", binarySearch);
			find(tempValues, numCommands, A, sizeOfA, "A", linearSearch);

			break;
		case 'A':
			// TODO
			cout << "Sum Pairs:" << endl;
			cout << "B:" << endl;
			for (int i = 0; i < numCommands; i++)
			{
				sumPairs(tempValues[i], B, sizeOfB);
			}
			cout << endl;
			cout << "A:" << endl;
			for (int i = 0; i < numCommands; i++)
			{
				sumPairs(tempValues[i], A, sizeOfA);
			}
			cout << endl;
			break;
		case 'R':
			// TODO
			cout << "Remove:" << endl;
			sizeOfB = remove(tempValues, numCommands, B, sizeOfB, "B", binarySearch);
			sizeOfA = remove(tempValues, numCommands, A, sizeOfA, "A", linearSearch);

			// display the values in array A
			cout << "After removal Array A: ";
			for (int i = 0; i < sizeOfA; i++)
			{
				cout << A[i] << " ";
			}
			cout << endl;
			cout << endl;

			// display the values in array B
			cout << "After removal Array B: ";
			for (int i = 0; i < sizeOfB; i++)
			{
				cout << B[i] << " ";
			}
			cout << endl;
			cout << endl;
			break;
		case 'I':
			// TODO
			cout << "Insert:" << endl;
			sizeOfB = insert(tempValues, numCommands, B, sizeOfB, "B");
			sizeOfA = insert(tempValues, numCommands, A, sizeOfA, "A");

			// display the values in array A
			cout << "After insertions Array A: ";
			for (int i = 0; i < sizeOfA; i++)
			{
				cout << A[i] << " ";
			}
			cout << endl;

			// display the values in array B
			cout << "After insertions Array B: ";
			for (int i = 0; i < sizeOfB; i++)
			{
				cout << B[i] << " ";
			}
			cout << endl;

			break;
		default:
			cout << "Invalid command: " << command << endl;
			break;
		}
	}

	// TODO delete all the dynamically created arrays
	delete[] A;
	delete[] B;

	return 0;
}