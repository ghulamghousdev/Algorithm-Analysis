/*
2018-CS-31
Ghulam Ghous
Program Description:
			In this program we have successfully implemented Activity Selection
			problem algorithm using a dynamic approach.
*/

#include <iostream>
using namespace std;

//Declaring a struct to store total number of activities selected
struct arr {
	int noOfActivitiesSelected;
};

//Function prototype
int* ActivitySelectionDynamic(int startTime[], int finishTime[], int totalActivities);
void printActivities(int arr[], int size);
arr obj;

int main() {
	//Input values
	int startTime[] = { 0, 2, 5, 7, 11 }; 
	int finishTime[] = { 3, 6, 8, 12, 14 };
	int totalActivities = sizeof(finishTime) / sizeof(finishTime[0]); //Calculating total activities

	//Calling function to calculate max no of activities that a man or machine can perform
	int* actSelected = ActivitySelectionDynamic(startTime, finishTime, totalActivities);

	//Printing the selected activities
	cout << "The total number of selected activities are: " << obj.noOfActivitiesSelected << endl;
	cout << "The selected activities are: ";
	printActivities(actSelected, obj.noOfActivitiesSelected);

	return 0;
}


//Function defination which calculates max no of activities that a man or machine can perform
int* ActivitySelectionDynamic(int startTime[], int finishTime[], int totalActivities) {
	
	int i, j;
	int max = 0;
	int* selectedActivities = new int[totalActivities];
	int* maxAct = new int[totalActivities];

	//Filling the array with 1
	for (i = 0; i < totalActivities; i++) {
		maxAct[i] = 1;
	}

	//Checking all possible combinations to compute max value
	for (i = 1; i < totalActivities; i++) {
		for (j = 0; j < i; j++) {
			if ((startTime[i] > finishTime[j]) && (maxAct[i] < (maxAct[j] + 1))) {
				maxAct[i] = maxAct[j] + 1;
			}
		}
	}

	j = 0;
	///Pick maximum of all maximum number of activities  values
	for (i = 0; i < totalActivities; i++)
		if (max < maxAct[i]) {
			max = maxAct[i];
			selectedActivities[j] = i+1;
			j++;
		}
	obj.noOfActivitiesSelected = j;

	return selectedActivities;
}


void printActivities(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "a" << arr[i] << "  ";
	}
	cout << endl << endl;
}