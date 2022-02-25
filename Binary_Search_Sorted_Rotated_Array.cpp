/**
 * @file Binary_Search_Sorted_Rotated_Array.cpp
 * @author Neeraj Shankar- codewithneeraj
 * @brief - Perform The Binary search on sorted rotated array.
 * @version 0.1
 * @date 2022-02-25
 * @Time Complexity: O(log n) and Space Complexity:O(1)
 * 
 */

#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int element ){
    int mid = (low + high)/2;

    // high cannot be less than low
    if(high<low){
        return -1;
    }

    //if element already found at mid
    if(arr[mid]==element){
        return mid;
    }

    //when the element at mid is less than required element, it must be in right side(mid+1)
    if(arr[mid]<element){
        return binarySearch(arr, mid+1, high, element);
    }

    //else
    return binarySearch(arr, low, mid-1, element);

}

//here pivot wil be the greatest number in array afer which smaller element exists
int searchPivot(int arr[], int low, int high){
    
    //base case
    if(high<low){
        return -1;
    }
    if(high==low){
        return low;
    }

    int mid = (low + high)/2;
    if(mid<high && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid>low && arr[mid]<arr[mid-1]){
        return mid-1;
    }

    if(arr[low]>=arr[mid]){
        return searchPivot(arr, low, mid-1);
    }

    //else
    return searchPivot(arr, mid+1, high);

}

//
int binarySearchUsingPivot(int arr[], int n, int element){
        int pivot = searchPivot(arr, 0, n-1);
        if(element == arr[pivot]){
            return pivot;
        }
        // if element is greater than or equal array at zero index, it must be before the pivot index
        if(element>=arr[0]){
                return binarySearch(arr, 0, pivot-1, element);
        }

        //else
        return binarySearch(arr, pivot+1, n-1, element);
}

int main(){
    int arr[] = {3,4,5,6,7,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element = 7;

    //call the binarySearchUsingPivot
   int foundAt = binarySearchUsingPivot(arr, n, element);
   cout<<"The element " <<element<< " found at the index "<<foundAt<<endl;;


    return 0;
}