/*
 * A C- program program to show insertion of element in an already existing array
 * An element can be inserted in an array at a specific position. For this operation to succeed,
 * the array must have enough capacity.
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

int InsertAtIndex(int arr[], int size, int capacity, int index, int element){
    for(int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;

    return 0;
}

int main()
{
    int capacity = 100;
    int arr[capacity] = {9, 14, 4, 8, 7, 5, 6};
    int size = 7;
    int index = 4;
    int element = 20;
    printf("The array elements before sorting: ");
    printArray(size, arr);

    InsertAtIndex(arr, size, capacity, index, element);
    printf("The array elements after insertion: ");
    size =size+1;
    printArray(size, arr);
}