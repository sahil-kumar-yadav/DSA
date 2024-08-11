#include <bits/stdc++.h>

using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void findStockSpanBrouteForce(int arr[], int n)
{
    int spanArr[7] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        cout << arr[i] << " -> ";
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                cout << arr[j] << " ";
                count++;
            }
            else
            {
                break;
            }
        }
        spanArr[i] = count;
        cout << endl;
    }

    printarr(spanArr, n);
}

void findStockSpanOptimized(int arr[], int n)
{
    int spanArr[7] = {0};

    for (int i = 0; i < n; i++)
    {
        // do something
    }
}

int main()
{

    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;

    findStockSpanBrouteForce(arr, n);
    findStockSpanOptimized(arr, n);

    return 0;
}