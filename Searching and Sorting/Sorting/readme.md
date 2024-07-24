# Bubble Sort

```cpp

```

# Insertion Sort

```cpp

```

# Selection Sort

- what to select --> minimum 
- algorithm is all about get the minumum and swap it
- in 1 step or 1 iteration we will have least minmum at the starting 
- so we n-1 step to sort complete array , because remaing 1 element will be automatically sorted

![alt text](image.png)

```cpp

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


```

# Quick Sort
```cpp

```

# Heap Sort
```cpp

```

```cpp

```

