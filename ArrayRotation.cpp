/**
 * @file ArrayRotation.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";

        i++;
    }
    cout << endl;
}

// By juggling method,  time complexity - O(n), space auxillary - O(1)
class ArrayRotation
{

public:
    int find_greatest_common_divisor(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return (b, a % b);
        }
    }

    // method to rotate by  finding common divisor method
    void leftRotationByGCD(int arr[], int n, int k)
    {
        int gcd = find_greatest_common_divisor(n, k);
        int d = -1, j;
        int temp;

        for (int i = 0; i < gcd; i++)
        {
            temp = arr[i];
            j = i;

            while (1)
            {
                int d = (j + k)%n;
                if (d == i)
                {
                    break;
                }

                arr[j] = arr[d];
                j = d;
            }
            arr[j] = temp;
        }
    }
};

// By one by one rotation,  time complexity - O(n*d), space auxillary - O(1)
class ArrayRotation2
{
public:
    void leftRotateByOne(int arr[], int n)
    {
        int i = 0;
        int temp = arr[i];
        while (i < n - 1)
        {
            arr[i] = arr[i + 1];
            i++;
        }
        arr[i] = temp;
    }

    void leftRotateByFactor(int arr[], int n, int d)
    {
        for (int i = 0; i < d; i++)
        {
            leftRotateByOne(arr, n);
        }
    }
};

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotate_by_factor = 3;

    cout << "****************************************************" << endl;
    ArrayRotation ob;
    cout<<"The array before rotation: ";
    printArray(arr, size);
    cout<<"The after the ratation by factor "<<rotate_by_factor<<"is: ";
    ob.leftRotationByGCD(arr, size, rotate_by_factor);
      printArray(arr, size);

    cout << "****************************************************" << endl;
    ArrayRotation2 ob2;
    cout << "The array before rotation: ";
    printArray(arr, size);
    cout << "The after the ratation by factor " << rotate_by_factor << " is: ";
    ob2.leftRotateByFactor(arr, size, rotate_by_factor);
    printArray(arr, size);
    
}