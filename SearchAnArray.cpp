/**
 * @brief - Linear search method searches for an element by visiting all the elements sequentially 
 * until the element is found or the array finishes. It follows the array traversal method.
 * This search method searches for an element by breaking the search space into half each 
 * time it finds the wrong element. This method is limited to a sorted array. 
 * @file SearchAnArray.cpp
 * @author Neeraj Shankar - codewithneeraj@outlook.com
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

// Time complexity - O(n), Space Auxillary- O(1)
int linearSearch(int arr[], int size, int element){
    int i =0;
    for(int i=0;i<size;i++){
        if(arr[i]== element){
            return i;
        }
    }
    return -1;
}

// Time complexity - O(log(n)), Space Auxillary- O(1)
int binarySearch(int arr[], int size, int element){
    int low =0;
    int high =size-1;
    int mid;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }

        if(arr[mid]<element){
            low =  mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element =6;

    int searchIndex = binarySearch(arr, size, element);
    cout<<"The element found "<<element<<" found at the index "<<searchIndex<<endl;
}