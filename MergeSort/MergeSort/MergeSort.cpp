#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <chrono>

using namespace std;

//ProtoTypes of functions used in the program
void RandomArray(int array[], int size); 
void MergeSort(int array[] , int startIndex, int endIndex);
void Merge(int array[], int p, int q, int r);

int main() {

	ofstream outputFile; //output file variable
	int SIZE;
	cout << "Enter the size of the array" << endl;
	cin >> SIZE; //Taking number of integers from user
	int * array = new int [SIZE]; //Dynamically allocated array
	
	RandomArray(array, SIZE); //Generating random numbers

	auto start = chrono::high_resolution_clock::now();

	MergeSort(array, 0, SIZE - 1); //Merge function to dort the array

	auto end = chrono::high_resolution_clock::now(); 
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); //calculating time taken by the merge algorithm
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(10);

	//Saving the sorted array in the file 
	outputFile.open("MergeSort.csv");
	for (int i = 0; i < SIZE; i++) {
		outputFile << array[i] << endl;

	}
	outputFile.close();

	delete[] array; //Deleting dynamically allocated memory

	system("pause");
}

//Function to generate random numbers
void RandomArray(int array[], int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		array[i] = rand() ;
	}
}

//Merge Sort function to sort the array
void MergeSort(int array[], int start, int end) {

	if (start < end) {
		int mid = floor((start + end) / 2); //Finding the mid point of the array
		MergeSort(array, start, mid); 
		MergeSort(array, mid + 1, end);
		Merge(array, start, mid, end); //Merging the sorted sub arrays
	}
}

//Function to merge the two arrays
void Merge(int array[], int p, int q, int r) {
    int sizeOfLeftArray = q - p + 1;
	int sizeOfRightArray = r - q;

	//Declaring left and right arrays dynamically to store the sub arrays
	int * L = new int [sizeOfLeftArray + 1];
	int * R = new int [sizeOfRightArray + 1];

	
	for (int i = 0; i < sizeOfLeftArray; i++) {
		L[i] = array[p + i];
	}

	for (int i = 0; i < sizeOfRightArray; i++) {
		R[i] = array[q + i + 1];
	}

	int i = 0, j = 0;
	L[sizeOfLeftArray] = 10000031;
	R[sizeOfRightArray] = 10033001;

	//Storing back in the original array 
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i = i + 1;
		}
		else {
			array[k] = R[j];
			j = j + 1;
		}
	}

	//deleting dynamically allocated array
	delete[] L;
	delete[] R;
}
