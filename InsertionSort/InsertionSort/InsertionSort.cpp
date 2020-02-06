#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <chrono>
using namespace std;

//ProtoTypes of functions used in the Program
void RandomArray(int array[], int size);
void InsertionSort(int array [], int startIndex, int endIndex);

int main() {

	ofstream outputFile; 
	int SIZE;
	cout << "Enter number of integers" << endl;
	cin >> SIZE;
	int * array = new int [SIZE];

	//Generating Random integers
	RandomArray(array, SIZE);

	
	auto start = chrono::high_resolution_clock::now(); //Variable to store starting time

	InsertionSort(array, 0, SIZE); //insertion function called to sort array
	
	auto end = chrono::high_resolution_clock::now(); // storin
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(10);

	//Storing the sorted array in the file
	outputFile.open("InsertionSort.csv");
	for (int i = 0; i < SIZE; i++) {
		outputFile << array[i] << endl;

	}
	outputFile.close();

	//deleting the dynamically allocated array
	delete[] array;
	system("pause");
}

//Function to generate random numbers
void RandomArray(int array[], int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 1000000;
	}
}

//Function to sort the array
void InsertionSort(int array[], int start, int end) {
	for (int j = start+1 ; j < end; j++) {
		int key = array[j];
		int i = j - 1;
		while (i >= start && array[i] > key) { 
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}
