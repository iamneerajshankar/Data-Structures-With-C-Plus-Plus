/*
* A java program to demonstrate Insertion sort. In Insertion sort, we pluck an element
* from the array and place it to its right place.

* Time Complexity of the insertion sort algorithm is O(n2) in the worst case and O(n)
* in the best case.
*
* It is a stable algorithm since it preserves the order of equal elements.
*
* It is not a recursive algorithm.
*
* Insertion sort is adaptive by default and no extra effort is needed to make it adaptive.
* The time complexity itself gets reduced from O(n2) to O(n) when the algorithm finds an
* array already sorted.
* */

#include<stdio.h>

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

void InsertionSort(int n, int arr[]){
    int key;
    int j;
    for(int i=1; i<n; i++){
        key = arr[i];
        j= i-1;

        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}

int main(){
    int n = 7;
    int arr[n] = {9, 14, 4, 8, 7, 5, 6};
    //int arr[n] = {1, 2, 3, 4, 5, 6, 7};

    printf("The array elements before sorting: ");
    printArray(n, arr);

    InsertionSort(n, arr);
    printf("The array elements after sorting: ");
    printArray(n, arr);

    return 0;
}