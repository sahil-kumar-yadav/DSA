#include <iostream>
#include <vector>

using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int s, int e)
{
    
    int mid = (s + e) / 2;
    int len1 = (mid - s) + 1;
    int len2 = e - mid;

    int *leftArray = new int[len1];
    int *rightArray = new int[len2];

    // copy into left
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        leftArray[i] = arr[k];
        k++;
    }
    // copy into right
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        rightArray[i] = arr[k];
        k++;
    }


    // merge

    int LI = 0;
    int RI = 0;
    int MI = s;

    while (LI < len1 && RI < len2)
    {
        if (leftArray[LI] < rightArray[RI])
        {
            arr[MI++] = leftArray[LI++];
        }
        else
        {
            arr[MI++] = rightArray[RI++];
        }
    }

    // left ka bacha hua part
    while (LI < len1)
    {
        arr[MI++] = leftArray[LI++];
    }

    // right ka bacha hua part
    while (RI <  len2)
    {
        arr[MI++] = rightArray[RI++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }
    
    
    int mid = (start + end) / 2;

    // left array sort
    
    mergeSort(arr, start, mid);

    // right array sort
    mergeSort(arr, mid + 1, end);

    // 2 sorted array hai unko merge karna hai
    merge(arr, start, end);
}

int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    mergeSort(arr, 0, n-1);

    cout << "printing final array " << endl;
    printArr(arr,n);

    return 0;
}