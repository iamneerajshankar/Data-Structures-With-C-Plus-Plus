/*
* A java program to demonstrate the bubble sort algorithm - With bubble sort,
* we intend to ensure that the largest element of the segment reaches the last
* position at each iteration.

*Time Complexity of the bubble sort algorithm is O(n2).
*It is a stable algorithm, because it preserves the order of equal elements.
*It is not a recursive algorithm.
*Bubble sort is not adaptive by default, but can be made adaptive by modifying the program.
* */

#include <stdio.h>

using namespace std;

// method to traverse and print array elements
void printArray(int n, int arr[])
{
    int i = 0;
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void bubbleSort(int n, int arr[])
{
    int temp;
    // outer loop to visit each element
    for (int i = 0; i < n; i++)
    {
        // inner loop for number passes
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int n, int arr[])
{
    int temp;
    bool isSorted = false;
    int pass_no = 0;
    // outer loop to visit each element
    for (int i = 0; i < n; i++)
    {
        isSorted = true;
        pass_no = pass_no + 1;
        // inner loop for number passes
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                isSorted = false; // if loop enters if statment, then array is not sorted
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (isSorted)
        {
            printf("Total passes taken: %d\n", pass_no);
            return; // if the array is already sorted, exit the loop
        }
    }
}

int main()
{
    printf("Please enter the number of elements: ");
    int n = 7;
    int arr[n] = {9, 14, 4, 8, 7, 5, 6};
    //int arr[n] = {1, 2, 3, 4, 5, 6, 7};

    printf("The array elements before sorting: ");
    printArray(n, arr);

    // bubbleSort(n, arr);
    bubbleSortAdaptive(n, arr);
    printf("The array elements after sorting: ");
    printArray(n, arr);
}