//Libraries
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <chrono>
using namespace std;
// We use this record to be returned by the function  that finds
// the maximum sub-array.
struct MaxSubArrayRecord 
{
	// Holds the starting index of the sub-array.
	int startIndex=0;
	// Holds the ending index of the sub-array.
	int endIndex=0;
	// Holds the sum of all the elements within  the  sub-array.
	int maxSum=0;
};
//ProtoTypes of functions used in the Program
void RandomArray(int array[], int size);
MaxSubArrayRecord findMaxArrayBruteForce(int A[],int start, int end);


int main() {
	
	MaxSubArrayRecord obj;
	ofstream outputFile;
	int SIZE;
	cout << "Enter number of integers" << endl;
	cin >> SIZE;
	int* array = new int[SIZE];

	//Generating Random integers
	RandomArray(array, SIZE);


	auto start = chrono::high_resolution_clock::now(); //Variable to store starting time

	obj = findMaxArrayBruteForce(array, 0,SIZE-1); 
	
	auto end = chrono::high_resolution_clock::now(); 
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(10)<<endl;

	//Storing the sorted array in the file
	outputFile.open("BruteForce.csv");
	for (int i = 0; i < SIZE; i++) {
		outputFile << array[i] << endl;

	}
	outputFile.close();

	

	cout << "Start index " << obj.startIndex << endl;
	cout << "End index " << obj.endIndex << endl;
	cout << "Max Sum " << obj.maxSum<<endl;

	//deleting the dynamically allocated array
	delete[] array;
	system("pause");
	return 0;
}


//Function to generate random numbers
void RandomArray(int array[], int size) {
	srand(time(0));
	int var;
	for (int i = 0; i < size; ++i) {
		var = rand() % 1000000;
		if ((var % 2) != 0) {
			var = var * (-1);
		}
		array[i] = var;
	}
}

//Brute force algorithm to find max sub array
MaxSubArrayRecord findMaxArrayBruteForce(int A[], int start, int end)
{
	int size = (end - start) + 1;
	if(size>1){ //when size of array is greater then 1
	int maxSum = -99999999;
	int low;
	int high;
	
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = i; j < size; j++) 
		{
			sum = sum + A[j];
			if (sum > maxSum)
			{
				maxSum = sum;
				low = i;
				high = j;
			}
		}
	}

		//Storing calculated values in the object we want to return
		MaxSubArrayRecord result;
		result.startIndex = low;
		result.endIndex = high;
		result.maxSum = maxSum;
		return result;
		}
		//Storing calculated values in the object when array contains only 1 elelment
		MaxSubArrayRecord obj;
		obj.startIndex = start;
		obj.endIndex = end;
		obj.maxSum = A[start];
		return obj;
		
	}
