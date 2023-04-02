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
    void setTID(int temptID);
    void setFromID(int tempfromID);
    void setFromValue(int tempfromValue);
    void setToID(int temptoID);
    void setToValue(int temptoValue);
    void setTAmount(int temptAmount);
    void setTimeStamp(string temptimeStamp);
    int getTID();
    int getFromID();
    int getFromValue();
    int getToID();
    int getToValue();
    int getTAmount();
    string getTimeStamp();
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

// Setters and Getters
void transaction::setTID(int temptID)
{
    tID = temptID;
}

void transaction::setFromID(int tempfromID)
{
    fromID = tempfromID;
}

void transaction::setFromValue(int tempfromValue)
{
    fromValue = tempfromValue;
}

void transaction::setToID(int temptoID)
{
    toID = temptoID;
}

void transaction::setToValue(int temptoValue)
{
    toValue = temptoValue;
}

void transaction::setTAmount(int temptAmount)
{
    tAmount = temptAmount;
}

void transaction::setTimeStamp(string temptimeStamp)
{
    timeStamp = temptimeStamp;
}

int transaction::getTID()
{
    return tID;
}

int transaction::getFromID()
{
    return fromID;
}

int transaction::getFromValue()
{
    return fromValue;
}

int transaction::getToID()
{
    return toID;
}

int transaction::getToValue()
{
    return toValue;
}

int transaction::getTAmount()
{
    return tAmount;
}

string transaction::getTimeStamp()
{
    return timeStamp;
}

// Other Methods
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
    void insert(transaction t1);
    // setters and getters as needed
    void setCurrentNumTransactions(int tempCurrentNumTransactions);
    int getBlockNumber();
    int getCurrentNumTransactions();
    int getMaxNumTransactions();
    // TODO: P4: search for an ID in the bTransaction vector
    int search(int id);
    // other methods as needed
    void displayBlock();
};

block::block(int bNumber, int maxTransactions)
{
    blockNumber = bNumber;
    maxNumTransactions = maxTransactions;
    currentNumTransactions = 0;
}

void block::insert(transaction t1)
{
    bTransactions.push_back(t1);
    currentNumTransactions++;
}

// Setters and Getters
void block::setCurrentNumTransactions(int tempCurrentNumTransactions)
{
    currentNumTransactions = tempCurrentNumTransactions;
}

int block::getBlockNumber()
{
    return blockNumber;
}

int block::getCurrentNumTransactions()
{
    return currentNumTransactions;
}

int block::getMaxNumTransactions()
{
    return maxNumTransactions;
}

// Search for an ID in the bTransaction vector
int block::search(int id)
{
    for (int i = 0; i < bTransactions.size(); i++)
    {
        if (bTransactions[i].getFromID() == id || bTransactions[i].getToID() == id)
        {
            return i;
        }
    }
    return -1;
}

// Other Methods
void block::displayBlock()
{
    cout << "Block Number: " << blockNumber << " -- Number of Transactions: " << currentNumTransactions << endl;
    for (int i = 0; i < bTransactions.size(); i++)
    {
        bTransactions[i].displayTransaction();
    }
}

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
    void insert(transaction t1);
    // setters and getters as needed
    void setCurrentNumBlocks(int tempCurrentNumBlocks);
    int getCurrentNumBlocks();
    // TODO: P4: search for an ID across all blocks in bChain
    int search(int id);
    // other methods as needed
    void displayBlockChain();
};

blockChain::blockChain(int tPerB)
{
    block b1(0, tPerB);
    bChain.push_front(b1);
    currentNumBlocks = 1;
}

void blockChain::insert(transaction t1)
{
    if (bChain.front().getCurrentNumTransactions() == bChain.front().getMaxNumTransactions())
    {
        block b1(currentNumBlocks, bChain.front().getMaxNumTransactions());
        bChain.push_front(b1);
        currentNumBlocks++;
    }
    bChain.front().insert(t1);
}

// Setters and Getters
void blockChain::setCurrentNumBlocks(int tempCurrentNumBlocks)
{
    currentNumBlocks = tempCurrentNumBlocks;
}

int blockChain::getCurrentNumBlocks()
{
    return currentNumBlocks;
}

// Search for an ID across all blocks in bChain
int blockChain::search(int id)
{
    int index = -1;
    for (list<block>::iterator it = bChain.begin(); it != bChain.end(); it++)
    {
        index = it->search(id);
        if (index != -1)
        {
            return index;
        }
    }
    return -1;
}

// Other Methods
void blockChain::displayBlockChain()
{
    cout << "Current Number of Blocks: " << currentNumBlocks << endl;
    for (list<block>::iterator it = bChain.begin(); it != bChain.end(); it++)
    {
        it->displayBlock();
    }
}

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
    void insert(int nodeNumber, transaction t1);
    // setters and getters as needed
    void setU(int tempU);
    void setV(int tempV);
    // other methods as needed
    void display();
};

blockNetwork::blockNetwork(int numberOfNodes)
{
    numNodes = numberOfNodes;
    for (int i = 0; i < numNodes; i++)
    {
        blockChain b1(10);
        allNodes.push_back(b1);
    }
}

void blockNetwork::insert(int nodeNumber, transaction t1)
{
    cout << "Inserting transaction to block #" << allNodes[nodeNumber].getCurrentNumBlocks() << " in node " << nodeNumber << endl;
    // Search for fromID and toID in the block chain
    int fromID = t1.getFromID();
    int toID = t1.getToID();

    allNodes[nodeNumber].insert(t1);
}
// Setters and Getters
void blockNetwork::setU(int tempU)
{
    u.push_back(tempU);
}

void blockNetwork::setV(int tempV)
{
    v.push_back(tempV);
}

// Other Methods
void blockNetwork::display()
{
    for (int i = 0; i < numNodes; i++)
    {
        cout << "~~~ Node " << i << endl;
        allNodes[i].displayBlockChain();
    }
}

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
    int numEdges;
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        n1->setU(u);
        n1->setV(v);
    }
    for (int i = 0; i < totalNumTransactions; i++)
    {
        int nodeNumber, tID, fromID, toID, amount, tAmount;
        string timeStamp;
        cin >> nodeNumber >> tID >> fromID >> toID >> amount >> tAmount >> timeStamp;
        transaction t1(tID, fromID, toID, tAmount, timeStamp);
        n1->insert(nodeNumber, t1);
    }

    n1->display(); // make sure you write display methods for each class

    return 0;
}
