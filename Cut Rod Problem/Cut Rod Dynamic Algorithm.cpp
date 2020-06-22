#include <iostream>
using namespace std;

//Global variable to store function calls in dynamic cut rod algorithm
int functionCallsDynamic = 0;

//Prototypes of the functions used in the program
int cutRodAI(int priceArray[], int lengthOfRod);
int cutRodAUX(int priceArray[], int tempArray[], int lengthOfRod);
int main()
{
	int priceArray[10] = { 1,5,8,9,10,17,17,20,24,30 }; //Array containing the price of rod on different lengths
	int lengthOfRod; 
	cout << "Enter the length of Rod you want to sell" << endl;
	cin >> lengthOfRod;

	int maxRevenue = cutRodAI(priceArray, lengthOfRod); //calling fucntion to find max revenue
	cout << "MaxRevenue is  " << maxRevenue << "  of ROD having length " << lengthOfRod << endl;
	cout << "Number Of Function Calls " << functionCallsDynamic << endl;
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

//Function to find max revenue using dynamic memory and memorization
int cutRodAUX(int priceArray[], int tempArray[], int lengthOfRod)
{
	functionCallsDynamic++; //Incrementing the value of function calls on each call
	if (tempArray[lengthOfRod - 1] >= 0)
		return tempArray[lengthOfRod - 1];

	int maxValue; //variable to store max value
	if (lengthOfRod <= 0) 
		maxValue = 0;
	else
	{
		maxValue = -1;
		for (int i = 0; i < lengthOfRod; i++) 
		{
			maxValue = max(maxValue, (priceArray[i] + cutRodAUX(priceArray, tempArray, lengthOfRod - i - 1))); 
		}
	}

	tempArray[lengthOfRod - 1] = maxValue;
	return	maxValue;
}

//Function to find max revenue using dynamic memory
int cutRodAI(int priceArray[], int lengthOfRod)
{
	int *tempArray = new int[lengthOfRod];
	for (int i = 0; i < lengthOfRod; i++) tempArray[i] = -1;
	return cutRodAUX(priceArray, tempArray, lengthOfRod);
}