// Data Structures Spring 2023
// CS 2413
// Preston Roesslet

#include <iostream>
#include <time.h> // for experiments

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Queries
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
void find(int *values, int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int, int))
{
    clock_t start, end;
    double cpu_time_used;
    int numTimes = 0;
    // create array to store times
    double times[numValues];
    start = clock();
    int index;
    for (int i = 0; i < numValues; i++)
    {
        index = search(array, values[i], 0, arraySize);
        if (index == -1)
        {
            cout << "Element " << values[i] << " not found in " << arrayName << endl;
            end = clock();
            // convert ticks to seconds
            cpu_time_used = double(end - start) / CLOCKS_PER_SEC;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
        }
        else
        {
            cout << "Element " << values[i] << " found at " << index << " in " << arrayName << endl;
            end = clock();
            cpu_time_used = double(end - start) / CLOCKS_PER_SEC;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
        }
    }
    // print empty line
    cout << endl;
    // find average time
    double sum = 0;
    for (int i = 0; i < numTimes; i++)
    {
        sum += times[i];
    }
    double average = sum / numTimes;
    cout << "Average time: " << average << " seconds" << endl;
    cout << endl;
}

void sumPairs(int target, int *array, int arraySize)
{
    clock_t start, end;
    double cpu_time_used;
    int numTimes = 0;
    // create array to store times
    double times[arraySize];
    start = clock();
    cout << target << endl;
    // find 2 numbers in array that add up to target
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (array[i] + array[j] == target)
            {
                cout << " = " << array[i] << " + " << array[j] << endl;
                end = clock();
                cpu_time_used = end - start;
                numTimes++;
                times[i] = cpu_time_used;
                cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
                return;
            }
        }
    }

    cout << endl;
}

// Operations
int remove(int values[], int numValues, int *array, int arraySize, string arrayName, int (*search)(int *, int, int, int))
{
    clock_t start, end;
    double cpu_time_used;
    int numTimes = 0;
    // create array to store times
    double times[numValues];
    start = clock();
    // find the index of the values in the array
    int index;
    int numRemoved = 0;
    for (int i = 0; i < numValues; i++)
    {
        index = search(array, values[i], 0, arraySize);
        if (index == -1)
        {
            cout << "Element " << values[i] << " not found in " << arrayName << endl;
            end = clock();
            cpu_time_used = end - start;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
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
            end = clock();
            cpu_time_used = end - start;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
        }
    }

    cout << endl;
    // find average time
    double sum = 0;
    for (int i = 0; i < numTimes; i++)
    {
        sum += times[i];
    }
    double average = sum / numTimes;
    cout << "Average time: " << average << " seconds" << endl;
    cout << endl;
    return arraySize;
}

int insert(int values[], int numValues, int *array, int arraySize, string arrayName)
{
    clock_t start, end = 0;
    double cpu_time_used;
    int numTimes = 0;
    // create array to store times
    double times[numValues];
    start = clock();
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
            end = clock();
            cpu_time_used = end - start;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
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
            end = clock();
            cpu_time_used = end - start;
            numTimes++;
            times[i] = cpu_time_used;
            cout << "Time taken: " << cpu_time_used << " clock ticks" << endl;
        }
    }
    cout << endl;
    // find average time
    double sum = 0;
    for (int i = 0; i < numTimes; i++)
    {
        cout << sum << " + " << times[i] << endl;
        sum += times[i];
    }
    cout << sum << " / " << numTimes << endl;
    double average = sum / numTimes;
    cout << "Average time: " << average << " seconds" << endl;
    cout << endl;
    return arraySize;
}

int main()
{
    int maxValues;     // max number of values to store / length of the arrays
    int currentValues; // as we add, the number of values in the arrays
    int tempVal;       // variable used to read the number
    int numCommands;   // variable used to read the number of commands
    char command;      // variable used to store the command
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
        // cout << A[i] << " ";
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
        // cout << B[i] << " ";
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
            // cout << "After removal Array A: ";
            // for (int i = 0; i < sizeOfA; i++)
            //{
            //    cout << A[i] << " ";
            //}
            // cout << endl;
            // cout << endl;

            // display the values in array B
            // cout << "After removal Array B: ";
            // for (int i = 0; i < sizeOfB; i++)
            //{
            //    cout << B[i] << " ";
            //}
            // cout << endl;
            cout << endl;
            break;
        case 'I':
            // TODO
            cout << "Insert:" << endl;
            sizeOfB = insert(tempValues, numCommands, B, sizeOfB, "B");
            sizeOfA = insert(tempValues, numCommands, A, sizeOfA, "A");

            // display the values in array A
            // cout << "After insertions Array A: ";
            // for (int i = 0; i < sizeOfA; i++)
            //{
            //    cout << A[i] << " ";
            //}
            // cout << endl;

            // display the values in array B
            // cout << "After insertions Array B: ";
            // for (int i = 0; i < sizeOfB; i++)
            //{
            //    cout << B[i] << " ";
            //}
            // cout << endl;

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