// Spring 2023
// Data Structures
// Project 2

#include <iostream>
#include <string>
#include <fstream> // for reading fileInput

using namespace std;

class tableClass
{
protected:
	string **myTable;	  // 2D string array to store all values (strings and numbers)
	string *DTarray;	  // 1D array to store the data types of each column
	int numRows, numCols; // number of rows and columns

public:
	// Constructors
	tableClass()
	{
		numRows = 0;
		numCols = 0;
		myTable = NULL;
		DTarray = NULL;
	}
	tableClass(int rows, int cols)
	{
		numRows = rows;
		numCols = cols;
		myTable = new string *[numRows];
		// Create the 2D array
		for (int i = 0; i < numRows; i++)
		{
			myTable[i] = new string[numCols];
		}
		// Create the 1D array
		DTarray = new string[numCols];
	}

	// Set DTarray
	void setDTarray(string *DTarray)
	{
		this->DTarray = DTarray;
	}

	// Overload the [] operator to access a row in myTable
	string *operator[](int i)
	{
		return myTable[i];
	}

	// File reading Method
	void readCSV(string filename)
	{
		ifstream fileInput;
		fileInput.open(filename);
		if (fileInput.is_open())
		{
			// Read file row by row. Each row is a string of several values separated by commas. We will use the getline() function to read the row.
			string row;
			int rowNumber = 0;
			int colNumber = 0;

			// Read each row, and store the values in the 2D array
			while (getline(fileInput, row))
			{
				// Read each value in the row, and store it in the 2D array
				string value;
				int pos = 0;
				while ((pos = row.find(",")) != string::npos)
				{
					value = row.substr(0, pos);
					myTable[rowNumber][colNumber] = value;
					row.erase(0, pos + 1);
					colNumber++;
				}
				// Store the last value in the row
				myTable[rowNumber][colNumber] = row;
				rowNumber++;
				colNumber = 0;
			}
		}
		else
		{
			cout << "File not found" << endl;
		}
		fileInput.close();
	}

	// Output Method
	void display()
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				cout << myTable[i][j];
				if (j < numCols - 1)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	// Sort the table
	void sortTable();

	// Search record
	string *searchRecord(string str); // str will be from the first column

	// Search value from table
	void searchValue(string str);

	// Getters
	int getNumberRows();														   // returns the number of rows
	int getNumberCols();														   // returns the number of columns
	tableClass *getColumns(int colLeft, int colRight);							   // returns a tableClass with a set of columns from colLeft to colRight indices
	tableClass *getRows(int rowTop, int rowBottom);								   // returns a tableClass with a set of rows from rowTop to rowBottom indices
	tableClass *getRowsCols(int colLeft, int colRight, int rowTop, int rowBottom); // returns a tableClass with the data between the cols and rows given

	// Find info of a given column
	double findMin(int colNumber); // returns the min of the given column

	// Destructor
	~tableClass();
};

int main()
{
	int numRows, numCols;
	string fileName;
	char option;

	cin >> numRows >> numCols >> fileName;
	cout << "NumRows: " << numRows << endl;
	cout << "NumCols: " << numCols << endl;
	cout << "FileName: " << fileName << endl;

	tableClass *d = new tableClass(numRows, numCols);

	// TODO: read the file input name and call readCSV()
	d->readCSV(fileName);

	// TODO: read the data types and store in DTarray of d
	string *DTarray = new string[numCols];
	for (int i = 0; i < numCols; i++)
	{
		cin >> DTarray[i];
	}
	d->setDTarray(DTarray);

	// TODO: start reading the options till the end of the file
	d->display();
}