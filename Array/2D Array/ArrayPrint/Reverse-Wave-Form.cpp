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

void ReverseWavePrint(int arr[4][4], int n, int m)
{
    int i = 0, j = m - 1;

    while (j >= 0)
    {
        if (j & 1)
        {
            // j odd // 1 3
            i = 0;
            while (i < n)
            {
                cout << arr[i][j] << " ";
                i++;
            }
        }
        else
        {
            // j is even 0 2 4
            i = n - 1;
            while (i >= 0)
            {
                cout << arr[i][j] << " ";
                i--;
            }
        }
        cout << endl;
        j--;
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
    ReverseWavePrint(arr, n, m);

    return 0;
}