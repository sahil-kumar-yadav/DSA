#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int s, int e)
{
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++, e--;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int s = 2, e = 3;

    reverse(arr, s, e);

    printArray(arr, n);

    return 0;
}