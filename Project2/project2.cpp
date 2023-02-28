// Spring 2023
// Data Structures
// Project 2
// Preston Roesslet

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
	// Default constructor
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

	// Overload the [] operator to access a row in myTable
	string *operator[](int i)
	{
		return myTable[i];
	}

	// Method to trim trailing whitespacte from a string
	// I had some major issues with this whole whitespace thing on my mac, but this seems to work. Spent a lot of time
	// researching this issue and found this stack overflow post that helped me out a lot:
	// https://stackoverflow.com/a/21815483. I hope it's okay that I used stack overflow for this specific issue. I was at my wits end
	// with it.
	inline string &stripWhiteSpace(string &s, const char *t = " \t\n\r\f\v")
	{
		s.erase(s.find_last_not_of(t) + 1);
		return s;
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
			int rowCounter = 0;

			while (getline(fileInput, row))
			{
				// Read each value in the row and remove trailing spaces
				string value;
				int colCounter = 0;
				for (int i = 0; i < row.length(); i++)
				{
					if (row[i] == ',')
					{
						stripWhiteSpace(value);
						myTable[rowCounter][colCounter] = value;
						value = "";
						colCounter++;
					}
					else
					{
						value += row[i];
					}
				}
				// Read the last value in the row
				stripWhiteSpace(value);
				myTable[rowCounter][colCounter] = stripWhiteSpace(value);
				rowCounter++;
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
		// display data types
		for (int i = 0; i < numCols; i++)
		{
			cout << DTarray[i];
			if (i < numCols - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
		// display table
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

	// Sort the table by the first column
	void sortTable()
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i + 1; j < numRows; j++)
			{
				if (myTable[i][0] > myTable[j][0])
				{
					string *temp = myTable[i];
					myTable[i] = myTable[j];
					myTable[j] = temp;
				}
			}
		}
	}

	// Search record
	// str will be from the first column
	string *searchRecord(string str)
	{
		for (int i = 0; i < numRows; i++)
		{
			if (myTable[i][0] == str)
			{
				return myTable[i];
			}
		}
		throw string("Record not found");
	}

	// Search value from table
	string searchValue(string str)
	{
		// Find all locations of the value and return each col and row as a string separated by commas
		string result = "";
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				if ((myTable[i][j].compare(str)) == 0)
				{
					result += "found in (" + to_string(i) + "," + to_string(j) + ") \n";
				}
			}
		}
		if (result != "")
		{
			return result;
		}
		else
		{
			throw string("Value not found");
		}
	}

	// Setters
	// sets the data type of a given column
	void setDataType(int colNumber, string dataType)
	{
		DTarray[colNumber] = dataType;
	}

	// Getters
	// returns the number of rows
	int getNumberRows()
	{
		return numRows;
	}
	// returns the number of columns
	int getNumberCols()
	{
		return numCols;
	}
	// returns a tableClass with a set of columns from colLeft to colRight indices
	tableClass *getColumns(int colLeft, int colRight)
	{
		tableClass *newTable = new tableClass(numRows, colRight - colLeft + 1);
		// Copy the data types
		for (int i = colLeft; i < colRight; i++)
		{
			newTable->setDataType(i - colLeft, DTarray[i]);
		}
		for (int i = 0; i < numRows; i++)
		{
			for (int j = colLeft; j < colRight; j++)
			{
				newTable->myTable[i][j - colLeft] = myTable[i][j];
			}
		}
		return newTable;
	}
	// returns a tableClass with a set of rows from rowTop to rowBottom indices
	tableClass *getRows(int rowTop, int rowBottom)
	{
		tableClass *newTable = new tableClass(rowBottom - rowTop + 1, numCols);
		// Copy the data types
		for (int i = 0; i < numCols; i++)
		{
			newTable->setDataType(i, DTarray[i]);
		}
		for (int i = rowTop; i < rowBottom; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				newTable->myTable[i - rowTop][j] = myTable[i][j];
			}
		}
		return newTable;
	}
	// returns a tableClass with the data between the cols and rows given
	tableClass *getRowsCols(int colLeft, int colRight, int rowTop, int rowBottom)
	{
		tableClass *newTable = new tableClass(rowBottom - rowTop + 1, colRight - colLeft + 1);
		// Copy the data types
		for (int i = colLeft; i < colRight; i++)
		{
			newTable->setDataType(i - colLeft, DTarray[i]);
		}
		for (int i = rowTop; i < rowBottom; i++)
		{
			for (int j = colLeft; j < colRight; j++)
			{
				newTable->myTable[i - rowTop][j - colLeft] = myTable[i][j];
			}
		}
		return newTable;
	}

	// Find info of a given column
	// returns the min of the given column
	double findMin(int colNumber)
	{
		if (colNumber >= numCols)
		{
			throw string("Column number is out of range");
		}
		else if (!(DTarray[colNumber] == "int" || DTarray[colNumber] == "double" || DTarray[colNumber] == "float"))
		{
			throw string("Column is not numeric");
		}
		else
		{

			double min = stod(myTable[1][colNumber]);
			for (int i = 1; i < numRows; i++)
			{
				if (stod(myTable[i][colNumber]) < min)
				{
					min = stod(myTable[i][colNumber]);
				}
			}
			return min;
		}
	}

	// Destructor
	~tableClass()
	{
		for (int i = 0; i < numRows; i++)
		{
			delete[] myTable[i];
		}
		delete[] myTable;
		delete[] DTarray;
	}
};

int main()
{
	int numRows, numCols;
	string fileName; // name of the file to be read in
	char option;
	string query;							  // query to be searched for
	string *record;							  // record that is found
	int minCol;								  // column to find the min of
	int min;								  // min of the column
	int colLeft, colRight, rowTop, rowBottom; // indices for the rows and columns

	// read the number of rows, columns and file name
	cin >> numRows >> numCols >> fileName;
	cout << "NumRows: " << numRows << endl;
	cout << "NumCols: " << numCols << endl;
	cout << "FileName: " << fileName << endl;

	// create a tableClass object
	tableClass *d = new tableClass(numRows, numCols);

	// read the file input name and call readCSV()
	d->readCSV(fileName);
	d->sortTable();

	// read the data types and store in DTarray of d
	for (int i = 0; i < numCols; i++)
	{
		string dataType;
		cin >> dataType;
		d->setDataType(i, dataType);
	}

	//  start reading the options till the end of the file
	while (true)
	{

		if (!(cin >> option))
		{
			// if there is not option left, exit the loop
			break;
		}

		switch (option)
		{
		case 'F':
			// Seach for a record
			cin >> query;
			// Call the search Record function
			try
			{
				record = d->searchRecord(query);
				cout << "Record found: " << endl;
				for (int i = 0; i < numCols; i++)
				{
					cout << record[i];
					if (i < numCols - 1)
					{
						cout << " ";
					}
				}
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}

			cout << endl;

			break;
		case 'V':
			// Search for a value
			cin >> query;
			cout << "Searching for " << query << endl;
			// Call the search Value function
			try
			{
				cout << d->searchValue(query);
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}

			break;
		case 'D':
			// Display method
			d->display();
			break;
		case 'I':
			// Find
			try
			{
				cin >> minCol;
				min = d->findMin(minCol);
				cout << "Min of " << minCol << " is " << min << endl;
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}
			break;
		// Remaining cases are to get a subset of the table
		case 'C':
			cin >> colLeft >> colRight;
			// Call the getColumns function
			try
			{
				tableClass *newTable = d->getColumns(colLeft, colRight);
				newTable->display();
				delete newTable;
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}
			break;
		case 'R':
			cin >> rowTop >> rowBottom;
			// Call the getRows function
			try
			{
				tableClass *newTable = d->getRows(rowTop, rowBottom);
				newTable->display();
				delete newTable;
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}
			break;
		case 'S':
			cin >> colLeft >> colRight >> rowTop >> rowBottom;
			// Call the getRowsCols function
			try
			{
				tableClass *newTable = d->getRowsCols(colLeft, colRight, rowTop, rowBottom);
				newTable->display();
				delete newTable;
			}
			catch (string e)
			{
				cout << e << endl;
				break;
			}
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}

	return 0;
}