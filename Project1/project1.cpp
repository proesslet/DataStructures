// Data Structures Spring 2023
// CS 2413
// Preston Roesslet

#include <iostream>
#include <time.h> // for experiments

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Queries
// Linear Search Function
// Returns the index of the value in the array
int linearSearch(int *array, int value, int low, int arraySize)
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

// Binary Search Function
// Returns the index of the value in the array using recursion
// Learned this algorithm in my Java 2 class and modified it to work here
// using slightly different parameters
int binarySearch(int *array, int value, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	else
	{
		int mid = (low + high) / 2;
		if (value == array[mid])
		{
			return mid;
		}
		else if (value < array[mid])
		{
			return binarySearch(array, value, low, mid - 1);
		}
		else
		{
			return binarySearch(array, value, mid + 1, high);
		}
	}
}

// Find Query
// Takes in an array of values and searches for each one in the corresponding array using
// whichever search function is passed in as a parameter. It then uses cout to print where each
// value was found or not found.
void find(int *values, int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int, int))
{
	int index;
	for (int i = 0; i < numValues; i++)
	{
		index = search(array, values[i], 0, arraySize);
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

// Sum Pairs Query
// Takes in a target value and searches for a pair of values in the array that add up to the target.
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
// Remove Query
// Takes in an array of values and first finds the index of that value in the corresponding array using
// whichever search function is passed in as a parameter. It then removes the value from the array by
// shifting all the values after it down one index. It returns the new size of the array.
int remove(int values[], int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int, int))
{

	// find the index of the values in the array
	int index;
	int numRemoved = 0;
	for (int i = 0; i < numValues; i++)
	{
		index = search(array, values[i], 0, arraySize);
		if (index == -1)
		{
			cout << "Element " << values[i] << " not found in " << arrayName << endl;
		}
		else
		{
			cout << "Removing " << values[i] << " at " << index << " in " << arrayName << endl;
			// set the value to -1
			array[index] = -1;
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

// Insert Query
// Takes in an array of values and inserts them into the corresponding array. It returns the new size of the array.
// If the array is A (unsorted), it inserts the values at the end of the array. If the array is B (sorted), it inserts
// the values in the correct sorted position.
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
	int sizeOfA = 0;   // size of array A, initialized to 0
	int sizeOfB = 0;   // size of array B, initialized to 0

	cin >> maxValues; // read the maximum number of values from the redirected input file
	currentValues = maxValues;

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

	// create a dynamic array B of size maxValues and copy the values from array A to array B
	// Based on the bubble sort algorithm on the online resource: https://www.geeksforgeeks.org/bubble-sort/
	int *B = new int[maxValues];
	for (int i = 0; i < maxValues; i++)
	{
		B[i] = A[i];
		sizeOfB += 1;
	}
	// sort the array B
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

	// read the commands/options till the end of the file
	while (true)
	{

		// check if a valid command was read in, if not, end the loop
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
			// Call the find function on the arrays A and B
			find(tempValues, numCommands, B, sizeOfB, "B", binarySearch);
			find(tempValues, numCommands, A, sizeOfA, "A", linearSearch);

			break;
		case 'A':
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
			// Call the remove function on the arrays A and B
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
			cout << "Insert:" << endl;
			// Call the insert function on the arrays A and B
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