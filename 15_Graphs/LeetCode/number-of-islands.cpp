bool isValid(int i, int j, int &n, int &m, vector<vector<char>> &grid)
{
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1')
        return true;

    return false;
}

void SolveNumIslandsDFS(int i, int j, int &n, int &m, vector<vector<char>> &grid)
{

    // mark kardo
    grid[i][j] = '0';

    // call dfs for all four direction

    if (isValid(i + 1, j, n, m, grid))
        SolveNumIslandsDFS(i + 1, j, n, m, grid);

    if (isValid(i - 1, j, n, m, grid))
        SolveNumIslandsDFS(i - 1, j, n, m, grid);
    if (isValid(i, j + 1, n, m, grid))
        SolveNumIslandsDFS(i, j + 1, n, m, grid);

    if (isValid(i, j - 1, n, m, grid))
        SolveNumIslandsDFS(i, j - 1, n, m, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    // dfs approch lagani padegi

    int n = grid.size();
    int m = grid[0].size();
    int countIslands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                countIslands++;
                SolveNumIslandsDFS(i, j, n, m, grid);
            }
        }
    }

    return countIslands;
}