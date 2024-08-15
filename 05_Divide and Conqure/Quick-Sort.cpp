#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int n, int s, int e)
{
    if (s < 0 || e > n)
        return;
    if (s >= e)
        return;

    cout << "Printing array" << endl;
    printArr(arr, n);
    int pivotIndex = partition(arr, s, e);
    cout << "pivot " << arr[pivotIndex] << endl;
    cout << "Printing array After Partion" << endl;
    printArr(arr, n);
    // cout<<"Piviot Index "<<pivotIndex<<endl;
    // left my quick Sort
    quickSort(arr, n, s, pivotIndex - 1);

    // right my quick Sort
    quickSort(arr, n, pivotIndex + 1, e);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    quickSort(arr, n, 0, n - 1);
    cout << "Printing Sorted array" << endl;
    printArr(arr, n);

    return 0;
}