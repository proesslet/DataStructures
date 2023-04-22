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
	int nodeNumber;	   // to store the node number
	string type;	   // can either be START, END, IF, BLOCK
	string textWithin; // can be expression or statement - for START and END this will be empty string
public:
	// TODO: construtors, getters, setters and other methods as needed
	// Default constructor
	Node()
	{
		nodeNumber = 0;
		type = "";
		textWithin = "";
	}

	Node(int tempNodeNum, string tempType, string tempText)
	{
		nodeNumber = tempNodeNum;
		type = tempType;
		textWithin = tempText;
	}

	// Setters and Getters
	int getNodeNumber()
	{
		return nodeNumber;
	}

	string getType()
	{
		return type;
	}

	string getTextWithin()
	{
		return textWithin;
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// function to convert the given flowchart to generate code
void convertFlowChart(vector<Node> allNodes, vector<vector<int>> adjList)
{
	// use stack (no recursion) to convert the flowchart into psuedo code
	// print the code as an output here using cout

	// Create a stack to store the nodes
	stack<int> nodeStack;

	// Create a vector to store the nodes in reverse postorder
	vector<int> reversePostorder;

	// Create a vector to store the visited nodes
	vector<bool> visited(allNodes.size(), false);

	// Push the start node onto the stack
	nodeStack.push(0);

	// While the stack is not empty
	while (!nodeStack.empty())
	{
		// Get the top node
		int topNode = nodeStack.top();

		// If the top node has not been visited
		if (!visited[topNode])
		{
			// Mark the top node as visited
			visited[topNode] = true;

			// Get the adjacent nodes
			vector<int> adjacentNodes = adjList[topNode];

			// For each adjacent node
			for (int i = 0; i < adjacentNodes.size(); i++)
			{
				// If the adjacent node has not been visited
				if (!visited[adjacentNodes[i]])
				{
					// Push the adjacent node onto the stack
					nodeStack.push(adjacentNodes[i]);
				}
			}
		}
		// If the top node has been visited
		else
		{
			// Pop the top node off the stack
			nodeStack.pop();

			// Add the top node to the reverse postorder vector
			reversePostorder.push_back(topNode);
		}
	}

	// Create a counter to keep track of nested if statements
	int ifCounter = 0;

	// For each node in the reverse postorder vector
	for (int i = reversePostorder.size() - 1; i >= 0; i--)
	{
		// Get the node
		Node node = allNodes[reversePostorder[i]];

		// If the node is a start node
		if (node.getType() == "START")
		{
			// Print the start
			cout << "start" << endl;
		}
		// If the node is an end node
		else if (node.getType() == "END")
		{
			// Print the end
			cout << "end" << endl;
		}
		// If the node is an if node
		else if (node.getType() == "IF")
		{
			// Print the if statement
			cout << "if (" << node.getTextWithin() << ")" << endl;
			cout << "{" << endl;

			// Increment the if counter
			ifCounter++;
		}
		// If the node is a block node
		else if (node.getType() == "BLOCK")
		{
			// We need to determine if we should print an else statement or not
			// as well as if we should print a closing bracket or not

			// If the node is the last node in the reverse postorder vector
			if (i == reversePostorder.size() - 1)
			{
				// Print the block statement
				cout << node.getTextWithin() << endl;
			}

			// If the node is not part of a nested if statement
			if (ifCounter == 0)
			{
				// Print the block statement
				cout << node.getTextWithin() << endl;
			}

			// If the node is not the last node in the reverse postorder vector
			else
			{
				// Get the next node
				Node nextNode = allNodes[reversePostorder[i + 1]];

				// If the next node is an if node
				if (nextNode.getType() == "IF")
				{
					// Print the block statement
					cout << node.getTextWithin() << endl;
					cout << endl;
					cout << "}" << endl;
				}
				// If the next node is a block node
				else if (nextNode.getType() == "BLOCK")
				{
					if (ifCounter == 0)
					{
						cout << node.getTextWithin() << endl;
					}
					else
					{
						// Print the else statement
						cout << "else" << endl;
						cout << "{" << endl;
						// Print the block statement
						cout << node.getTextWithin() << endl;
						cout << endl;
						// Print the closing bracket
						cout << "}" << endl;
						cout << endl;

						// Decrement the if counter
						ifCounter--;

						// If the if counter is greater than 0
						if (ifCounter > 0)
						{
							// Print the closing bracket
							cout << "}" << endl;
						}
					}
				}
				// If the next node is an end node
				else if (nextNode.getType() == "END")
				{
					// Print the block statement
					cout << node.getTextWithin() << endl;
				}
			}
		}
	}
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	int numNodesInFlowChart; // number of nodes in the flow chart

	cin >> numNodesInFlowChart;
	cout << "Number of nodes: " << numNodesInFlowChart << endl;

	// Node objects array to store all the information
	vector<Node> allNodes(numNodesInFlowChart);

	// read in the information about the nodes and store it in allNodes
	for (int i = 0; i < numNodesInFlowChart; i++)
	{
		int nodeNumber;
		string type;
		string textWithin;

		cin >> nodeNumber;
		cin >> type;
		getline(cin, textWithin);

		// Trim the textWithin string of any leading or trailing whitespace
		if (textWithin[0] == ' ')
		{
			textWithin.erase(0, 1);
		}
		if (textWithin[textWithin.length() - 1] == ' ')
		{
			textWithin.erase(textWithin.length() - 1, 1);
		}

		// Create a new node
		Node newNode(nodeNumber, type, textWithin);

		// Add the node to the allNodes array
		allNodes[nodeNumber] = newNode;
		if (type != "START" && type != "END")
		{
			cout << nodeNumber << ": " << type << " node - " << textWithin << endl;
		}
		else if (type == "START" || type == "END")
		{
			cout << nodeNumber << ": " << type << " node" << endl;
		}
	}

	// adjacency list to store the flow chart
	vector<vector<int>> adjList(numNodesInFlowChart);

	// read in the adjaceny list
	cout << "AdjList:" << endl;
	for (int i = 0; i < numNodesInFlowChart; i++)
	{
		int nodeNumber;
		cin >> nodeNumber;

		// Create a vector to store the adjacent nodes
		vector<int> adjacentNodes;

		// Read in the adjacent nodes
		// While the next character is not a newline
		// Take into account that there could be an extra space at the end of the line
		while (cin.peek() != '\n')
		{

			int adjacentNode;
			cin >> adjacentNode;

			// Add the adjacent node to the vector
			adjacentNodes.push_back(adjacentNode);
			if (cin.peek() == ' ')
			{
				cin.ignore();
			}
		}

		// Add the adjacent nodes to the adjList
		adjList[nodeNumber] = adjacentNodes;

		// Print the adjacent nodes
		cout << nodeNumber << ": ";
		for (int j = 0; j < adjacentNodes.size(); j++)
		{
			cout << adjacentNodes[j] << " ";
		}
		cout << endl;
	}

	// call the convertFlowChart function with the allNodes and adjList parameters
	convertFlowChart(allNodes, adjList);

	return 0;
}
