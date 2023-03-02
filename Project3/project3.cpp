// Project 3 
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <vector> // for array of transactions
#include <list> // for blockchain

using namespace std;

class transaction
{
	int tID; // transaction id
	int fromID; // source ID
	int toID; // target ID
	int tAmount; // how much is being transfered
	string timeStamp; // time of the transaction read from the input file

	public: 
		transaction(); // default constructor
		transaction(int temptID, int tempfromID, int temptoID, int temptAmount, int temptimeStamp); // non default constructor - default 100 for values
		// all setters and getters
};

class block
{
	int blockNumber; // block number of the current block
	int currentNumTransactions; // how many transactions are currently in the block
	int maxNumTransactions; // how many maximum transactions can be in the block
	vector<transaction> bTransactions; // vector of transaction objects

	public:
		block(); // default constructor
		block(int bNumber, int maxTransactions); // non default constructor
		// search method for searching through array of transactions
		// insert method to insert a new transaction
		// setters and getters as needed
};

class blockChain
{
	int currentNumBlocks; // maintain the size of the list/block chain list
	list<block> bChain; // blockchain as a linked list

	public: 
		blockChain(); // default constructor
		blockChain(int tPerB); // non default constructor
		// insert method to insert new transaction into the block chain - add new block if existing block is full
		// while inserting new block into list, insert front 
		// setters and getters as needed
};

int main()
{
	int numTransactionsPerBlock; // max transactions per block

	cin >> numTransactionsPerBlock;
	cout << "Number of transactions per block: " << numTransactionsPerBlock << endl;

	int totalNumTransactions; // total transactions to be read from the input file

	cin >> totalNumTransactions;
	cout << "Total number of transactions: " << totalNumTransactions << endl;

	// object of block chain
	blockChain* b1 = new blockChain(numTransactionsPerBlock);

	// insert transactions into the blockchain

	return 0;
}

