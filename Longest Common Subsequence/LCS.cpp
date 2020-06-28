#include <iostream>;
using namespace std;


//Declaring constructor to use it to return arrays from LCS_Length function
struct arrayInitilizer {

	int** traceArray;
	int** valueArray;
	int lengthOfLCS = 0;


	//initilizing 2D arrays using parameterized constructor
	arrayInitilizer(int lengthOfString1, int lengthOfString2) {

		traceArray = new int* [lengthOfString2];
		for (int i = 0; i <= lengthOfString2; i++)
			traceArray[i] = new int[lengthOfString1];

		valueArray = new int* [lengthOfString2 + 1];
		for (int i = 0; i <= lengthOfString2; i++)
			valueArray[i] = new int[lengthOfString1];
	}
};

//Function prototypes
arrayInitilizer LCS_Length(string string1, string string2);
void PrintLCS(int** traceArray, int m, int n, string a);



int main() {
	string string1, string2;
	string1 = "bdcaba";
	string2 = "abcbdab";
	int lengthOfString1 = string1.length(); 
	int lengthOfString2 = string2.length();

	//declaring object to store returned data from LCS_Length function
	arrayInitilizer obj(lengthOfString1, lengthOfString2); 
	obj = LCS_Length(string1, string2);
	
	//Printing Results
	cout << "The Longest common Subsequence is: ";
	PrintLCS(obj.traceArray, lengthOfString2, lengthOfString1, string2); //Printing the LCS
	cout << " with length of: " << obj.lengthOfLCS << endl;
	
	//Deallocating the memory
	for (int i = 0; i <= lengthOfString2; i++){
        delete[] obj.traceArray[i];
        delete[] obj.valueArray[i];
    }
    delete[] obj.traceArray;
    delete[] obj.valueArray;
    
    
	return 0;
}

arrayInitilizer LCS_Length(string string1, string string2) {

	int lengthOfString1, lengthOfString2;
	lengthOfString1 = string1.length();
	lengthOfString2 = string2.length();

	//declaring object of Struct arrayInitilizer
	arrayInitilizer obj(lengthOfString1, lengthOfString2);

	//Filling 2D Arrays 0th row and 0th column with 0's
	for (int i = 0; i <= lengthOfString1; i++) {
		obj.valueArray[0][i] = 0;
	}
	for (int i = 1; i <= lengthOfString2; i++) {
		obj.valueArray[i][0] = 0;
	}

	int i,j;
	i = 0;
	j = 0;
	for (i = 1; i <= lengthOfString2; i++) {
		for (j = 1; j <= lengthOfString1; j++) {

			if (string2[i-1] == string1[j-1]) {
				obj.valueArray[i][j] = (obj.valueArray[i - 1][j - 1]) + 1;
				obj.traceArray[i][j] = 1; //It means the trace is in upper left diagonal direction
			}
			else if (obj.valueArray[i][j - 1] > obj.valueArray[i - 1][j]) {
				obj.valueArray[i][j] = obj.valueArray[i][j - 1];
				obj.traceArray[i][j] = 3; //it means the trace is in left direction
			}
			else {
				obj.valueArray[i][j] = obj.valueArray[i - 1][j];
				obj.traceArray[i][j] = 2; //it means the trace is in upword direction
			}
		}

	}
	obj.lengthOfLCS = obj.valueArray[i - 1][j - 1];
	
	return obj;
}



//Function to print LCS
void PrintLCS(int** traceArray, int m, int n, string string1) {

	if (m == 0 || n == 0) { //base case if length of any string becomes 0, recursive calls will stop
		return;
	}


	if (traceArray[m][n] == 1) { //If value comes from upper left diagonal direction
		PrintLCS(traceArray, m - 1, n - 1, string1);
		cout << string1[m - 1];
	}


	else if (traceArray[m][n] == 2) { //when value comes from top box
		PrintLCS(traceArray, m - 1, n, string1);
	}


	else if (traceArray[m][n] == 3) { //when value comes from left box
		PrintLCS(traceArray, m, n - 1, string1);
	}
}
