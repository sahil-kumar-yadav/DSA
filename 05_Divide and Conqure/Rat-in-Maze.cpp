#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossibleMovement(vector<vector<int>> &Maze, int i, int j, vector<vector<int>> &visited)
{
    return (i >= 0 && i < Maze.size() && j >= 0 && j < Maze[0].size() &&
            visited[i][j] == 0 && Maze[i][j] == 1);
}

void findPathHelper(vector<vector<int>> &Maze, int i, int j, string path, vector<string> &ans, vector<vector<int>> &visited)
{
    if (i == Maze.size() - 1 && j == Maze[0].size() - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[i][j] = 1;

    // Down
    if (isPossibleMovement(Maze, i + 1, j, visited))
    {
        findPathHelper(Maze, i + 1, j, path + "D", ans, visited);
    }

    // Right
    if (isPossibleMovement(Maze, i, j + 1, visited))
    {
        findPathHelper(Maze, i, j + 1, path + "R", ans, visited);
    }

    // Left
    if (isPossibleMovement(Maze, i, j - 1, visited))
    {
        findPathHelper(Maze, i, j - 1, path + "L", ans, visited);
    }

    // Up
    if (isPossibleMovement(Maze, i - 1, j, visited))
    {
        findPathHelper(Maze, i - 1, j, path + "U", ans, visited);
    }

    visited[i][j] = 0; // Backtrack
}

int main()
{

    // 1 0 0 0
    // 1 1 0 1 
    // 1 1 0 0 
    // 0 1 1 1
    vector<vector<int>> Maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = 4;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;

    vector<string> ans;
    findPathHelper(Maze, 0, 0, "", ans, visited);

    cout << "Printing ans" << endl;
    for (const auto &path : ans)
    {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
