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

