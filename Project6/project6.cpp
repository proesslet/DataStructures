// Project 6
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <string>  // for storing string
#include <fstream> // for reading a file again and again
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Hash Function
int hashFunction(string s)
{
	// Write hash function for string using chaining to handle collisions
	// Idea for this was provided by the TA in an announcement
	// Mod 26
	int hash_value = 0;
	int ascii_value = (int)s[0];
	hash_value = ascii_value % 26;

	return hash_value;
}

// Display functions for map and unordered map
void displayMap(map<int, vector<string>> m)
{
	cout << "Map:" << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
}

void displayUnorderedMap(unordered_map<int, vector<string>> m)
{
	cout << "Unordered Map:" << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
}

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
	// clock_t start = clock();
	while (fI >> option)
	{
		fI >> temp;
		// create the structure - map - m1
		if (option == 'I')
		{
			int temp2 = hashFunction(temp);
			// if the key already exists, then add the value to the vector
			if (m1.find(temp2) != m1.end())
			{
				m1[temp2].push_back(temp);
			}
			// if the key does not exist, then create a new key and add the value to the vector
			else
			{
				m1.insert(pair<int, vector<string>>(temp2, {temp}));
			}
		}
		else if (option == 'R')
		{
			// if the key exists, then remove the value from the vector
			vector<string> temp3 = m1[hashFunction(temp)];
			for (int i = 0; i < temp3.size(); i++)
			{
				if (temp3[i] == temp)
				{
					temp3.erase(temp3.begin() + i);
				}
			}
		}
	}
	// stop timer
	// clock_t stop = clock();
	// double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	// cout << "Elapsed time for map in ms: " << elapsed << endl;

	// close the opened file
	fI.close();

	// UNORDERED MAP
	unordered_map<int, vector<string>> m2;
	// open a file again in read mode
	fI.open(fileName);

	// start timer
	// start = clock();
	while (fI >> option)
	{
		fI >> temp;
		// create the structure - unordered map - m2
		if (option == 'I')
		{
			// if the key already exists, then add the value to the vector
			if (m2.find(hashFunction(temp)) != m2.end())
			{
				m2[hashFunction(temp)].push_back(temp);
			}
			// if the key does not exist, then create a new key and add the value to the vector
			else
			{
				m2.insert(pair<int, vector<string>>(hashFunction(temp), {temp}));
			}
		}
		else if (option == 'R')
		{
			// if the key exists, then remove the value from the vector
			vector<string> temp3 = m2[hashFunction(temp)];
			for (int i = 0; i < temp3.size(); i++)
			{
				if (temp3[i] == temp)
				{
					temp3.erase(temp3.begin() + i);
				}
			}
		}
	}
	// stop timer
	// stop = clock();
	// elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	// cout << "Elapsed time for unordered map in ms: " << elapsed << endl;

	// close the opened file
	fI.close();

	displayMap(m1);
	displayUnorderedMap(m2);
	return 0;
}
