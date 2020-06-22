#include <iostream>
using namespace std;

//Variable to store number of function calls
int functionCalls = 0;

//Prototypes of the functions used in the program
int cutRodMax(int array[], int lengthOfTheRod);
int max(int a, int b);


int main()
{
	int arr[10] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int lengthOfRod;
	cout << "Enter the length of Rod you want to sell" << endl;
	cin >> lengthOfRod;

	int maxRevenue = cutRodMax(arr, lengthOfRod);
	cout << "MaxRevenue is " << maxRevenue << " of ROD having length " << lengthOfRod << endl;
	cout << "Number Of Function Calls " << functionCalls << endl;
	return 0;
}

//Function to get the maximum of two integers 
int max(int a, int b)
{ 
	if (a > b)
		return a;
	else
		return b;
}

//Function which returns the max revenue on given length of the rod
int cutRodMax(int array[], int lengthOfTheRod)
{
	functionCalls++; //Incrementing the value of function calls on each call

	if (lengthOfTheRod <= 0) //base case when length of rod becomes equal to zero
	{
		return 0;
	}

	int maxValue = -9999999;  //declarijng a variable to store the max value

	for (int i = 0; i < lengthOfTheRod; i++)
	{
		maxValue = max(maxValue, array[i] + cutRodMax(array, lengthOfTheRod - i - 1));
	}
	
	return maxValue;
}