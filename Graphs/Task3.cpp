
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<windows.h>
#include <vector>
using namespace std;

// Declaring class to store all the data related to graphs
class Graph
{
public:
	int vertice;
	int vertices = 0;
	int edges = 0;
	vector <char> graph[100];
	bool directed = false;
	bool* present;

	void addEdge(vector <char> graph[], char a, char b, bool directed);
	void BFS(int startVertex);
};


//To add new edges in rhe graph
void Graph::addEdge(vector <char> graph[], char a, char b, bool directed) {
	if (directed) //if graph is directed
		graph[a].push_back(b);
	else { //if it is undirected
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}


// Breath First Search

void Graph::BFS(int start)
{
	present = new bool[vertices];
	for (int i = 0; i < vertices; i++){
		present[i] = false;
	}

	vector<int> a;
	present[start] = true;
	a.push_back(start);
	vector<int>::iterator visited;
	cout << "The visited vertex are: ";
	while (!a.empty())
	{
		int currentNode = a.front();
		cout << currentNode << ", ";
		a.pop_front();
		for (visited = graph[currentNode].begin(); visited != graph[currentNode].end(); ++visited)
		{
			int neighVertex = *visited;
			if (!present[neighVertex])
			{
				present[neighVertex] = true;
				a.push_back(neighVertex);
			}
		}
	}
}

int main()
{
	
	Graph g;
	int i, direct;

	char spc, temp;
	string name = "";
	ifstream input;
	input.open("data.txt"); //opening file
	if (!input) {
		cout << "Unable to open file " << endl;
		exit(1);
	}
	else
	{
		input >> g.vertices;
		input >> spc;
		input >> direct;
		if (direct == 0) {
			g.directed = false;
		}
		else {
			g.directed = true;
		}
		for (int i = 0; i < g.vertices; i++) {
			input >> spc;
			name += spc;
		}
		input >> g.edges;
		for (int i = 0; i < g.edges; i++) {
			input >> spc;
			input >> temp;
			g.addEdge(g.graph, spc, temp, g.directed); //creatig edges in the list
		}
	}
	input.close(); //closing file
	g.BFS(4);

	return 0;
}