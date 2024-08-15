#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setRowAndColZero(vector<vector<int>> &arr, int row, int col)
{

    // row to zero
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < m; i++)
    {
        arr[row][i] = 0;
    }
    // col zero
    for (int i = 0; i < n; i++)
    {
        arr[i][col] = 0;
    }
}

void setRowAndCol(vector<vector<int>> &arr, int row, int col)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < m; i++)
    {
        if (arr[row][i] != 0)
        {
            arr[row][i] = -1;
        }
    }
    // col zero
    for (int i = 0; i < n; i++)
    {
        if (arr[i][col] != 0)
        {
            arr[i][col] = -1;
        }
    }
}

void setMatrixmethod1(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    // if any element is zero set all its row and col to zero
    // m-1 create a new array

    vector<vector<int>> ans1(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                setRowAndColZero(ans1, i, j);
            }
        }
    }

    // copy karna hai

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = ans1[i][j];
        }
    }
}

void setMatrixmethod2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    // if any element is zero set all its row and col to zero
    // m-1 create a new array

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                setRowAndCol(v, i, j);
            }
        }
    }

    
    // abh jaha jaha -1 laga hai vaha 0 kardo
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    cout << "befor " << endl;
    printArr(v);
    // setMatrixmethod1(v);
    setMatrixmethod2(v);
    cout << "After " << endl;
    printArr(v);

    //other methos 
    // # store index in pair in stack or queue or array 
    // 

    return 0;
}