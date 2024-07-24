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

void bubbleSort(int arr[], int n)
{

    // phele baar my 0 sy n-1 tak ja rahe hai
    // second time 0 - n-2
    // ..
    // 0 - 1

    // so we are going n-1 to 1

    for (int i = n - 1; i >= 1; i--)
    {
        // 0 sy i tak
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // wrong order
                swap(arr[j], arr[j + 1]);
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
    bubbleSort(arr, n);
    cout << "After sorting " << endl;
    printarr(arr, n);

    return 0;
}