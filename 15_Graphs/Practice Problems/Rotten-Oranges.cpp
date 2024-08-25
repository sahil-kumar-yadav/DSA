#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // adj list bana lo
    unordered_map<int, list<int>> adjList;
    // visited array bana lo
    unordered_map<int, bool> visited;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != j && edge[i][j] == 1)
            {
               adjList[i].push_back(j);
            }
        }
    }

    cout << "Printing adjList " << endl;
    for (auto node : adjList)
    {
        cout << node << " -> ";
        for (auto nbr : node)
        {
            cout << nbr << " , ";
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 2},
                                {0, 1, 2},
                                {2, 1, 1}};

    int ans = orangesRotting(grid);

    cout << "answer is " << ans << endl;

    return 0;
}