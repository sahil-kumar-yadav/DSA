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

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int miniIndex = i;
        // get the minimum index
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[miniIndex])
            {
                miniIndex = j;
            }
        }
        // swap with current index
        swap(arr[i], arr[miniIndex]);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    cout << "before sorting " << endl;
    printarr(arr, n);
    selectionSort(arr,n);
    cout << "after sorting " << endl;
    printarr(arr, n);

    return 0;
}
