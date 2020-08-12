
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<windows.h>
#include <vector>
using namespace std;

//Struct to store attributes of a graph
struct graphAttributes {
	int vertices = 0;
	int edges = 0;
	vector <char> graph[100];
	bool directed = false;
};

vector <int> startTime; //To store start time of each node
vector <int> finishTime; //To store finish time of each node
vector <string> nodeColor; //TO keep track of color of each node
void DFS_Visit(vector <char>  graph[], int nodeIndex, string name, vector <string> nodeColor, int vertices, int& currentTime);
void DFS(vector <char> graph[], int vertices, vector <string> nodeColor, string name);
void printNeighbours(vector <char> graph[], int vertice);
void addEdge(vector <char> graph[], char u, char v, bool directed);
void print(vector <char> graph[], int vertices);

int main() {

	graphAttributes g; //declaring object of graph attribute
	int i, direct;

	char spc, temp;
	string name = "";
	ifstream input;
	input.open("data.txt"); //oprning file
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
			addEdge(g.graph, spc, temp, g.directed); //creatig edges in the list
		}
	}
	input.close(); //closing file
	system("color 80");
	DFS(g.graph, 4, nodeColor, name); //Calling depth first search to traverse the graph

	return 0;
}

//To add new edges in rhe graph
void addEdge(vector <char> graph[], char a, char b, bool directed) {
	if (directed) //if graph is directed
		graph[a].push_back(b);
	else { //if it is undirected
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

//To print the graph
void print(vector <char> graph[], int vertices) {
	for (int i = 0; i < vertices; i++) {
		cout << i << " ";
		for (auto u : graph[i])
			cout << "	->	" << u;
		cout << endl;
	}
}

//To print neighbours of a vertix
void printNeighbours(vector <char> graph[], int vertice) {
	cout << "\nNeighbours of vertix " << vertice << " are ";
	for (auto u : graph[vertice])
		cout << " " << u;
}

//DFS search
void DFS(vector <char> graph[], int vertices, vector <string> nodeColor, string name) {
	int currentTime = 0;
	for (int i = 0; i < vertices; i++) { //initilizing with default values
		nodeColor.emplace_back("white");
		startTime.emplace_back(0);
		finishTime.emplace_back(0);
	}
	for (int i = 0; i < vertices; i++) {
		if (nodeColor[i] == "white") { //If node is visited first time exploring all the possible edges
			DFS_Visit(graph, i, name, nodeColor, vertices, currentTime);
		}
	}
}


void DFS_Visit(vector <char>  graph[], int nodeIndex, string name, vector <string> nodeColor, int vertices, int& currentTime) {
	currentTime++;
	startTime[nodeIndex] = currentTime;
	nodeColor[nodeIndex] = "grey";
	cout << name[nodeIndex] << endl;
	int j;
	for (auto const& p : graph[nodeIndex]){
		for (int i = 0; i < vertices; i++){
			if (name[i] == p){
				j = i;
			}
		}
		if (nodeColor[j] == "white"){
			DFS_Visit(graph, j, name, nodeColor, vertices, currentTime);
		}
	}

	nodeColor[nodeIndex] = "Black";
	currentTime = currentTime + 1;

	finishTime[nodeIndex] = currentTime;
}
