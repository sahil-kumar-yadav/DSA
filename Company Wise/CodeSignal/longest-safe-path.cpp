#include <iostream>
#include <vector>

using namespace std;

bool checkMove(int currRow, int CurrCol, vector<vector<int>> &space)
{

    if (currRow > space.size() || currRow < 0 || CurrCol > space[0].size() || CurrCol < 0)
    {
        return false;
    }

    // check karlo laser affected area to nahi hai

    if (space[currRow][CurrCol] == 0)
    {
        return false;
    }
    return true;
}

int findLongestPath(int currRow, int CurrCol, vector<vector<int>> &space)
{
    bool check = checkMove(currRow, CurrCol, space);

    if (!check)
        return INT_MIN;

    // check down movement possible
    check = checkMove(currRow + 1, CurrCol, space);
    int down = INT_MIN;

    if (check)
    {
        down = findLongestPath(currRow + 1, CurrCol, space);
        if (down != INT_MIN)
        {
            down += 1;
        }
    }

    // left jake check kara
    check = checkMove(currRow, CurrCol + 1, space);
    int left = INT_MIN;
    if (check)
    {
        left = findLongestPath(currRow, CurrCol + 1, space);
        if (left != INT_MIN)
        {
            left += 1;
        }
    }

    int right = INT_MIN;
    check = checkMove(currRow, CurrCol - 1, space);
    if (check)
    {
        right = findLongestPath(currRow, CurrCol - 1, space);
        if (right != INT_MIN)
        {
            right += 1;
        }
    }

    int up = INT_MIN;
    check = checkMove(currRow - 1, CurrCol, space);
    if (check)
    {
        up = findLongestPath(currRow - 1, CurrCol, space);
        if (up != INT_MIN)
        {
            up += 1;
        }
    }

    return max(down, max(left, max(right, up)));
}
int main()
{
    vector<vector<int>> laserCoordinates{{1, 6}, {2, 8}};
    int numRows = 8, numCols = 8;
    int currRow = 5, currCol = 3;

    vector<vector<int>> space(numRows, vector<int>(numCols, 1));

    // set area
    for (auto it : laserCoordinates)
    {
        int row = it[0] - 1;
        int col = it[1] - 1;

        // pure row ko chage kardo

        for (int i = 0; i < numCols; i++)
        {
            space[row][i] = 0;
        }

        // pure col ko change kardo
        for (int j = 0; j < numRows; j++)
        {
            space[j][col] = 0;
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << space[i][j] << " ";
        }
        cout << endl;
    }
    int longestpath = findLongestPath(currRow, currCol, space);
    cout << "longest path " << longestpath << endl;
    return 0;
}