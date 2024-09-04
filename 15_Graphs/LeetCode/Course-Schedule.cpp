#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool detectCycle(unordered_map<int, vector<int>> &adjList, int src, vector<int> &visited, vector<int> &dfsVisited)
{

    visited[src] = true;
    dfsVisited[src] = true;
    for (auto v : adjList[src])
    {
        if (visited[v] && dfsVisited[v])
        {
            return true;
        }
        else if (!visited[v])
        {
            bool ans = detectCycle(adjList, v, visited, dfsVisited);
            if (ans)
                return true;
        }
    }
    dfsVisited[src] = false;

    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // adj List banate hai
    unordered_map<int, vector<int>> adjList;
    vector<int> visited(numCourses, false);
    vector<int> dfsVisited(numCourses, false);

    for (auto it : prerequisites)
    {
        int u = it[0];
        int v = it[1];
        adjList[u].push_back(v);
    }

    for (int i = 0; i < numCourses; i++)
    {
        bool ans = detectCycle(adjList, i, visited, dfsVisited);
        if (ans)
            return false;
    }

    return true;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites{{0, 1}}; // true
    // vector<vector<int>> prerequisites{{0, 1}, {1, 0}}; // false
    if (canFinish(numCourses, prerequisites))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}