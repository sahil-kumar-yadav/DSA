#include <iostream>

using namespace std;

int findMin(int arr[], int n, int i)
{
    if (i == n)
        return INT_MAX;

    // 1 case hum solve kar lete hai hai baki recursion sambhal lega
    int aagekaSolution = findMin(arr, n, i + 1);
    int mini = min(arr[i], aagekaSolution);

    return mini;
}

int main()
{
    // find minimum,maximum element in array using recursion
    int arr[] = {10, 30, 15, 21, 5, 26};
    int n = 6;
    int min = findMin(arr, n, 0);

    cout << "minimum element is " << min << endl;

    return 0;
}