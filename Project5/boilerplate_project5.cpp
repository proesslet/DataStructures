// Project 5
// CS 2413 Data Structures
// Spring 2023

// Code generated for input 1 would be:
// if(expression1)
// {
// 	statement1;
// }
// else
// {
// 	statement2;
// }

#include <iostream>
#include <string> // for the fields in the class
#include <vector> // for the flowchart structures
#include <stack>  // for conversion

using namespace std;

// class to store node information
class Node
{
private:
	int nodeNumber;    // to store the node number
	string type;       // can either be START, END, IF, BLOCK
	string textWithin; // can be expression or statement - for START and END this will be empty string
public:
	// TODO: construtors, getters, setters and other methods as needed
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// function to convert the given flowchart to generate code
void convertFlowChart(vector<Node> allNodes, vector<vector<int>> adjList)
{
	// TODO: use stack (no recursion) to convert the flowchart into psuedo code
	// print the code as an output here using cout
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	int numNodesInFlowChart; // number of nodes in the flow chart

	cin >> numNodesInFlowChart;
	cout << "Number of nodes: " << numNodesInFlowChart << endl;

	// Node objects array to store all the information
	vector<Node> allNodes(numNodesInFlowChart);

	// TODO: read in the information about the nodes and store it in allNodes

	// adjacency list to store the flow chart
	vector<vector<int>> adjList(numNodesInFlowChart);

	// TODO: read in the adjaceny list

	// TODO: call the convertFlowChart function with the allNodes and adjList parameters

	return 0;
}
