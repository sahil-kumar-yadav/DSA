#include <iostream>

using namespace std;
int R = 5, C = 5;
void printArr(int arr[5][5], int n, int m)
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

void SpiralPrint(int arr[5][5], int n, int m)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    // spriral movement  -->
    // 1. go right (left to right)
    // 2. go bottom (top to bottom)
    // 3. go left (right to left)
    // 4. go up (bottom to up)

    while (top <= bottom && right >= left)
    {

        // 1. go right (left to right)
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;
        // 2. go bottom (top to bottom)
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;
        // 3. go left (right to left)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
        }
        bottom--;
        // 4. go up (bottom to up)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
        }
        left++;
    }
}

int main()
{
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int n = 5, m = 5;
    printArr(arr, n, m);
    cout << endl;
    SpiralPrint(arr, n, m);
    // 1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13

    return 0;
}