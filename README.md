# Algorithm-Analysis
💻📚💻This repository consists of codes written during my undergraduate Design and Analysis of Algorithms course!

## Insertion Sort
-   Takes n^2 time complexity to sort the Array
-   Better for small sized arrays

## Merge Sort
-   Takes n(ln(n)) time complexity to sort the Array
-   Better for large sized arrays

## Hybrid Merge Sort
-   Hybrid version of Merge and Insertion sort algorithm to provide better results and time complexity
-   Sorts large sized arrays by **Merge Sort** until **Insertion Sort** Algorithm becomes more efficient and sorts the remaining small sized arrays by insertion sort algorithm

# BruteForce VS Recursive Algorithms

- ## Brute Force Algorithm
        MaxSubArrayRecord findMaxArrayBruteForce(int A[],int start, int end);
- ## Recursive AlgorithmMaxSubArrayRecord 
        FindMaxSubArrayRecursive(int A[], int start, int end);
        MaxSubArrayRecord CrossSum(int A[], int start, int mid, int end);
- ## Hybrid Recursive-BruteForce Algorithm
        MaxSubArrayRecord HybridMaxSubArray(int A[], int start, int end);
        MaxSubArrayRecord findMaxArrayBruteForce(int A[], int start, int end);
        MaxSubArrayRecord CrossSum(int A[], int start, int mid, int end);
