#include <iostream>

using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int arr[], int n)
{
    // pick each and every element
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            // piche ki or jana hai
            if (arr[j - 1] > arr[j])
            {
                // swap
                swap(arr[j - 1], arr[j]);
            }
            else
            {
                // sabh correct order my hai no need to go more back
                break;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    cout << "before sorting " << endl;
    printarr(arr, n);
    InsertionSort(arr, n);
    cout << "After sorting " << endl;
    printarr(arr, n);

    return 0;
}