/*
* QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions 
* the given array around the picked pivot. 
* The partition method in sorting. In the partition method, we choose an element as a pivot and 
* try pushing all the elements smaller than the pivot element to its left and all the greater elements to its right. 

*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

//method to traverse and print array elements
int print_array(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    return 0;
}

// create a partition method returning partionIndex for the subarrays.
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        //loop runs through until we get a greater element than pivot from left to right
        while (arr[i] <= pivot)
        {
            i++;
        }

        //loop runs through until we get a smaller element than pivot from right to left
        while (arr[j] > pivot)
        {
            j--;
        }

        //till, i and j did not cross each other, exchane these elements.
        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);

    //once,i and j crosses each other swap element at low and element j 
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return j; // i becomes next point of partition
}
int quick_sort(int arr[], int low,int high){

    int partitionIndex;
    if(low<high){
        partitionIndex = partition(arr, low, high);
        quick_sort(arr, low, partitionIndex-1); // sorts first subarray
        quick_sort(arr, partitionIndex+1, high);// sorts second subarray
    }
    return 0;
}

int main(){
    // int arr[n] = {9, 14, 4, 8, 7, 5, 6};
    //int arr[n] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {1, 2, 3, -4, 5, -6, 7, -2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

     printf("The array elements before sorting: ");
    print_array(arr,n);

    quick_sort(arr, 0, n-1);
    printf("The array elements after sorting: ");
    print_array(arr, n);

    return 0;
}
