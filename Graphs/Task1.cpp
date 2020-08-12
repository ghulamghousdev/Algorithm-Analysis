#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<windows.h>
#include <vector>
using namespace std;

//Graph attributes stored in a struct
struct graphAttributes {
	int vertices = 0;
	int edges = 0;
	vector <int> graph[100];
	bool directed = false;
};

void printNeighbours(vector <int> graph[], int vertice); //to print neihbours of a vertix
void addEdge(vector <int> graph[], int u, int v, bool directed); //To add new edges into the graph
void print(vector <int> graph[], int vertices); //To print graph

int main() {

	graphAttributes g;
	int i, direct;

	char spc, temp;
	string name = "";
	ifstream input;
	input.open("data.txt"); //opening input file
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
			addEdge(g.graph, spc, temp, g.directed);
		}
	}
	input.close(); //closing input file
	system("color 80");
	int option;
	do
	{
		system("cls");
		cout << setw(70) << " Graphs " << endl;
		cout << "\nPlease Select Your Option\n";
		cout << " 1- How many Vertices are there?\n";
		cout << " 2- How many Edges are there?\n";
		cout << " 3- Is the graph Directed?\n";
		cout << " 4- Which are the neighbors of any vertex?\n";
		cout << "\n Enter option!\n";
		cin >> option;
		switch (option)
		{
		case 1: //to show number of vertices
		{
			system("cls");
			cout << setw(70) << " Graphs " << endl;
			cout << " 1- How many Vertices are there?\n";
			cout << "Ans:\n	The total number of Vertices in this Graph are " << g.vertices << endl;
			cout << " Press any key to continue...";
			system("pause>nul");
			break;
		}
		case 2: //To show number of edges
		{
			system("cls");

			cout << setw(70) << " Graphs " << endl;
			cout << " 2- How many Edges are there?\n";
			cout << "Ans:\n	The total number of Edges in this Graph are " << g.edges << endl;
			cout << " Press any key to continue...";
			system("pause>nul");

			break;
		}
		case 3: //To show if the graph is directed or not
		{
			system("cls");
			cout << setw(70) << " Graphs" << endl;
			cout << " 3- Is the graph Directed?\n";
			if (g.directed)
				cout << "Ans:\n	Yes, the Graph is directed." << endl;
			else
				cout << "Ans:\n	No, the Graph is not directed.";
			cout << " Press any key to continue...";
			system("pause>nul");
			break;
		}
		case 4://TO show neighbour vertices of vertix
		{
			system("cls");

			cout << setw(70) << " Graphs " << endl;
			cout << "Enter the Vertix" << endl;
			int a;
			cin >> a;
			cout << " 4- Which are the neighbors of vertex " << a << "?\n";
			cout << "Ans:\n	";
			printNeighbours(g.graph, a);
			cout << " Press any key to continue...";
			system("pause>nul");
			break;
		}
	
		}
	} while (option != 5);

	return 0;
}

//To add new edges to the graph
void addEdge(vector <int> graph[], int a, int b, bool directed) {
	if (directed)
		graph[a].push_back(b);
	else {
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void print(vector <int> graph[], int vertices) {
	for (int i = 0; i < vertices; i++) {
		cout << i << " ";
		for (auto u : graph[i])
			cout << "	->	" << u;
		cout << endl;
	}
}

void printNeighbours(vector <int> graph[], int vertice) {
	cout << "\nNeighbours of vertice " << vertice << " are ";
	for (auto u : graph[vertice])
		cout << " " << u;
}
