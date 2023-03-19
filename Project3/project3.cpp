// Project 3
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <vector> // for array of transactions
#include <list>	  // for blockchain

using namespace std;

class transaction
{
	int tID;		  // transaction id
	int fromID;		  // source ID
	int toID;		  // target ID
	int tAmount;	  // how much is being transfered
	string timeStamp; // time of the transaction read from the input file

public:
	// default constructor
	transaction()
	{
		tID = 0;
		fromID = 0;
		toID = 0;
		tAmount = 0;
		timeStamp = "00:00:00";
	}
	// non default constructor
	transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp)
	{
		tID = temptID;
		fromID = tempfromID;
		toID = temptoID;
		tAmount = temptAmount;
		timeStamp = temptimeStamp;
	}
	// non default constructor - default 100 for values
	transaction(int temptID, int tempfromID, int temptoID, int temptAmount)
	{
		tID = temptID;
		fromID = tempfromID;
		toID = temptoID;
		tAmount = temptAmount;
		timeStamp = "00:00:00";
	}
	// all setters and getters
	void setID(int temptID)
	{
		tID = temptID;
	}
	void setFromID(int tempfromID)
	{
		fromID = tempfromID;
	}
	void setToID(int temptoID)
	{
		toID = temptoID;
	}
	void setAmount(int temptAmount)
	{
		tAmount = temptAmount;
	}
	void setTimeStamp(string temptimeStamp)
	{
		timeStamp = temptimeStamp;
	}
	int getID()
	{
		return tID;
	}
	int getFromID()
	{
		return fromID;
	}
	int getToID()
	{
		return toID;
	}
	int getAmount()
	{
		return tAmount;
	}
	string getTimeStamp()
	{
		return timeStamp;
	}
};

class block
{
	int blockNumber;				   // block number of the current block
	int currentNumTransactions;		   // how many transactions are currently in the block
	int maxNumTransactions;			   // how many maximum transactions can be in the block
	vector<transaction> bTransactions; // vector of transaction objects

public:
	// default constructor
	block()
	{
		blockNumber = 0;
		maxNumTransactions = 0;
		currentNumTransactions = 0;
	}
	// non default constructor
	block(int bNumber, int maxTransactions)
	{
		blockNumber = bNumber;
		maxNumTransactions = maxTransactions;
		currentNumTransactions = 0;
	}
	// search method for searching through array of transactions
	void search(int tID)
	{
		for (int i = 0; i < bTransactions.size(); i++)
		{
			if (bTransactions[i].getID() == tID)
				cout << "Transaction ID: " << bTransactions[i].getID() << " From ID: " << bTransactions[i].getFromID() << " To ID: " << bTransactions[i].getToID() << " Amount: " << bTransactions[i].getAmount() << " Time Stamp: " << bTransactions[i].getTimeStamp() << endl;
			else
				cout << "Transaction ID: " << tID << " not found" << endl;
		}
	}
	// insert method to insert a new transaction
	void insert(transaction t1)
	{
		bTransactions.push_back(t1);
		currentNumTransactions++;
	}
	// setters and getters as needed
	void setCurrentNumTransactions(int cNumTransactions)
	{
		currentNumTransactions = cNumTransactions;
	}
	int getBlockNumber()
	{
		return blockNumber;
	}
	int getCurrentNumTransactions()
	{
		return currentNumTransactions;
	}
	int getMaxNumTransactions()
	{
		return maxNumTransactions;
	}
	int getTransactionID(int index)
	{
		return bTransactions[index].getID();
	}
};

class blockChain
{
	int currentNumBlocks; // maintain the size of the list/block chain list
	list<block> bChain;	  // blockchain as a linked list

public:
	// default constructor
	blockChain()
	{
		block b1;
		bChain.push_front(b1);
		currentNumBlocks = 1;
	}
	// non default constructor
	blockChain(int tPerB)
	{
		block b1(0, tPerB);
		bChain.push_front(b1);
		currentNumBlocks = 1;
	}
	// insert method to insert new transaction into the block chain - add new block if existing block is full
	// while inserting new block into list, insert front
	void insert(transaction t1)
	{
		if (bChain.front().getCurrentNumTransactions() == bChain.front().getMaxNumTransactions())
		{
			block b1(currentNumBlocks, bChain.front().getMaxNumTransactions());
			b1.insert(t1);
			bChain.push_front(b1);
			currentNumBlocks++;
		}
		else
		{
			bChain.front().insert(t1);
		}
	}

	// setters and getters as needed
	void setCurrentNumBlocks(int cNumBlocks)
	{
		currentNumBlocks = cNumBlocks;
	}
	int getCurrentNumBlocks()
	{
		return currentNumBlocks;
	}
	int getTransactionsPerBlock()
	{
		return bChain.front().getMaxNumTransactions();
	}
	// get block method to get a block from the block chain
	block getBlock(int bNumber)
	{
		list<block>::iterator it;
		for (it = bChain.begin(); it != bChain.end(); it++)
		{
			if (it->getBlockNumber() == bNumber)
				return *it;
		}
	}
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
	blockChain *b1 = new blockChain(numTransactionsPerBlock);

	// insert transactions into the blockchain for each transaction in input
	for (int i = 0; i < totalNumTransactions; i++)
	{
		int tID, fromID, toID, tAmount;
		string timeStamp;

		cin >> tID >> fromID >> toID >> tAmount >> timeStamp;

		transaction *t1 = new transaction(tID, fromID, toID, tAmount, timeStamp);

		b1->insert(*t1);
	}

	return 0;
}
