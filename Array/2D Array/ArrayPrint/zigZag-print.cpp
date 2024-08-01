#include <iostream>

using namespace std;

void printArr(int arr[4][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void zigZagPrint(int arr[4][4], int n, int m)
{
    int i = 0, j = 0;

    while (i < n)
    {
        if (i & 1)
        {
            // j odd // 1 3
            j = m - 1;
            while (j >= 0)
            {
                cout << arr[i][j] << " ";
                j--;
            }
        }
        else
        {
            // j is even 0 2 4
            j = 0;
            while (j < n)
            {
                cout << arr[i][j] << " ";
                j++;
            }
        }
        cout << endl;
        i++;
    }
}

int main()
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int n = 4, m = 4;
    printArr(arr, n, m);
    cout << endl;
    zigZagPrint(arr, n, m);

    return 0;
}