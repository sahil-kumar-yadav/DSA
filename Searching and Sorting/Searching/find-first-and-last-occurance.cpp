#include <iostream>
#include <vector>
using namespace std;

int BinarySearchIterative(int arr[], int n, int target, bool flag)
{
    int ans = -1;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        // cout << "start " << start << " mid " << mid << " end " << end << endl;

        if (arr[mid] == target)
        {
            ans = mid;
            // return true
            if (flag)
            {
                // flag true for first occ
                end = mid - 1; // first occurance
            }
            else
            {
                // flag false for last occ
                start = mid + 1; // last occurance
            }
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            // arr[mid] > target
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    // return false;
    cout << "printing ans " << endl;
    return ans;
}

int main()
{
    int arr[] = {1, 3, 4, 4, 4, 4, 6, 7, 9};
    int n = 9;
    int firstOcc = BinarySearchIterative(arr, n, 4, true);
    int lastOcc = BinarySearchIterative(arr, n, 4, false);

    cout << "firstOcc " << firstOcc << endl;
    cout << "lastOcc " << lastOcc << endl;

    return 0;
}