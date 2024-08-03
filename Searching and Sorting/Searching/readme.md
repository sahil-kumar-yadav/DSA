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


```cpp

```



