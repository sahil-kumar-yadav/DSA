#include <iostream>

using namespace std;

int findPivot(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    // 4 , 5 , 6 , 7 , 0 , 1 , 2
    // 0   1   2   3  4    5   6
    while (start <= end)
    {
        cout << "start " << start << " mid " << mid << " end " << end << endl;
        if (mid + 1 <= end && arr[mid] > arr[mid + 1])
        {
            // peak element will be in left side
            return mid;
        }
        if (arr[mid] < arr[start])
        {
            // peak element will be in left side
            end = mid - 1;
        }
        else
        {
            // arr[mid] > arr[start]
            // peak element will be in left side
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    return mid;
}

int main()
{
    int arr[] = {12, 10, 2, 4, 6, 8};
    int n = 6;
    findPivot(arr, n);

    return 0;
}