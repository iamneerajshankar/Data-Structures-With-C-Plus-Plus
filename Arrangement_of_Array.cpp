#include <iostream>

using namespace std;

// with time complexity O(n * log n) and Auxiliary Space: O(n) 
class RearrangingTheArray1
{

public:
    void printArry(int arr[], int n)
    {
        int i = 0;
        while (i < n)
        {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1; // pointing index just after pivot
        int j = high;    // last index of the array
        int temp;

        do
        {
            // keep looking for greater element than pivot
            while (arr[i] <= pivot)
            {
                i++;
            }
            // keep looking for smaller element than pivot
            while (arr[j] > pivot)
            {
                j--;
            }

            // if the i and j has not crossed each other, swap arr[i] and arr[j]
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        } while (i < j);

        // when i and j becomes eaqual or crosses each other, swap arr[low] and arr[j]
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        return j;
    }
    void quickSort(int arr[], int low, int high)
    {
        int partition_index;
        if (low < high)
        {
            partition_index = partition(arr, low, high);
            // sort the left sub array
            quickSort(arr, low, partition_index - 1);
            // sort the right subarray.
            quickSort(arr, partition_index + 1, high);
        }
    }

    void MinMaxOrderArrangement(int arr[], int n)
    {
        int resultant[n];
        int min_item = 0;
        int max_item = n - 1;

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 == 0)
            {
                // put the elements at  even index place
                resultant[i] = arr[max_item--];
            }
            else
            { // put the elements at odd  index place
                resultant[i] = arr[min_item++];
            }
        }

        cout << "The Arrays arranged in first min and then max order: ";
        for (int i = 0; i < n; i++)
        {
            cout << resultant[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    int arr[] = {5, 8, 1, 4, 2, 9, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

   RearrangingTheArray1 object;

    cout << "****************************************************" << endl;
    cout << "The given array: ";
    object.printArry(arr, n);
    cout << "\n****************************************************" << endl;
    cout << "The sorted array with help of quick sort: ";
    object.quickSort(arr, 0, n - 1);
    object.printArry(arr, n);
    cout << "\n****************************************************" << endl;
    object.MinMaxOrderArrangement(arr, n); 
   
}