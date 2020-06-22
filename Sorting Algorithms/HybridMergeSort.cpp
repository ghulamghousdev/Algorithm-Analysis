#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <chrono>

using namespace std;

//Prototypes of the functions used in the program
void RandomArray(int array[], int size);
void HybridMergeSort(int array[], int start, int end);
void Merge(int array[], int p, int q, int r);
void InsertionSort(int array[], int start, int end);

int main() {

	ofstream outputFile;
	int SIZE;
	cout << "Enter the size of the array" << endl;
	cin >> SIZE;
	int* array = new int[SIZE];

	RandomArray(array, SIZE); //Generating random numbers 

	auto start = chrono::high_resolution_clock::now(); //storing starting time

	HybridMergeSort(array, 0, SIZE - 1); //sorting the array

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count(); //calculating time taken by the algorithm
	time_taken *= 1e-6;
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(10);


	outputFile.open("InsertionSort.csv");
	for (int i = 0; i < SIZE; i++) {
		outputFile << array[i] << endl;

	}
	outputFile.close();

	delete[] array;

	system("pause");
}

//Function to generate random numbers
void RandomArray(int array[], int size) { 
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		array[i] = rand();
	}
}

//Function to sort array
void HybridMergeSort(int array[], int start, int end) {
	if((end-start)>1250){ //condition tells when to call merge sort and when to insertion
		int mid = floor((start + end) / 2);
		HybridMergeSort(array, start, mid);
		HybridMergeSort(array, mid + 1, end);
		Merge(array, start, mid, end);
	}
	else {
		InsertionSort(array, start, end + 1);
	}
}

void Merge(int array[], int p, int q, int r) {
	int sizeOfLeftArray = q - p + 1;
	int sizeOfRightArray = r - q;

	int* L = new int[sizeOfLeftArray + 1];
	int* R = new int[sizeOfRightArray + 1];

	for (int i = 0; i < sizeOfLeftArray; i++) {
		L[i] = array[p + i];
	}

	for (int i = 0; i < sizeOfRightArray; i++) {
		R[i] = array[q + i + 1];
	}

	int i = 0, j = 0;
	L[sizeOfLeftArray] = 10000018;
	R[sizeOfRightArray] = 10000081;

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
	delete[] L;
	delete[] R;
}

void InsertionSort(int array[], int start, int end) {
	for (int j = start + 1; j < end; j++) {
		int key = array[j];
		int i = j - 1;
		while (i >= start && array[i] > key) {
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}