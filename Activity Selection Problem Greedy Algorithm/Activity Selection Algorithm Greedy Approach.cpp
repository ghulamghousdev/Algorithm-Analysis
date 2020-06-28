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
struct noOfActSelected {
	int noOfActivitiesSelected;
};


//Function prototype
int* activitySelectorGreedy(int startTime[], int finishTime[], int act[], int noOfActivities);
void printActivities(int arr[], int size);
noOfActSelected obj;


int main() {

	//Input values
	int startTime[] = { 0, 2, 5, 7, 11 };
	int finishTime[] = { 3, 6, 8, 12, 14 };
	int noOfActivities = sizeof(finishTime) / sizeof(finishTime[0]);
	int act[] = { 1, 2, 3, 4, 5};
	
	//Calling function to calculate max no of activities that a man or machine can perform
	int * resultArray = activitySelectorGreedy(startTime, finishTime, act, noOfActivities);
	
	//Printing the selected activities	
	cout << "The total number of selected activities are: " << obj.noOfActivitiesSelected << endl;
	cout << "The selected activities are: " ;
	printActivities(resultArray, obj.noOfActivitiesSelected);

	return 0;
}


//Function defination which calculates max no of activities that a man or machine can perform
int* activitySelectorGreedy(int startTime[], int finishTime[], int act[], int noOfActivities) {

	int currentActivity, totalSelectedActivities, i = 0, m=0;
	int* selectedActivities = new int [noOfActivities];
	selectedActivities[i] = act[m]; //Selecting the for activity
	i++;
	currentActivity = act[m]-1;


	//Selecting the activities
	for (m = 1; m < noOfActivities; m++) {

		if (startTime[m] >= finishTime[currentActivity]) {
			selectedActivities[i] = act[m]; //Storing it in an array
			currentActivity = m;
			i++;
		}
		
	}

	//returning the computed results
	obj.noOfActivitiesSelected = i;
	return selectedActivities;
}


//Function to Print the selected activities
void printActivities(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "a" << arr[i] << "  ";
	}
	cout << endl << endl;
}