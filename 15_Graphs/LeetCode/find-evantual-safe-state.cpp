#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
}

void printGraph(vector<int> adjList[], int v)
{

    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto it : adjList[i])
        {
            cout << it << " , ";
        }
        cout << endl;
    }
}

bool DFScycle(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &DFSvisited, vector<bool> &isCyclePresent)
{
    visited[src] = true;
    DFSvisited[src] = true;

    for (auto v : graph[src])
    {
        if (visited[v] && DFSvisited[v])
        {
            isCyclePresent[src] = true;
            return true;
        }
        else if (!visited[v])
        {
            if(DFScycle(graph, v, visited, DFSvisited, isCyclePresent)){
                return isCyclePresent[src] = true;
            }
        }
    }
    DFSvisited[src] = false;
    return false;
}

int main()
{
    // [[1,2],[2,3],[5],[0],[5],[],[]]
    // [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    // vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> DFSvisited(n, false);
    vector<bool> isCyclePresent(n, false);

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
            DFScycle(graph, i, visited, DFSvisited, isCyclePresent);
    }

    cout << "Printing array " << endl;
    for (int i = 0;i<n;i++)
    {
        cout << i << "->" << isCyclePresent[i] << endl;
    }
    return 0;
}