/*
A CPP program to find the subarray with least average.

We are given an array of size n and integer say 'k' such that k is always less than or equal to n

Here: k is the length of subarray and we have to return the first and last index of subarray which
has minimum averge.
*/

#include <iostream>
#include <climits>

using namespace std;

void least_average(int arr[], int n, int k)
{

    int start_index = 0; // initialize start index to 0

    int curr_sum = 0; // initialize the curr sum. It stores the curr_sum of running iteration
    for (int i = 0; i < k; i++)
    { // here k =3
        curr_sum += arr[i];
    }

    // initiaze min_sum and store value fo curr_sum
    int min_sum = curr_sum;

    // start the loop from where first loop ends - ie- after first subarray formed
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k]; // add the value of next element and subtract first element  value

        if (curr_sum < min_sum)
        {
            min_sum = curr_sum;
            start_index = i - k + 1; // index of subarray with min sum as current itration
        }
    }

    cout << "The index range of least average subarray " << start_index << ", " << start_index + k - 1 << endl;
}

void least_average2(int arr[], int n, int k)
{
    int start_index = 0;
    int min_sum = INT_MAX;
    int curr_sum = 0;
    int item_count = 0;

    for (int i = 0; i < n; i++)
    {

        curr_sum += arr[i];
        item_count++;
        // once the count element in subarray reaches k
        if (item_count == k)
        {
            // if min_sum is greater than curr_sum update the value of min index
            if (min_sum > curr_sum)
            {
                min_sum = curr_sum;
                start_index = i - k + 1;
            }
            // everytime count equals k reducce it by 1
            item_count--;
            curr_sum -= arr[i - k + 1]; // subtract first element  value
        }
    }
    

    cout << "The index range of least average subarray " << start_index << ", " << start_index + k - 1 << endl;
}


int main()
{
    int arr[] = {3, 7, 90, 20, 10, 50, 40};
    // int arr2[] = {14, 43, 10, 3, 40, 34, 40};

    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    least_average(arr, len, k);
    least_average2(arr, len, k);
}