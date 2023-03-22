// Project 4
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <vector> // for array of transactions and array of blockChains
#include <list>   // for blockchain

using namespace std;


using namespace std;

class transaction
{
    int tID;          // transaction id
    int fromID;       // source ID
    int fromValue;    // P4: how much funds does the source ID person have? If first time, then initialize with 100 coins
    int toID;         // target ID
    int toValue;      // P4: how much funds does the source ID person have? If first time, then initialize with 100 coins
    int tAmount;      // how much is being transfered
    string timeStamp; // time of the transaction read from the input file

public:
    transaction();                                                                                 // default constructor
    transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp); // non default constructor - P4: default 100 for from and to values
    // all setters and getters
    // other methods as needed
    void displayTransaction();
};

transaction::transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp)
{
    tID = temptID;
    fromID = tempfromID;
    toID = temptoID;
    tAmount = temptAmount;
    timeStamp = temptimeStamp;
    fromValue = 100;
    toValue = 100;
}

void transaction::displayTransaction()
{
    cout << tID << " " << fromID << " " << fromValue << " " << toID << " " << toValue << " " << tAmount << " " << timeStamp << endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class block
{
    int blockNumber;                   // block number of the current block
    int currentNumTransactions;        // how many transactions are currently in the block
    int maxNumTransactions;            // how many maximum transactions can be in the block
    vector<transaction> bTransactions; // vector of transaction objects

public:
    block();                                 // default constructor
    block(int bNumber, int maxTransactions); // non default constructor
    // insert method to insert a new transaction
    // setters and getters as needed
    // P4: search for an ID in the bTransaction vector
    // other methods as needed
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class blockChain
{
    int currentNumBlocks; // maintain the size of the list/block chain list
    list<block> bChain;   // blockchain as a linked list

public:
    blockChain();          // default constructor
    blockChain(int tPerB); // non default constructor
    // insert method to insert new transaction into the block chain - add new block if existing block is full
    // while inserting new block into list, insert front
    // setters and getters as needed
    // P4: search for an ID across all blocks in bChain
    // other methods as needed
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class blockNetwork
{
    int numNodes;                // maintain the number of nodes in the network
    vector<blockChain> allNodes; // vector of all the blockChains in the network
    vector<int> u;               // edge list u node
    vector<int> v;               // edge list v node

public:
    blockNetwork();                  // default constructor
    blockNetwork(int numberOfNodes); // non default constructor
    // insert method to insert new transaction into the block chain in a specific node - there will be a block chain existent in each node (allNodes vector)
    // setters and getters as needed
    // other methods as needed
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    int numNodesInNetwork; // number of nodes in the network

    cin >> numNodesInNetwork;
    cout << "Number of nodes: " << numNodesInNetwork << endl;

    int numTransactionsPerBlock; // max transactions per block

    cin >> numTransactionsPerBlock;
    cout << "Number of transactions per block: " << numTransactionsPerBlock << endl;

    int totalNumTransactions; // total transactions to be read from the input file

    cin >> totalNumTransactions;
    cout << "Total number of transactions: " << totalNumTransactions << endl;

    // object of block network
    blockNetwork *n1 = new blockNetwork(numNodesInNetwork);

    // TODO: input the transaction information and insert to n1

    n1->display(); // make sure you write display methods for each class 

    return 0;
}
