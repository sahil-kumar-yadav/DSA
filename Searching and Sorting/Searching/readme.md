# Binary Search

## Recursive
```cpp
int BinarySearchRecursive(vector<int> &arr, int target, int start, int end)
{
    // base case
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    int ans = -1;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        start = mid + 1;
        ans = BinarySearchRecursive(arr, target, start, end);
    }
    else
    {
        // arr[mid] > target
        end = mid - 1;
        ans = BinarySearchRecursive(arr, target, start, end);
    }

    return ans;
}
```

## Iterative
```cpp
bool BinarySearchIterative(int arr[], int n, int target)
{
    int start = 0, end = n - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        cout << "start " << start << " mid " << mid << " end " << end << endl;

        if (arr[mid] == target)
        {
            return true;
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

    return false;
}
```

## first and last position of element in sorted array

```cpp
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
```


# magic number
```cpp
int BS(vector<int> arr, int n)
{
    int ans = -1;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == mid)
        {
            ans = mid;
            // return true
            end = mid - 1;
            // break;
        }
        else if (arr[mid] < mid)
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

    return ans;
}
```

## Find Pivot number
```cpp
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
```

# search in sorted and rotated array
```cpp
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
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

int BS(int arr[], int start, int end, int target)
{
    int mid = (start + end) / 2;
    while (start <= end)
    {
        // cout << "start " << start << " mid " << mid << " end " << end << endl;

        if (arr[mid] == target)
        {
            return mid;
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

    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    int pivotIndex = findPivot(arr, n);
    cout << "pivotIndex " << pivotIndex << endl;
    int target = 0;
    if (target <= arr[pivotIndex] && target >= arr[0])
    {
        // 0 to pivot element vale search space my search karna hai
        int start = 0, end = pivotIndex;
        int ans = BS(arr, start, end, target);
        if (ans >= 0)
        {
            cout << "ans found at " << ans << endl;
        }
        else
        {
            cout << "ans not found" << endl;
        }
    }
    else
    {
        // pivot element to end vale search space my search karna hai
        cout << "else" << endl;
        int start = pivotIndex + 1, end = n - 1;
        int ans = BS(arr, start, end, target);
        if (ans >= 0)
        {
            cout << "ans found at " << ans << endl;
        }
        else
        {
            cout << "ans not found" << endl;
        }
    }

    // int *ptr = arr;
    // ptr = ptr + pivotIndex;
    // cout << "printing ptr+pivot" << endl; // karke dekho
    // cout << *ptr << endl;
    // if (target <= arr[pivotIndex] && target >= arr[0])
    // {
    //     // 0 to pivot element vale search space my search karna hai
    //     int ans = lower_bound(arr, arr + pivotIndex, target) - arr;
    //     if (ans)
    //     {
    //         cout << "ans found at 1 " << ans << endl;
    //     }
    //     else
    //     {
    //         cout << "ans not found 1" << endl;
    //     }
    // }
    // else
    // {
    //     int ans = lower_bound(arr + (pivotIndex + 1), arr + n, target) - (arr + (pivotIndex + 1)); // using stl in algorithms lib
    //     if (ans)
    //     {
    //         cout << "ans found at 2 " << ans << endl;
    //     }
    //     else
    //     {
    //         cout << "ans not found 2" << endl;
    //     }
    // }

    return 0;
}hi
```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```


```cpp

```



