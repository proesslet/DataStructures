// Project 6
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <string>  // for storing string
#include <fstream> // for reading a file again and again
#include <map>
#include <unordered_map>

using namespace std;

// Hash Function
void hashFunction(string s)
{
	// TODO: Write hash function
}

// write display functions for map and unordered map

using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	string fileName; // to read in the name of the fileInput from redirected input

	cin >> fileName;
	cout << "Name of fileInput: " << fileName << endl;

	// MAP
	map<int, vector<string>> m1;
	// open a fileName in read mode
	ifstream fI;
	fI.open(fileName);

	char option;
	string temp;
	// reading and performing operations
	// start timer
	while (fI >> option)
	{
		fI >> temp;
		// create the structure - map - m1
	}
	// stop timer

	// close the opened file
	fI.close();

	// UNORDERED MAP
	unordered_map<int, vector<string>> m2;
	// open a file again in read mode
	fI.open(fileName);

	// start timer
	while (fI >> option)
	{
		fI >> temp;
		// create the structure - unordered map - m2
	}
	// stop timer

	// close the opened file
	fI.close();

	return 0;
}
